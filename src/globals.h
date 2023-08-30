// globals.h
#ifndef GLOBALS_H
#define GLOBALS_H


#ifdef __cplusplus
extern "C"
{
#endif

    bool checkPIN(const char *pin);
    void toggleGPIO(const char *gpio);
    void editConfig(const char *lnbitshost, const char *deviceid, const char *devicecurrency, const char *devicekey, const char *configpin, const char *switchname1, const char *switchprice1, const char *switchtime1, const char *switchgpio1);
    void saveConfig();
    void payNow(int item);
    void hideQRCode();
    void addQRCode();
    void thankYou();
    void toManyAttempts();
    bool checkSECRETPin(const char *SECRETpin);

#ifdef __cplusplus
}
#endif

#endif