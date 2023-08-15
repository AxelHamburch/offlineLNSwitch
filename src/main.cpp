#include <Arduino.h>
#include <esp32_smartdisplay.h>
#include <../src/ui/ui.h>
#include "globals.h"
#include <LittleFS.h>
#include <ArduinoJson.h>


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
String config_configpin = String(START_PIN);

// LNURL variables
int randomPin;
int amount = 0; // Preis x100, ohne Dezimalstellen
String lnurlVendProdNames = "";
String lnurlVendProdAmounts = ""; // Preis mit zwei Dezimalstellen und Punkt als Trennzeichen
String lnurlVendProdPins = "";
String virtkey; // Der virtuelle Schlüssel
String baseURLvend;
String secretvend;
String currencyvend;
String preparedURL;
String qrData;


// defines for the config file
#define DEVICE_CFG_HOST "lnbitshost"
#define DEVICE_CFG_ID "deviceid"
#define DEVICE_CFG_KEY "devicekey"
#define DEVICE_CFG_PIN "configpin"

// create QR code object
lv_obj_t *ui_QrcodeLnurl = NULL;


void toggleGPIO(const char *gpio)
{
  Serial.print(gpio);
  if (strcmp(gpio, "Relay1") == 0)
    {
      Serial.printf(" vorher %d to %d\n", gpioOut1, statusGPIOOut1);
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

void loadConfig()
{
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
        else if (name == DEVICE_CFG_PIN)
        {
          config_configpin = String(value);
        }
      }
    }
  }
}

void editConfig(const char *lnbitshost, const char *deviceid, const char *devicekey, const char *configpin)
{

  config_lnbitshost = String(lnbitshost);
  config_deviceid = String(deviceid);
  config_devicekey = String(devicekey);
  config_configpin = String(configpin);

  saveConfig();
}

void saveConfig()
{
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
  doc[3]["name"] = DEVICE_CFG_PIN;
  doc[3]["value"] = config_configpin;

  String output = "";
  serializeJson(doc, output);
  serializeJson(doc, file);
  file.close();
}

void payNow(int item)
{
  if (item == 0)
  {
    lv_disp_load_scr(ui_ScreenPlayground);
    return;
  }
  const char *data = "LNURL1DP68GURN8GHJ7MRWVF5HGUEWV4EX26T8DE5HX6R0WF5H5MMWWSH8S7T69AMKJARGV3EXZAE0V9CXJTMKXYHKCMN4WFKZ7KZEFF656E6XD4MK5CJWGEGY2C2JGAVH5KNYY5NS2W";
  lv_qrcode_update(ui_QrcodeLnurl, data, strlen(data)); // Das QRCode Objekt mit den Daten unter Angabe der Datenlänge füllen
  lv_disp_load_scr(ui_ScreenScan);

  char buffer[20];                              // Hier verwenden wir einen Puffer, um die Zeichenfolge zu erstellen
  snprintf(buffer, sizeof(buffer), "Product: %d", item); // Wandelt den Integer in eine Zeichenfolge um
  lv_label_set_text(ui_LabelProduct, buffer);   // Setzt die Textzeile im Label

}

/*

void qrShowCode()
{
  Serial.println("qrShowCode()");
  qrData.toUpperCase();
  const char *lnurlChar = qrData.c_str();
  QRCode qrcode;
  uint8_t qrcodeData[qrcode_getBufferSize(20)];
  qrcode_initText(&qrcode, qrcodeData, 6, 0, lnurlChar);


  tft.println("PAY AND ENTER PIN FROM RECEIPT ");
}

void makeLNURL()
{
  randomPin = random(1000, 9999);
  byte nonce[8];
  for (int i = 0; i < 8; i++)
  {
    nonce[i] = random(256);
  }
  byte payload[51]; // 51 bytes is max one can get with xor-encryption

  size_t payload_len = xor_encrypt(payload, sizeof(payload), (uint8_t *)secretvend.c_str(), secretvend.length(), nonce, sizeof(nonce), randomPin, amount);
  preparedURL = baseURLvend + "?p=";
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
  to_upper(charLnurl);
  qrData = charLnurl;
  Serial.println(qrData);
}

int xor_encrypt(uint8_t *output, size_t outlen, uint8_t *key, size_t keylen, uint8_t *nonce, size_t nonce_len, uint64_t pin, uint64_t amount_in_cents)
{
  // check we have space for all the data:
  // <variant_byte><len|nonce><len|payload:{pin}{amount}><hmac>
  if (outlen < 2 + nonce_len + 1 + lenVarInt(pin) + 1 + lenVarInt(amount_in_cents) + 8)
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
  // payload, unxored first - <pin><currency byte><amount>
  int payload_len = lenVarInt(pin) + 1 + lenVarInt(amount_in_cents);
  output[cur] = (uint8_t)payload_len;
  cur++;
  uint8_t *payload = output + cur;                                 // pointer to the start of the payload
  cur += writeVarInt(pin, output + cur, outlen - cur);             // pin code
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

*/

void setup()
{
  Serial.begin(115200);

  LittleFS.begin(true);

  smartdisplay_init();
  ui_init();

  // set UI components from config
  loadConfig();

  // set config
  lv_textarea_set_text(ui_TextAreaConfigHost, config_lnbitshost.c_str());
  lv_textarea_set_text(ui_TextAreaConfigDeviceID, config_deviceid.c_str());
  lv_textarea_set_text(ui_TextAreaConfigDeviceKey, config_devicekey.c_str());
  lv_textarea_set_text(ui_TextAreaConfigPin, config_configpin.c_str());
  // set firmware version
  lv_label_set_text(ui_LabelFWVersion, String(FIRMWARE_VERSION).c_str());

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

  /*

    // baseURLvend , secretvend , currencyvend
    // https://lnbits.ereignishorizont.xyz/lnurldevice/api/v1/lnurl/walletid , secret , sat

    const JsonObject lnurlVRoot = doc[1];
    const char *lnurlvendChar = lnurlVRoot["value"];
    String lnurlvend = lnurlvendChar;
    baseURLvend = getValue(lnurlvend, ',', 0);
    secretvend = getValue(lnurlvend, ',', 1);
    currencyvend = getValue(lnurlvend, ',', 2);

    const JsonObject lnurlVTime = doc[2];
    const char *lnurlvendCharTime = lnurlVTime["value"];
    lnurlVendTime = String(lnurlvendCharTime).toInt();
 

  */
}

  void loop()
  {

    // amount = lnurlVendProdAmounts[i].toFloat() * 100;

    lv_timer_handler();

    digitalWrite(gpioOut1, statusGPIOOut1);
    digitalWrite(gpioOut2, statusGPIOOut2);
    digitalWrite(gpioLEDr, statusGPIOLEDr);
    digitalWrite(gpioLEDg, statusGPIOLEDg);
    digitalWrite(gpioLEDb, statusGPIOLEDb);
 
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
