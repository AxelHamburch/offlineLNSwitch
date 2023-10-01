// INFO
// baseURLvend , secretvend , currencyvend
// https://lnbits.ereignishorizont.xyz/lnurldevice/api/v1/lnurl/walletid , secret , sat

#include <Arduino.h>
#include <esp32_smartdisplay.h>
#include <../src/ui/ui.h>
#include "globals.h"
#include <LittleFS.h>
#include <ArduinoJson.h>
#include <Bitcoin.h>
#include <Hash.h>

// Verzögerung
#include <iostream>
#include <thread>
#include <chrono>

// general variables
int gpioOut1 = 21;
int gpioOut2 = 22;
int gpioIn1 = 35;
int gpioLEDr = 4;
int gpioLEDg = 16;
int gpioLEDb = 17;
bool statusGPIOOut1 = false;

// config variables
String config_lnbitshost = "";
String config_deviceid = "";
String config_devicekey = "";
String config_devicecurrency = "";
String config_configpin = String(START_PIN);
String config_switchname1 = "";
String config_switchprice1 = "";
String config_switchtime1 = "";
String config_switchgpio1 = String(21);
String config_statusGPIOOut1 = "0";

// LNURL, pay und QR-Code variables
int randomPin;
int amount = 0; // Preis x100, ohne Dezimalstellen
String preparedURL;
String qrData;
String selection;
String price;
bool bThankYou = false;
bool bToManyAttempts = false;
int itemtopay = 0;
bool bOneCycle = false;
time_t start_time;       // Timer übergeordnet bekannt geben
time_t current_time;     // Timer übergeordnet bekannt geben
int timer_duration = 1;  // Timerdauer in Sekunden
time_t start_time2;      // Timer übergeordnet bekannt geben
time_t current_time2;    // Timer übergeordnet bekannt geben
int timer_duration2 = 1; // Timerdauer in Sekunden
bool zeit1 = false;

// defines for the config file
#define DEVICE_CFG_HOST "lnbitshost"
#define DEVICE_CFG_ID "deviceid"
#define DEVICE_CFG_KEY "devicekey"
#define DEVICE_CFG_CUR "devicecurrency"
#define DEVICE_CFG_PIN "configpin"
#define DEVICE_SWITCH_NAME_1 "switchname1"
#define DEVICE_SWITCH_PRICE_1 "switchprice1"
#define DEVICE_SWITCH_TIME_1 "switchtime1"
#define DEVICE_SWITCH_GPIO_1 "switchgpio1"
#define DEVICE_SWITCH_STATUS_1 "switchstatus1"

;
// create QR code object
lv_obj_t *ui_QrcodeLnurl = NULL;

void toggleGPIO(const char *gpio)
{
  Serial.print(gpio);
  if (strcmp(gpio, "Relay1") == 0)
  {
    statusGPIOOut1 = !statusGPIOOut1; // Toggle the value
    Serial.printf(" toggle GPIO %d to %d\n", gpioOut1, statusGPIOOut1);
  }
}

bool checkPIN(const char *pin)
{
  if (pin == NULL)
  {
    return false;
  }
  if (String(pin).equals(config_configpin))
  {
    return true;
  }
  return false;
}

bool checkSECRETPin(const char *SECRETpin)
{
  if (SECRETpin == NULL)
  {
    return false;
  }
  if (String(SECRETpin).equals(String(randomPin)))
  {
    return true;
  }
  return false;
}

void loadConfig()
{
  Serial.println("loadConfig");
  File file = LittleFS.open("/config.json", "r");
  if (file)
  {

    //  StaticJsonDocument<2000> doc;
    DynamicJsonDocument doc(2000);
    String content = file.readString();
    DeserializationError error = deserializeJson(doc, content);
    file.close();

    if (error.code() == DeserializationError::Ok)
    {

      JsonArray arr = doc.as<JsonArray>();
      for (JsonObject obj : arr)
      {
        String name = obj["name"];
        String value = obj["value"];

        if (name == DEVICE_CFG_HOST)
        {
          config_lnbitshost = String(value);
        }
        else if (name == DEVICE_CFG_ID)
        {
          config_deviceid = String(value);
        }
        else if (name == DEVICE_CFG_KEY)
        {
          config_devicekey = String(value);
        }
        else if (name == DEVICE_CFG_CUR)
        {
          config_devicecurrency = String(value);
        }
        else if (name == DEVICE_CFG_PIN)
        {
          config_configpin = String(value);
        }

        else if (name == DEVICE_SWITCH_NAME_1)
        {
          config_switchname1 = String(value);
        }
        else if (name == DEVICE_SWITCH_PRICE_1)
        {
          config_switchprice1 = String(value);
        }
        else if (name == DEVICE_SWITCH_TIME_1)
        {
          config_switchtime1 = String(value);
        }
        else if (name == DEVICE_SWITCH_GPIO_1)
        {
          config_switchgpio1 = String(value);
        }
        else if (name == DEVICE_SWITCH_STATUS_1)
        {
          config_statusGPIOOut1 = String(value);
        }
      }
    }
  }
}

void editConfig(const char *lnbitshost, const char *deviceid, const char *devicekey, const char *devicecurrency, const char *configpin, const char *switchname1, const char *switchprice1, const char *switchtime1, const char *switchgpio1)
{
  Serial.println("editConfig");
  config_lnbitshost = String(lnbitshost);
  config_deviceid = String(deviceid);
  config_devicekey = String(devicekey);
  config_devicecurrency = String(devicecurrency);
  config_configpin = String(configpin);
  config_switchname1 = String(switchname1);
  config_switchprice1 = String(switchprice1);
  config_switchtime1 = String(switchtime1);
  config_switchgpio1 = String(switchgpio1);
  config_statusGPIOOut1 = String(statusGPIOOut1);
  saveConfig();
}

void saveConfig()
{
  Serial.println("saveConfig");
  File file = LittleFS.open("/config.json", "w");
  if (!file)
  {
    return;
  }

  // StaticJsonDocument<2000> doc;
  DynamicJsonDocument doc(2000);

  doc[0]["name"] = DEVICE_CFG_HOST;
  doc[0]["value"] = config_lnbitshost;
  doc[1]["name"] = DEVICE_CFG_ID;
  doc[1]["value"] = config_deviceid;
  doc[2]["name"] = DEVICE_CFG_KEY;
  doc[2]["value"] = config_devicekey;
  doc[3]["name"] = DEVICE_CFG_CUR;
  doc[3]["value"] = config_devicecurrency;
  doc[4]["name"] = DEVICE_CFG_PIN;
  doc[4]["value"] = config_configpin;
  doc[5]["name"] = DEVICE_SWITCH_NAME_1;
  doc[5]["value"] = config_switchname1;
  doc[6]["name"] = DEVICE_SWITCH_PRICE_1;
  doc[6]["value"] = config_switchprice1;
  doc[7]["name"] = DEVICE_SWITCH_TIME_1;
  doc[7]["value"] = config_switchtime1;
  doc[8]["name"] = DEVICE_SWITCH_GPIO_1;
  doc[8]["value"] = config_switchgpio1;
  doc[9]["name"] = DEVICE_SWITCH_STATUS_1;
  doc[9]["value"] = config_statusGPIOOut1;

  String output = "";
  serializeJson(doc, output);
  serializeJson(doc, file);
  file.close();
}

int xor_encrypt(uint8_t *output, size_t outlen, uint8_t *key, size_t keylen, uint8_t *nonce, size_t nonce_len, uint64_t rpin, uint64_t amount_in_cents)
{
  Serial.println("xor_encrypt(.)");
  // check we have space for all the data:
  // <variant_byte><len|nonce><len|payload:{rpin}{amount}><hmac>
  if (outlen < 2 + nonce_len + 1 + lenVarInt(rpin) + 1 + lenVarInt(amount_in_cents) + 8)
  {
    return 0;
  }
  int cur = 0;
  output[cur] = 1; // variant: XOR encryption
  cur++;
  // nonce_len | nonce
  output[cur] = nonce_len;
  cur++;
  memcpy(output + cur, nonce, nonce_len);
  cur += nonce_len;
  // payload, unxored first - <rpin><currency byte><amount>
  int payload_len = lenVarInt(rpin) + 1 + lenVarInt(amount_in_cents);
  output[cur] = (uint8_t)payload_len;
  cur++;
  uint8_t *payload = output + cur;                                 // pointer to the start of the payload
  cur += writeVarInt(rpin, output + cur, outlen - cur);            // rpin code
  cur += writeVarInt(amount_in_cents, output + cur, outlen - cur); // amount
  cur++;
  // xor it with round key
  uint8_t hmacresult[32];
  SHA256 h;
  h.beginHMAC(key, keylen);
  h.write((uint8_t *)"Round secret:", 13);
  h.write(nonce, nonce_len);
  h.endHMAC(hmacresult);
  for (int i = 0; i < payload_len; i++)
  {
    payload[i] = payload[i] ^ hmacresult[i];
  }
  // add hmac to authenticate
  h.beginHMAC(key, keylen);
  h.write((uint8_t *)"Data:", 5);
  h.write(output, cur);
  h.endHMAC(hmacresult);
  memcpy(output + cur, hmacresult, 8);
  cur += 8;
  // return number of bytes written to the output
  return cur;
}

void makeLNURL()
{
  Serial.println("makeLNURL()");
  randomPin = random(1000, 9999);
  Serial.println("randomPin: " + String(randomPin));
  byte nonce[8];
  for (int i = 0; i < 8; i++)
  {
    nonce[i] = random(256);
  }
  byte payload[51]; // 51 bytes is max one can get with xor-encryption

  size_t payload_len = xor_encrypt(payload, sizeof(payload), (uint8_t *)config_devicekey.c_str(), config_devicekey.length(), nonce, sizeof(nonce), randomPin, amount);
  preparedURL = "https://" + config_lnbitshost + "/lnurldevice/api/v1/lnurl/" + config_deviceid + "/?p=";
  preparedURL += toBase64(payload, payload_len, BASE64_URLSAFE | BASE64_NOPADDING);

  Serial.println("LNURL link: " + preparedURL);
  char Buf[200];
  preparedURL.toCharArray(Buf, 200);
  char *url = Buf;
  byte *data = (byte *)calloc(strlen(url) * 2, sizeof(byte));
  size_t len = 0;
  int res = convert_bits(data, &len, 5, (byte *)url, strlen(url), 8, 1);
  char *charLnurl = (char *)calloc(strlen(url) * 2, sizeof(byte));
  bech32_encode(charLnurl, "lnurl", data, len);
  qrData = charLnurl;
  Serial.println(qrData);
}

void qrShowCode()
{
  Serial.println("qrShowCode()");

  makeLNURL();

  qrData.toUpperCase();

  const char *data = qrData.c_str();
  lv_qrcode_update(ui_QrcodeLnurl, data, strlen(data)); // Das QRCode Objekt mit den Daten unter Angabe der Datenlänge füllen
  lv_disp_load_scr(ui_ScreenScan);
  lv_label_set_text(ui_LabelProduct, selection.c_str()); // Setzt die Textzeile im Label
  String totalText = "Price: " + price + " " + config_devicecurrency;
  lv_label_set_text(ui_LabelPriceAndCurrency, totalText.c_str());
  Serial.println(String("Selection: ") + String(itemtopay) + ". " + selection);
}

void payNow(int item)
{
  Serial.println("payNow()");
  itemtopay = item;
  if (config_lnbitshost != "")
  {
    if (itemtopay == 0)
    {
      selection = "Test payment";
      amount = 1;
      if (config_devicecurrency == "sat")
      {
        price = 1;
      }
      else
      {
        price = 0.01;
      }
      qrShowCode();
      return;
    }
    else if (itemtopay == 1)
    {
      selection = config_switchname1;
      if (config_devicecurrency == "sat")
      {
        amount = config_switchprice1.toFloat();
        price = config_switchprice1.toInt();
      }
      else
      {
        amount = config_switchprice1.toFloat() * 100;
        price = config_switchprice1.toFloat();
      }
      qrShowCode();
      return;
    }
  }
  else
  {
    lv_disp_load_scr(ui_ScreenConfig);
  }
}

void hideQRCode()
{
  lv_obj_add_flag(ui_QrcodeLnurl, LV_OBJ_FLAG_HIDDEN);
}

void addQRCode()
{
  lv_obj_clear_flag(ui_QrcodeLnurl, LV_OBJ_FLAG_HIDDEN);
}

void triggerTimer()
{
  Serial.println("Trigger external timer relay");
  digitalWrite(gpioOut2, true);
  delay(300);
  digitalWrite(gpioOut2, false);
}

void thankYou()
{

  if (itemtopay == 0)
  {
    lv_disp_load_scr(ui_ScreenInfo);
    lv_obj_add_flag(ui_ImageTestButtonGreen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_ImageTestButtonOrange, LV_OBJ_FLAG_HIDDEN);
  }
  else
  {
    lv_disp_load_scr(ui_ScreenStart);
    lv_obj_add_flag(ui_ImageBitcoinSwitchGreen, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_ImageBitcoinSwitchOrange, LV_OBJ_FLAG_HIDDEN);
  }
  lv_timer_handler();
  Serial.println("Delay to start");
  time(&start_time); // Aktuelle Zeit als Start Zeit setzten
  Serial.println("start_time: " + start_time);
  bThankYou = true;
}

void toManyAttempts()
{
  bToManyAttempts = true;
}

void setup()
{
  Serial.begin(115200);
  delay(2000);
  Serial.println("booting..");

  LittleFS.begin(true);

  smartdisplay_init();
  ui_init();

  // set UI components from config
  loadConfig();

  // set config to display and status
  lv_textarea_set_text(ui_TextAreaConfigHost, config_lnbitshost.c_str());
  lv_textarea_set_text(ui_TextAreaConfigDeviceID, config_deviceid.c_str());
  lv_textarea_set_text(ui_TextAreaConfigDeviceKey, config_devicekey.c_str());
  lv_textarea_set_text(ui_TextAreaConfigCurrency, config_devicecurrency.c_str());
  lv_textarea_set_text(ui_TextAreaConfigPin, config_configpin.c_str());
  lv_textarea_set_text(ui_TextAreaSwitchName1, config_switchname1.c_str());
  lv_textarea_set_text(ui_TextAreaSwitchPrice1, config_switchprice1.c_str());
  lv_textarea_set_text(ui_TextAreaSwitchTime1, config_switchtime1.c_str());
  lv_textarea_set_text(ui_TextAreaSwitchRelay1, config_switchgpio1.c_str());
  statusGPIOOut1 = (config_statusGPIOOut1 == "0") ? false : true;

  // set firmware version
  lv_label_set_text(ui_LabelFWVersion, String(FIRMWARE_VERSION).c_str());

  // set GPIOs
  pinMode(gpioOut1, OUTPUT);
  pinMode(gpioOut2, OUTPUT);
  pinMode(gpioIn1, INPUT_PULLUP);
  pinMode(gpioLEDr, OUTPUT);
  pinMode(gpioLEDg, OUTPUT);
  pinMode(gpioLEDb, OUTPUT);
  // LED GPIOs off = true
  digitalWrite(gpioLEDr, true);
  digitalWrite(gpioLEDg, true);
  digitalWrite(gpioLEDb, true);

  // initialize the QR code
  lv_color_t bg_color = lv_color_hex(0xFFFFFF);
  lv_color_t fg_color = lv_color_hex(0x000000);
  ui_QrcodeLnurl = lv_qrcode_create(ui_ScreenScan, 240, fg_color, bg_color);
  lv_obj_center(ui_QrcodeLnurl);
  lv_obj_set_pos(ui_QrcodeLnurl, 0, 0);
  lv_obj_set_style_border_width(ui_QrcodeLnurl, 0, 0);
}

void loop()
{

  lv_timer_handler();

  digitalWrite(gpioOut1, statusGPIOOut1);

  // Enter PIN 6 digits
  if (strlen(lv_textarea_get_text(ui_TextAreaPINConfig)) == 6)
  {
    // Check PIN
    if (checkPIN(lv_textarea_get_text(ui_TextAreaPINConfig)) == true)
    {
      lv_disp_load_scr(ui_ScreenConfig);
      lv_obj_add_flag(ui_PanelPINConfig, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_KeyboardPINConfig, LV_OBJ_FLAG_HIDDEN);
      lv_textarea_set_text(ui_TextAreaPINConfig, "");
    }
    else
    {
      lv_label_set_text(ui_LabelEnterConfigPin, "Wrong Config PIN");
      lv_textarea_set_text(ui_TextAreaPINConfig, "");
    }
  }

  // At least one characters and check button
  if (strlen(lv_textarea_get_text(ui_TextAreaPINConfig)) == 0)
  {
    lv_label_set_text(ui_LabelEnterConfigPin, "Enter Config PIN");
  }

  // Paid, process function
  if (bThankYou)
  {
    time(&current_time);                                      // Get current time
    if (difftime(current_time, start_time) >= timer_duration) // Query whether the time has expired
    {
      bool zeit1;
      if (zeit1 == false)
      {
        // Serial.println("Time 1 has expired");
        zeit1 = true;
      }
      if (bOneCycle)
      {
        time(&current_time2);
        if (difftime(current_time2, start_time2) >= timer_duration2) // Query whether the time has expired
        {
          Serial.println("Start Switch");
          if (itemtopay == 0)
          {
            delay(1000);
            lv_obj_add_flag(ui_ImageTestButtonGreen, LV_OBJ_FLAG_HIDDEN);    // Hide button
            lv_obj_clear_flag(ui_ImageTestButtonOrange, LV_OBJ_FLAG_HIDDEN); // Make button visible
          }
          else if (itemtopay == 1)
          {
            int gpioOut1 = config_switchgpio1.toInt();
            Serial.printf("Serve product on GPIO: %d for %d ms\n", gpioOut1, config_switchtime1.toInt());
            statusGPIOOut1 = !statusGPIOOut1; // Toggle the value
            digitalWrite(gpioOut1, statusGPIOOut1);
            delay(config_switchtime1.toInt());
            statusGPIOOut1 = !statusGPIOOut1; // Toggle the value
            lv_obj_add_flag(ui_ImageBitcoinSwitchGreen, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_ImageBitcoinSwitchOrange, LV_OBJ_FLAG_HIDDEN);
          }
          lv_label_set_text(ui_LabelPINValue, "ENTER PIN");
          Serial.println("Button orange");
          Serial.println("Payment finished");
          bThankYou = false;
          bOneCycle = false;
          zeit1 = false;
          return;
        }
        return;
      }

      // Setzt Button aktiv
      if (itemtopay == 0)
      {
        lv_obj_add_flag(ui_ImageTestButtonOrange, LV_OBJ_FLAG_HIDDEN);  // Hide button
        lv_obj_clear_flag(ui_ImageTestButtonGreen, LV_OBJ_FLAG_HIDDEN); // Make button visible
      }
      else
      {
        lv_obj_add_flag(ui_ImageBitcoinSwitchOrange, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_ImageBitcoinSwitchGreen, LV_OBJ_FLAG_HIDDEN);
      }
      // Set at the first by the bit
      bOneCycle = true;
      lv_timer_handler();
      Serial.println("Button green");
      time(&start_time2);
    }
    else
    {
      // do nothing until the time has expired
      Serial.println("Die Zeit 1 noch nicht abgelaufen = orange");
      delay(200);
    }
  }

  // To Many Attempts reset
  if (bToManyAttempts)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    lv_disp_load_scr(ui_ScreenStart);
    lv_label_set_text(ui_LabelPINValue, "ENTER PIN");
    Serial.println("To Many Attempts zurückgesetzt");
    bToManyAttempts = false;
  }
  else
  {
  }
}
