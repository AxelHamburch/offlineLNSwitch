// globals.h
#ifndef GLOBALS_H
#define GLOBALS_H

#ifdef __cplusplus
extern "C"
{
#endif

    bool checkPIN(const char *pin);
    void toggleBit();
    void editConfig(const char *lnbitshost, const char *deviceid, const char *devicekey, const char *configpin);
    void saveConfig();

#ifdef __cplusplus
}
#endif

#endif