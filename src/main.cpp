// INFO
// baseURLvend , secretvend , currencyvend
// https://lnbits.ereignishorizont.xyz/lnpos/api/v2/lnurl/walletid , secret , sat

#include <Arduino.h>
#include <esp32_smartdisplay.h>
#include <../src/ui/ui.h>
#include "globals.h"
#include <LittleFS.h>
#include <ArduinoJson.h>
#include <Bitcoin.h>
#include <Hash.h>
#include <TaskScheduler.h>
#include "mbedtls/aes.h"
#include "mbedtls/md.h"
#include "mbedtls/md5.h"

// Verzögerung
#include <iostream>
#include <thread>
#include <chrono>

// Test DeepSleep und Task Scheduler
Scheduler scheduler;
int delayDeepSleep = 300000; // ms (5 minutes)
bool buttonState = LOW;      // current state
bool lastButtonState = LOW;  // last state
int energyMode = 0;          // current mode
int lastEnergyMode = 0;      // last mode

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
String config_energymode = "0";

// LNURL, pay und QR-Code variables
int randomPin;
int backdoorPin = 0; // 0 = no backdoor pin
int amount = 0;      // Preis x100, ohne Dezimalstellen
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
#define DEVICE_ENERGY_MODE "energymode"

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
  if ((backdoorPin != 0) && (String(SECRETpin).equals(String(backdoorPin))))
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
        else if (name == DEVICE_ENERGY_MODE)
        {
          config_energymode = String(value);
        }
      }
    }
  }
}

void editConfig(const char *lnbitshost, const char *deviceid, const char *devicekey, const char *devicecurrency, const char *configpin, const char *switchname1, const char *switchprice1, const char *switchtime1, const char *switchgpio1, const char *energymode)
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
  config_energymode = String(energymode);
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
  doc[10]["name"] = DEVICE_ENERGY_MODE;
  doc[10]["value"] = config_energymode;

  String output = "";
  serializeJson(doc, output);
  serializeJson(doc, file);
  file.close();
}

// MD5 transform function (complete implementation with all 4 rounds)
void md5_transform(uint32_t state[4], const uint8_t block[64]) {
    #define MD5_F(x, y, z) (((x) & (y)) | ((~x) & (z)))
    #define MD5_G(x, y, z) (((x) & (z)) | ((y) & (~z)))
    #define MD5_H(x, y, z) ((x) ^ (y) ^ (z))
    #define MD5_I(x, y, z) ((y) ^ ((x) | (~z)))
    #define MD5_ROTLEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))
    #define MD5_FF(a, b, c, d, x, s, ac) { (a) += MD5_F((b), (c), (d)) + (x) + (ac); (a) = MD5_ROTLEFT((a), (s)); (a) += (b); }
    #define MD5_GG(a, b, c, d, x, s, ac) { (a) += MD5_G((b), (c), (d)) + (x) + (ac); (a) = MD5_ROTLEFT((a), (s)); (a) += (b); }
    #define MD5_HH(a, b, c, d, x, s, ac) { (a) += MD5_H((b), (c), (d)) + (x) + (ac); (a) = MD5_ROTLEFT((a), (s)); (a) += (b); }
    #define MD5_II(a, b, c, d, x, s, ac) { (a) += MD5_I((b), (c), (d)) + (x) + (ac); (a) = MD5_ROTLEFT((a), (s)); (a) += (b); }
    
    uint32_t a = state[0], b = state[1], c = state[2], d = state[3];
    uint32_t x[16];
    
    for (int i = 0; i < 16; i++) {
        x[i] = block[i*4] | (block[i*4+1] << 8) | (block[i*4+2] << 16) | (block[i*4+3] << 24);
    }
    
    // Round 1
    MD5_FF(a, b, c, d, x[0], 7, 0xd76aa478); MD5_FF(d, a, b, c, x[1], 12, 0xe8c7b756);
    MD5_FF(c, d, a, b, x[2], 17, 0x242070db); MD5_FF(b, c, d, a, x[3], 22, 0xc1bdceee);
    MD5_FF(a, b, c, d, x[4], 7, 0xf57c0faf); MD5_FF(d, a, b, c, x[5], 12, 0x4787c62a);
    MD5_FF(c, d, a, b, x[6], 17, 0xa8304613); MD5_FF(b, c, d, a, x[7], 22, 0xfd469501);
    MD5_FF(a, b, c, d, x[8], 7, 0x698098d8); MD5_FF(d, a, b, c, x[9], 12, 0x8b44f7af);
    MD5_FF(c, d, a, b, x[10], 17, 0xffff5bb1); MD5_FF(b, c, d, a, x[11], 22, 0x895cd7be);
    MD5_FF(a, b, c, d, x[12], 7, 0x6b901122); MD5_FF(d, a, b, c, x[13], 12, 0xfd987193);
    MD5_FF(c, d, a, b, x[14], 17, 0xa679438e); MD5_FF(b, c, d, a, x[15], 22, 0x49b40821);
    
    // Round 2
    MD5_GG(a, b, c, d, x[1], 5, 0xf61e2562); MD5_GG(d, a, b, c, x[6], 9, 0xc040b340);
    MD5_GG(c, d, a, b, x[11], 14, 0x265e5a51); MD5_GG(b, c, d, a, x[0], 20, 0xe9b6c7aa);
    MD5_GG(a, b, c, d, x[5], 5, 0xd62f105d); MD5_GG(d, a, b, c, x[10], 9, 0x02441453);
    MD5_GG(c, d, a, b, x[15], 14, 0xd8a1e681); MD5_GG(b, c, d, a, x[4], 20, 0xe7d3fbc8);
    MD5_GG(a, b, c, d, x[9], 5, 0x21e1cde6); MD5_GG(d, a, b, c, x[14], 9, 0xc33707d6);
    MD5_GG(c, d, a, b, x[3], 14, 0xf4d50d87); MD5_GG(b, c, d, a, x[8], 20, 0x455a14ed);
    MD5_GG(a, b, c, d, x[13], 5, 0xa9e3e905); MD5_GG(d, a, b, c, x[2], 9, 0xfcefa3f8);
    MD5_GG(c, d, a, b, x[7], 14, 0x676f02d9); MD5_GG(b, c, d, a, x[12], 20, 0x8d2a4c8a);
    
    // Round 3
    MD5_HH(a, b, c, d, x[5], 4, 0xfffa3942); MD5_HH(d, a, b, c, x[8], 11, 0x8771f681);
    MD5_HH(c, d, a, b, x[11], 16, 0x6d9d6122); MD5_HH(b, c, d, a, x[14], 23, 0xfde5380c);
    MD5_HH(a, b, c, d, x[1], 4, 0xa4beea44); MD5_HH(d, a, b, c, x[4], 11, 0x4bdecfa9);
    MD5_HH(c, d, a, b, x[7], 16, 0xf6bb4b60); MD5_HH(b, c, d, a, x[10], 23, 0xbebfbc70);
    MD5_HH(a, b, c, d, x[13], 4, 0x289b7ec6); MD5_HH(d, a, b, c, x[0], 11, 0xeaa127fa);
    MD5_HH(c, d, a, b, x[3], 16, 0xd4ef3085); MD5_HH(b, c, d, a, x[6], 23, 0x04881d05);
    MD5_HH(a, b, c, d, x[9], 4, 0xd9d4d039); MD5_HH(d, a, b, c, x[12], 11, 0xe6db99e5);
    MD5_HH(c, d, a, b, x[15], 16, 0x1fa27cf8); MD5_HH(b, c, d, a, x[2], 23, 0xc4ac5665);
    
    // Round 4
    MD5_II(a, b, c, d, x[0], 6, 0xf4292244); MD5_II(d, a, b, c, x[7], 10, 0x432aff97);
    MD5_II(c, d, a, b, x[14], 15, 0xab9423a7); MD5_II(b, c, d, a, x[5], 21, 0xfc93a039);
    MD5_II(a, b, c, d, x[12], 6, 0x655b59c3); MD5_II(d, a, b, c, x[3], 10, 0x8f0ccc92);
    MD5_II(c, d, a, b, x[10], 15, 0xffeff47d); MD5_II(b, c, d, a, x[1], 21, 0x85845dd1);
    MD5_II(a, b, c, d, x[8], 6, 0x6fa87e4f); MD5_II(d, a, b, c, x[15], 10, 0xfe2ce6e0);
    MD5_II(c, d, a, b, x[6], 15, 0xa3014314); MD5_II(b, c, d, a, x[13], 21, 0x4e0811a1);
    MD5_II(a, b, c, d, x[4], 6, 0xf7537e82); MD5_II(d, a, b, c, x[11], 10, 0xbd3af235);
    MD5_II(c, d, a, b, x[2], 15, 0x2ad7d2bb); MD5_II(b, c, d, a, x[9], 21, 0xeb86d391);
    
    state[0] += a; state[1] += b; state[2] += c; state[3] += d;
    
    #undef MD5_F
    #undef MD5_G
    #undef MD5_H
    #undef MD5_I
    #undef MD5_ROTLEFT
    #undef MD5_FF
    #undef MD5_GG
    #undef MD5_HH
    #undef MD5_II
}

// OpenSSL-compatible key derivation (like Python crypto-js/AES)
// Derives 32-byte key + 16-byte IV from password and salt using MD5
// Using simple MD5 implementation since ESP32 mbedtls MD5 is problematic

void md5_transform(uint32_t state[4], const uint8_t block[64]);

void simple_md5(const uint8_t *data, size_t len, uint8_t output[16]) {
    uint32_t state[4] = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476};
    uint8_t buffer[64];
    size_t i;
    uint64_t total_bits = len * 8;  // Store original length in bits
    
    // Process full 64-byte blocks
    while (len >= 64) {
        md5_transform(state, data);
        data += 64;
        len -= 64;
    }
    
    // Handle remaining bytes and padding
    memcpy(buffer, data, len);
    buffer[len++] = 0x80;
    
    if (len > 56) {
        memset(buffer + len, 0, 64 - len);
        md5_transform(state, buffer);
        len = 0;
    }
    
    memset(buffer + len, 0, 56 - len);
    // Append length in bits (little-endian)
    for (i = 0; i < 8; i++) {
        buffer[56 + i] = total_bits >> (i * 8);
    }
    md5_transform(state, buffer);
    
    // Output
    for (i = 0; i < 4; i++) {
        output[i*4] = state[i];
        output[i*4+1] = state[i] >> 8;
        output[i*4+2] = state[i] >> 16;
        output[i*4+3] = state[i] >> 24;
    }
}

void deriveKeyAndIV(const char *secret, unsigned char *salt, unsigned char *outputBuffer)
{
  size_t secretLen = strlen(secret);
  unsigned char md5Output[16];
  unsigned char data[256];
  
  // Build data: key + salt
  memcpy(data, secret, secretLen);
  memcpy(data + secretLen, salt, 8);
  size_t dataLen = secretLen + 8;
  
  size_t outputIndex = 0;
  unsigned char prevHash[16];
  bool firstRound = true;
  
  for (int round = 0; round < 3; round++)
  {
    if (firstRound) {
      simple_md5(data, dataLen, md5Output);
      firstRound = false;
    } else {
      // MD5(prevHash + data)
      unsigned char combined[256];
      memcpy(combined, prevHash, 16);
      memcpy(combined + 16, data, dataLen);
      simple_md5(combined, 16 + dataLen, md5Output);
    }
    
    memcpy(outputBuffer + outputIndex, md5Output, 16);
    memcpy(prevHash, md5Output, 16);
    outputIndex += 16;
  }
}

// AES-256-CBC encryption compatible with lnbits AESCipher
size_t aes_encrypt(uint8_t *output, size_t outlen, const char *key, int pin, int amount_cents)
{
  Serial.println("aes_encrypt()");

  // Build payload string: "PIN:AMOUNT_IN_CENTS"
  String payload = String(pin) + ":" + String(amount_cents);
  Serial.println("Payload: " + payload);

  // Generate 8-byte random salt (OpenSSL format)
  unsigned char salt[8];
  for (int i = 0; i < 8; i++)
  {
    salt[i] = random(256);
  }

  // Derive key and IV using OpenSSL EVP_BytesToKey compatible method
  unsigned char keyIV[48];
  deriveKeyAndIV(key, salt, keyIV);

  unsigned char derived_key[32];
  unsigned char iv[16];
  memcpy(derived_key, keyIV, 32);      // First 32 bytes = key
  memcpy(iv, keyIV + 32, 16);          // Last 16 bytes = IV

  // PKCS7 padding
  size_t payloadLen = payload.length();
  int padding = 16 - (payloadLen % 16);
  size_t paddedLen = payloadLen + padding;

  // Check output buffer size: "Salted__" (8) + salt (8) + ciphertext
  if (outlen < 16 + paddedLen)
  {
    Serial.println("Buffer too small!");
    return 0;
  }

  // Create padded plaintext
  unsigned char *paddedPayload = (unsigned char *)malloc(paddedLen);
  memcpy(paddedPayload, payload.c_str(), payloadLen);
  for (int i = 0; i < padding; i++)
  {
    paddedPayload[payloadLen + i] = (unsigned char)padding;
  }

  // Encrypt with AES-256-CBC
  mbedtls_aes_context aes;
  mbedtls_aes_init(&aes);
  mbedtls_aes_setkey_enc(&aes, derived_key, 256);
  
  unsigned char iv_copy[16];
  memcpy(iv_copy, iv, 16);
  mbedtls_aes_crypt_cbc(&aes, MBEDTLS_AES_ENCRYPT, paddedLen, iv_copy, paddedPayload, output + 16);
  mbedtls_aes_free(&aes);

  // Build output: "Salted__" + salt + ciphertext
  memcpy(output, "Salted__", 8);
  memcpy(output + 8, salt, 8);

  free(paddedPayload);

  size_t totalLen = 16 + paddedLen;
  Serial.println("Encrypted length: " + String(totalLen));
  return totalLen;
}

void makeLNURL()
{
  Serial.println("makeLNURL()");
  randomPin = random(1000, 9999);
  Serial.println("randomPin: " + String(randomPin));

  byte payload[128]; // AES encrypted payload needs more space

  size_t payload_len = aes_encrypt(payload, sizeof(payload), config_devicekey.c_str(), randomPin, amount);
  
  String base64_payload = toBase64(payload, payload_len, BASE64_URLSAFE);
  Serial.println("Base64 payload length: " + String(base64_payload.length()));
  Serial.println("Base64 payload: " + base64_payload);
  
  preparedURL = "https://" + config_lnbitshost + "/lnpos/api/v2/lnurl/" + config_deviceid + "?p=";
  preparedURL += base64_payload;

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

void startDeepSleep()
{
  Serial.println("Going to sleep...");
  Serial.flush();
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_35, HIGH);
  esp_deep_sleep_start();
}

// Task for start a delayed deep sleep
Task t1(delayDeepSleep, TASK_FOREVER, &startDeepSleep);

void triggerTimer()
{
  if (energyMode == 1)
  {
    Serial.println("Change pages: Reset task for deep sleep to " + String(delayDeepSleep) + " ms.");
    t1.setInterval(delayDeepSleep);
  }
  else if (energyMode == 2)
  {
    Serial.println("Change pages: Trigger output GPIO 22 for time relay");
    digitalWrite(gpioOut2, true);
    delay(300);
    digitalWrite(gpioOut2, false);
  }
  return;
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

  // Task scheduler
  scheduler.addTask(t1);
  if (config_energymode.toInt() == 1)
  {
    Serial.println("Energy Mode: 1 => Enable deep sleep task");
    t1.enableDelayed(); // activate deep sleep task
  }
  else
  {
    Serial.println("Energy Mode: 0 or 2 => Disable deep sleep task");
    t1.disable(); // disable deep sleep task
  }

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
  lv_textarea_set_text(ui_TextAreaEnergyMode, config_energymode.c_str());

  // set firmware version
  lv_label_set_text(ui_LabelFWVersion, String(FIRMWARE_VERSION).c_str());

  // set GPIOs
  pinMode(gpioOut1, OUTPUT);
  pinMode(gpioOut2, OUTPUT);
  pinMode(gpioIn1, INPUT);
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

  scheduler.execute();

  digitalWrite(gpioOut1, statusGPIOOut1);

  // Check Energy Mode
  energyMode = config_energymode.toInt();
  if (energyMode != lastEnergyMode != 0) // change of energy mode
  {
    Serial.println("Energy mode: " + String(energyMode));
  }
  lastEnergyMode = energyMode; // store energy mode

  // Edge detection of external button for deep sleep task
  // External pull down resistor (10KOhm) required, if GPIO 35 ist wired
  buttonState = digitalRead(gpioIn1);
  if ((energyMode == 1) && (buttonState == HIGH && lastButtonState == LOW) || (buttonState == LOW && lastButtonState == HIGH)) // rising edge OR falling edge
  {
    if (digitalRead(gpioIn1) == LOW)
    {
      Serial.println("Button edge detected - acivate task deep sleep");
      t1.enableDelayed(); // activate deep sleep task
    }
    else
    {
      Serial.println("Button edge detected - disable task deep sleep");
      t1.disable(); // disable deep sleep task
    }
  }
  lastButtonState = buttonState; // store state

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
}
