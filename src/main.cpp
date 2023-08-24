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
int gpioLEDr = 4;
int gpioLEDg = 16;
int gpioLEDb = 17;
bool statusGPIOOut1 = false;
bool statusGPIOOut2 = false;
bool statusGPIOLEDr = true; // Ground switching
bool statusGPIOLEDg = true; // Ground switching
bool statusGPIOLEDb = true; // Ground switching

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
String config_switchname2 = "";
String config_switchprice2 = "";
String config_switchtime2 = "";
String config_switchgpio2 = String(22);

// LNURL, pay und QR-Code variables
int randomPin;
int amount = 0; // Preis x100, ohne Dezimalstellen
int factor = 0;
//String lnurlVendProdNames = "";
//String lnurlVendProdAmounts = ""; // Preis mit zwei Dezimalstellen und Punkt als Trennzeichen
//String lnurlVendProdPins = "";
//String baseURLvend;
//String secretvend;
//String currencyvend;
String preparedURL;
String qrData;
String selection;
bool bThankYou = false;
bool bToManyAttempts = false;
int itemtopay = 0;



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
/*
#define DEVICE_SWITCH_NAME_2 "switchname2"
#define DEVICE_SWITCH_PRICE_2 "switchprice2"
#define DEVICE_SWITCH_TIME_2 "switchtime2"
#define DEVICE_SWITCH_GPIO_2 "switchgpio2"
*/
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
  else if (strcmp(gpio, "Relay2") == 0)
    {
    statusGPIOOut2 = !statusGPIOOut2; // Toggle the value
    Serial.printf(" toggle GPIO %d to %d\n", gpioOut2, statusGPIOOut2);
    }
  else if (strcmp(gpio, "LEDred") == 0)
    {
    statusGPIOLEDr = !statusGPIOLEDr; // Toggle the value
    Serial.printf(" toggle GPIO %d to %d\n", gpioLEDr, statusGPIOLEDr);
    }
  else if (strcmp(gpio, "LEDgreen") == 0)
    {
    statusGPIOLEDg = !statusGPIOLEDg; // Toggle the value
    Serial.printf(" toggle GPIO %d to %d\n", gpioLEDg, statusGPIOLEDg);
    }
  else if (strcmp(gpio, "LEDblue") == 0)
    {
    statusGPIOLEDb = !statusGPIOLEDb; // Toggle the value
    Serial.printf(" toggle GPIO %d to %d\n", gpioLEDb, statusGPIOLEDb);
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
        /*
        else if (name == DEVICE_SWITCH_NAME_2)
        {
          config_switchname2 = String(value);
        }
        else if (name == DEVICE_SWITCH_PRICE_2)
        {
          config_switchprice2 = String(value);
        }
        else if (name == DEVICE_SWITCH_TIME_2)
        {
          config_switchtime2 = String(value);
        }
        else if (name == DEVICE_SWITCH_GPIO_2)
        {
          config_switchgpio2 = String(value);
        }
        */
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
  /*
  config_switchname2 = String(switchname2);
  config_switchprice2 = String(switchprice2);
  config_switchtime2 = String(switchtime2);
  config_switchgpio2 = String(switchgpio2);
  */
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
  /*
  doc[9]["name"] = DEVICE_SWITCH_NAME_2;
  doc[9]["value"] = config_switchname2;
  doc[10]["name"] = DEVICE_SWITCH_PRICE_2;
  doc[10]["value"] = config_switchprice2;
  doc[11]["name"] = DEVICE_SWITCH_TIME_2;
  doc[11]["value"] = config_switchtime2;
  doc[12]["name"] = DEVICE_SWITCH_GPIO_2;
  doc[12]["value"] = config_switchgpio2;
  */

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
  cur += writeVarInt(rpin, output + cur, outlen - cur);             // rpin code
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
  lv_label_set_text(ui_LabelProduct, selection.c_str());   // Setzt die Textzeile im Label
  String totalText = "Price: " + config_switchprice1 + " " + config_devicecurrency;
  lv_label_set_text(ui_LabelPriceAndCurrency, totalText.c_str()); 
  Serial.println(String("Selection: ") + String(itemtopay) + ". " + selection);

}

void payNow(int item)
{
  Serial.println("payNow()");
  itemtopay = item;

  if (config_devicecurrency == "sat") {
    factor = 1;
  } else {
    factor = 100;
  }

  if (itemtopay == 1)
  {
    selection = config_switchname1;
    amount = config_switchprice1.toFloat() * factor;
    qrShowCode();
    return;
  }
  else if (itemtopay == 2)
  {
    selection = config_switchname2;
    amount = config_switchprice2.toFloat() *factor;
    qrShowCode();
    return;
  }

}

void hideQRCode()
{
  lv_obj_add_flag(ui_QrcodeLnurl,LV_OBJ_FLAG_HIDDEN);
}

void addQRCode()
{
  lv_obj_clear_flag(ui_QrcodeLnurl,LV_OBJ_FLAG_HIDDEN);
}

void thankYou()
{
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

  // set config to display
  lv_textarea_set_text(ui_TextAreaConfigHost, config_lnbitshost.c_str());
  lv_textarea_set_text(ui_TextAreaConfigDeviceID, config_deviceid.c_str());
  lv_textarea_set_text(ui_TextAreaConfigDeviceKey, config_devicekey.c_str());
  lv_textarea_set_text(ui_TextAreaConfigCurrency, config_devicecurrency.c_str());
  lv_textarea_set_text(ui_TextAreaConfigPin, config_configpin.c_str());
  lv_textarea_set_text(ui_TextAreaSwitchName1, config_switchname1.c_str());
  lv_textarea_set_text(ui_TextAreaSwitchPrice1, config_switchprice1.c_str());
  lv_textarea_set_text(ui_TextAreaSwitchTime1, config_switchtime1.c_str());
  lv_textarea_set_text(ui_TextAreaSwitchRelay1, config_switchgpio1.c_str());
  /*
  lv_textarea_set_text(ui_TextAreaSwitchName2, config_switchname1.c_str());
  lv_textarea_set_text(ui_TextAreaSwitchTime2, config_switchprice1.c_str());
  lv_textarea_set_text(ui_TextAreaSwitchTime2, config_switchtime1.c_str());
  lv_textarea_set_text(ui_TextAreaSwitchRelay2, config_switchgpio1.c_str());
  */

  // set firmware version
  lv_label_set_text(ui_LabelFWVersion, String(FIRMWARE_VERSION).c_str());

  // set GPIOs
  pinMode(gpioOut1, OUTPUT);
  pinMode(gpioOut2, OUTPUT);
  pinMode(gpioLEDr, OUTPUT);
  pinMode(gpioLEDg, OUTPUT);
  pinMode(gpioLEDb, OUTPUT);

  // initialize the QR code
  lv_color_t bg_color = lv_color_hex(0xFFFFFF);
  lv_color_t fg_color = lv_color_hex(0x000000);
  ui_QrcodeLnurl = lv_qrcode_create(ui_ScreenScan, 240, fg_color, bg_color);
  lv_obj_center(ui_QrcodeLnurl);
  lv_obj_set_pos(ui_QrcodeLnurl, 0, 0);
  lv_obj_set_style_border_width(ui_QrcodeLnurl, 0, 0);
  //  lv_obj_add_flag(ui_QrcodeLnurl, LV_OBJ_FLAG_HIDDEN);

  

    // baseURLvend , secretvend , currencyvend
    // https://lnbits.ereignishorizont.xyz/lnurldevice/api/v1/lnurl/walletid , secret , sat


    //const JsonObject lnurlVTime = doc[2];
    //const char *lnurlvendCharTime = lnurlVTime["value"];
    //lnurlVendTime = String(lnurlvendCharTime).toInt();
 }

  void loop()
  {

    lv_timer_handler();

    digitalWrite(gpioOut1, statusGPIOOut1);
    digitalWrite(gpioOut2, statusGPIOOut2);
    digitalWrite(gpioLEDr, statusGPIOLEDr);
    digitalWrite(gpioLEDg, statusGPIOLEDg);
    digitalWrite(gpioLEDb, statusGPIOLEDb);




  // Thank You zurücksetzten
  if (bThankYou) {
    if (itemtopay == 1) {
      int gpioOut1 = config_switchgpio1.toInt(); 
      Serial.printf("Serve product on GPIO: %d for %d ms\n", gpioOut1, config_switchtime1.toInt());
      digitalWrite(gpioOut1, true);
      delay(config_switchtime1.toInt());
      digitalWrite(gpioOut1, false);

      //int delayTime = config_switchtime1.toInt(); // Annahme: config_switchtime1 ist eine Integer-Variable oder ähnliches
      //std::this_thread::sleep_for(std::chrono::milliseconds(delayTime));
      //std::cout << "Delay completed" << std::endl;
      

      //lv_timer_t *timer = lv_timer_create(backToAbout, 3000, NULL);
      //lv_obj_add_flag(ui_BarBierProgress,LV_OBJ_FLAG_HIDDEN);
      //lv_timer_set_repeat_count(timer,1);
    }
    if (itemtopay == 2) {
      int gpioOut2 = config_switchgpio2.toInt(); 
      Serial.printf("Serve product on GPIO: %d for %d ms\n", gpioOut2, config_switchtime2.toInt());
      digitalWrite(gpioOut2, true);
      delay(config_switchtime2.toInt());
      digitalWrite(gpioOut2, false);
    } else {
    }
    //std::this_thread::sleep_for(std::chrono::milliseconds(2000)); 
    lv_disp_load_scr(ui_ScreenStart);
    lv_label_set_text(ui_LabelPINValue, "ENTER PIN");
    Serial.println("Thank You zurückgesetzt");
    bThankYou = false;
  } else {
  }

  // To Many Attempts zurücksetzten
  if (bToManyAttempts) {
    std::this_thread::sleep_for(std::chrono::milliseconds(3000)); 
    lv_disp_load_scr(ui_ScreenStart);
    lv_label_set_text(ui_LabelPINValue, "ENTER PIN");
    Serial.println("To Many Attempts zurückgesetzt");
    bToManyAttempts = false;
  } else {
  }
/*

  if ( bDisplayQRCode ) {
    lv_obj_clear_flag(ui_QrcodeLnurl,LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_obj_add_flag(ui_QrcodeLnurl,LV_OBJ_FLAG_HIDDEN);
    //_ui_flag_modify(ui_QrcodeLnurl, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
  }
*/
 
  /*
  if ((digitalRead(gpio21) == HIGH) != merker)
  {
    Serial.println("statusButton: " + String(statusButton));
    merker = (digitalRead(21) == gpio21);
  }
  */
  /*
    auto r = (byte)(millis() / 75);
    auto g = (byte)(millis() / 10);
    auto b = (byte)(millis() / 150);

    smartdisplay_set_led_color(lv_color32_t({.ch = {.blue = b, .green = g, .red = r}}));

  auto r = (byte)0;   // Roter Farbkanal auf 0 setzen
  auto g = (byte)0; // Grüner Farbkanal auf 0 setzen
  auto b = (byte)0;   // Blauer Farbkanal auf 255 (volle Intensität) setzen

  smartdisplay_set_led_color(lv_color32_t({.ch = {.blue = b, .green = g, .red = r}}));
  */
    }
