#include <Arduino.h>
#include <esp32_smartdisplay.h>
#include <../src/ui/ui.h>
#include "globals.h"
#include <LittleFS.h>
#include <ArduinoJson.h>


// general variables
bool statusButton = false;
bool merker = false;

// config variables
String config_lnbitshost = "";
String config_deviceid = "";
String config_devicekey = "";
String config_configpin = String(START_PIN);

// defines for the config file
#define DEVICE_CFG_HOST "lnbitshost"
#define DEVICE_CFG_ID "deviceid"
#define DEVICE_CFG_KEY "devicekey"
#define DEVICE_CFG_PIN "configpin"


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

void toggleBit()
{
  if (statusButton == false)
  {
    statusButton = true;
  }
  else
  {
    statusButton = false;
  }
}

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

  pinMode (21, OUTPUT); // 21
  digitalWrite(21, LOW);
  Serial.println("21 LOW");
  
}

void loop()
{
  lv_timer_handler();
 
  digitalWrite(21, statusButton);
  if ((digitalRead(21) == HIGH) != merker)
  {
    Serial.println("statusButton: " + String(statusButton));
    merker = (digitalRead(21) == HIGH);
  }
      /*
        auto r = (byte)(millis() / 75);
        auto g = (byte)(millis() / 10);
        auto b = (byte)(millis() / 150);

        smartdisplay_set_led_color(lv_color32_t({.ch = {.blue = b, .green = g, .red = r}}));
      */
      auto r = (byte)0;   // Roter Farbkanal auf 0 setzen
      auto g = (byte)0; // Grüner Farbkanal auf 0 setzen
      auto b = (byte)0;   // Blauer Farbkanal auf 255 (volle Intensität) setzen

      smartdisplay_set_led_color(lv_color32_t({.ch = {.blue = b, .green = g, .red = r}}));
    }
