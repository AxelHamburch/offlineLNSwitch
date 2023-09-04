// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: TouchDisplaySmall

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_ScreenStart
void ui_ScreenStart_screen_init(void);
lv_obj_t *ui_ScreenStart;
lv_obj_t *ui_TopScreenStart;
lv_obj_t *ui_LabelTopScreenStart;
void ui_event_ImageBitcoinSwitchOrange( lv_event_t * e);
lv_obj_t *ui_ImageBitcoinSwitchOrange;
lv_obj_t *ui_ImageBitcoinSwitchGreen;
void ui_event_ImageSettings( lv_event_t * e);
lv_obj_t *ui_ImageSettings;
void ui_event_ImageInfo( lv_event_t * e);
lv_obj_t *ui_ImageInfo;
lv_obj_t *ui_PanelPINConfig;
lv_obj_t *ui_LabelEnterConfigPin;
lv_obj_t *ui_TextAreaPINConfig;
void ui_event_ButtonCancelPIN( lv_event_t * e);
lv_obj_t *ui_ButtonCancelPIN;
lv_obj_t *ui_LabelCancelPIN;
lv_obj_t *ui_KeyboardPINConfig;


// SCREEN: ui_ScreenPIN
void ui_ScreenPIN_screen_init(void);
lv_obj_t *ui_ScreenPIN;
lv_obj_t *ui_TopScreenPIN;
lv_obj_t *ui_LabelTopScreenPIN;
lv_obj_t *ui_LabelPINValue;
void ui_event_ButtonPin1( lv_event_t * e);
lv_obj_t *ui_ButtonPin1;
lv_obj_t *ui_LabelButtonPin1;
void ui_event_ButtonPin2( lv_event_t * e);
lv_obj_t *ui_ButtonPin2;
lv_obj_t *ui_LabelButtonPin2;
void ui_event_ButtonPin3( lv_event_t * e);
lv_obj_t *ui_ButtonPin3;
lv_obj_t *ui_LabelButtonPin3;
void ui_event_ButtonPin4( lv_event_t * e);
lv_obj_t *ui_ButtonPin4;
lv_obj_t *ui_LabelButtonPin4;
void ui_event_ButtonPin5( lv_event_t * e);
lv_obj_t *ui_ButtonPin5;
lv_obj_t *ui_LabelButtonPin5;
void ui_event_ButtonPin6( lv_event_t * e);
lv_obj_t *ui_ButtonPin6;
lv_obj_t *ui_LabelButtonPin6;
void ui_event_ButtonPin7( lv_event_t * e);
lv_obj_t *ui_ButtonPin7;
lv_obj_t *ui_LabelButtonPin7;
void ui_event_ButtonPin8( lv_event_t * e);
lv_obj_t *ui_ButtonPin8;
lv_obj_t *ui_LabelButtonPin8;
void ui_event_ButtonPin9( lv_event_t * e);
lv_obj_t *ui_ButtonPin9;
lv_obj_t *ui_LabelButtonPin9;
void ui_event_ButtonPin10( lv_event_t * e);
lv_obj_t *ui_ButtonPin10;
lv_obj_t *ui_LabelButtonPin10;
void ui_event_ButtonPin11( lv_event_t * e);
lv_obj_t *ui_ButtonPin11;
lv_obj_t *ui_LabelButtonPin11;
void ui_event_ButtonPin12( lv_event_t * e);
lv_obj_t *ui_ButtonPin12;
lv_obj_t *ui_LabelButtonPin12;


// SCREEN: ui_ScreenConfig
void ui_ScreenConfig_screen_init(void);
lv_obj_t *ui_ScreenConfig;
lv_obj_t *ui_TopScreenConfig;
lv_obj_t *ui_LabelTopScreenConfig;
lv_obj_t *ui_LabelGeneralSetup;
void ui_event_TextAreaConfigHost( lv_event_t * e);
lv_obj_t *ui_TextAreaConfigHost;
lv_obj_t *ui_LabelConfigHost;
void ui_event_TextAreaConfigDeviceID( lv_event_t * e);
lv_obj_t *ui_TextAreaConfigDeviceID;
lv_obj_t *ui_LabelConfigDeviceID;
void ui_event_TextAreaConfigDeviceKey( lv_event_t * e);
lv_obj_t *ui_TextAreaConfigDeviceKey;
lv_obj_t *ui_LabelConfigDeviceKey;
void ui_event_TextAreaConfigCurrency( lv_event_t * e);
lv_obj_t *ui_TextAreaConfigCurrency;
lv_obj_t *ui_LabelConfigCurrency;
void ui_event_TextAreaConfigPin( lv_event_t * e);
lv_obj_t *ui_TextAreaConfigPin;
lv_obj_t *ui_LabelConfigPin;
void ui_event_ButtonConfigSave( lv_event_t * e);
lv_obj_t *ui_ButtonConfigSave;
lv_obj_t *ui_LabelButtonConfigSave;
void ui_event_ButtonGoSwitches( lv_event_t * e);
lv_obj_t *ui_ButtonGoSwitches;
lv_obj_t *ui_LabelButtonGoSwitches;
void ui_event_ButtonGoWelcome( lv_event_t * e);
lv_obj_t *ui_ButtonGoWelcome;
lv_obj_t *ui_LabelButtonGoWelcome;
lv_obj_t *ui_LabelConfigMoreOptions;
void ui_event_KeyboardText( lv_event_t * e);
lv_obj_t *ui_KeyboardText;
void ui_event_KeyboardNumber( lv_event_t * e);
lv_obj_t *ui_KeyboardNumber;


// SCREEN: ui_ScreenSwitch1
void ui_ScreenSwitch1_screen_init(void);
lv_obj_t *ui_ScreenSwitch1;
lv_obj_t *ui_TopScreenConfigSwitch1;
lv_obj_t *ui_LabelTopScreenSwitch1;
lv_obj_t *ui_LabelSwitch1;
lv_obj_t *ui_LabelTestFunction1;
void ui_event_TextAreaSwitchName1( lv_event_t * e);
lv_obj_t *ui_TextAreaSwitchName1;
lv_obj_t *ui_LabelSwitchName1;
void ui_event_TextAreaSwitchPrice1( lv_event_t * e);
lv_obj_t *ui_TextAreaSwitchPrice1;
lv_obj_t *ui_LabelSwitchPrice1;
void ui_event_TextAreaSwitchTime1( lv_event_t * e);
lv_obj_t *ui_TextAreaSwitchTime1;
lv_obj_t *ui_LabelSwitchTime1;
lv_obj_t *ui_LabelSwitchRelay1;
void ui_event_TextAreaSwitchRelay1( lv_event_t * e);
lv_obj_t *ui_TextAreaSwitchRelay1;
void ui_event_ButtonGoConfig( lv_event_t * e);
lv_obj_t *ui_ButtonGoConfig;
lv_obj_t *ui_LabelButtonGoConfig;
void ui_event_SwitchToggle1( lv_event_t * e);
lv_obj_t *ui_SwitchToggle1;
void ui_event_KeyboardSwitchText1( lv_event_t * e);
lv_obj_t *ui_KeyboardSwitchText1;
void ui_event_KeyboardSwitchNumber1( lv_event_t * e);
lv_obj_t *ui_KeyboardSwitchNumber1;


// SCREEN: ui_ScreenWelcome
void ui_ScreenWelcome_screen_init(void);
lv_obj_t *ui_ScreenWelcome;
lv_obj_t *ui_TopScreenConfigWelcome;
lv_obj_t *ui_LabelTopScreenWelcome;
lv_obj_t *ui_LabelWelcome;
void ui_event_TextAreaWelcome1( lv_event_t * e);
lv_obj_t *ui_TextAreaWelcome1;
void ui_event_TextAreaWelcome2( lv_event_t * e);
lv_obj_t *ui_TextAreaWelcome2;
lv_obj_t *ui_LabelWelcome1;
lv_obj_t *ui_LabelWelcome2;
lv_obj_t *ui_LabelWelcomeInfo;
void ui_event_ButtonGoConfigFromWelcome( lv_event_t * e);
lv_obj_t *ui_ButtonGoConfigFromWelcome;
lv_obj_t *ui_LabelButtonGoConfig1;
void ui_event_KeyboardWelcome( lv_event_t * e);
lv_obj_t *ui_KeyboardWelcome;


// SCREEN: ui_ScreenScan
void ui_ScreenScan_screen_init(void);
lv_obj_t *ui_ScreenScan;
lv_obj_t *ui_TopScreenScan;
lv_obj_t *ui_LabelTopScreenScan;
void ui_event_ButtonGotoScreenPin2( lv_event_t * e);
lv_obj_t *ui_ButtonGotoScreenPin2;
lv_obj_t *ui_LabelButtonGotoScreenPin2;
void ui_event_ButtonCallPanelCancel( lv_event_t * e);
lv_obj_t *ui_ButtonCallPanelCancel;
lv_obj_t *ui_LabelButtonGotoScreenPin3;
lv_obj_t *ui_ImageScanQRCodeBorder;
lv_obj_t *ui_LabelProduct;
lv_obj_t *ui_LabelPriceAndCurrency;
lv_obj_t *ui_Label2;
lv_obj_t *ui_PanelCancel;
lv_obj_t *ui_LabelPanelCancel;
void ui_event_ButtonYES( lv_event_t * e);
lv_obj_t *ui_ButtonYES;
lv_obj_t *ui_LabelYES;
void ui_event_ButtonNO( lv_event_t * e);
lv_obj_t *ui_ButtonNO;
lv_obj_t *ui_LabelNO;


// SCREEN: ui_ScreenInfo
void ui_ScreenInfo_screen_init(void);
lv_obj_t *ui_ScreenInfo;
lv_obj_t *ui_TopScreenPlay1;
lv_obj_t *ui_LabelTopScreenPlayground1;
void ui_event_ButtonGotoScreenPlay2( lv_event_t * e);
lv_obj_t *ui_ButtonGotoScreenPlay2;
lv_obj_t *ui_LabelButtonGotoScreenPlay2;
lv_obj_t *ui_LabelInfo;
lv_obj_t *ui_LabelTestPayment;
lv_obj_t *ui_LabelMoreInfos;
lv_obj_t *ui_ImageTestButtonGreen;
void ui_event_ImageTestButtonOrange( lv_event_t * e);
lv_obj_t *ui_ImageTestButtonOrange;
lv_obj_t *ui_Image1;
lv_obj_t *ui_LabelInfoFirmware;
lv_obj_t *ui_LabelFWVersion;
lv_obj_t *ui____initial_actions0;
const lv_img_dsc_t *ui_imgset_ereignishorizont_xyz_[1] = {&ui_img_ereignishorizont_xyz_128_png};
const lv_img_dsc_t *ui_imgset_1355287214[1] = {&ui_img_166440904};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_ImageBitcoinSwitchOrange( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonPayNow1Click( e );
}
}
void ui_event_ImageSettings( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_PanelPINConfig, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
      _ui_flag_modify( ui_KeyboardPINConfig, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
}
}
void ui_event_ImageInfo( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_ScreenInfo, LV_SCR_LOAD_ANIM_NONE, 500, 0, &ui_ScreenInfo_screen_init);
}
}
void ui_event_ButtonCancelPIN( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_KeyboardPINConfig, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
      _ui_flag_modify( ui_PanelPINConfig, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_ButtonPin1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonPinOneClicked( e );
}
}
void ui_event_ButtonPin2( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonPinTwoClicked( e );
}
}
void ui_event_ButtonPin3( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonPinThreeClicked( e );
}
}
void ui_event_ButtonPin4( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonPinFourClicked( e );
}
}
void ui_event_ButtonPin5( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonPinFiveClicked( e );
}
}
void ui_event_ButtonPin6( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonPinSixClicked( e );
}
}
void ui_event_ButtonPin7( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonPinSevenClicked( e );
}
}
void ui_event_ButtonPin8( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonPinEightClicked( e );
}
}
void ui_event_ButtonPin9( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonPinNineClicked( e );
}
}
void ui_event_ButtonPin10( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonPinZeroClicked( e );
}
}
void ui_event_ButtonPin11( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonPinCancelClicked( e );
}
}
void ui_event_ButtonPin12( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonPinOKClicked( e );
}
}
void ui_event_TextAreaConfigHost( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_KeyboardText, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
      _ui_keyboard_set_target(ui_KeyboardText,  ui_TextAreaConfigHost);
      _ui_flag_modify( ui_KeyboardNumber, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_TextAreaConfigDeviceID( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_KeyboardText, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
      _ui_keyboard_set_target(ui_KeyboardText,  ui_TextAreaConfigDeviceID);
      _ui_flag_modify( ui_KeyboardNumber, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_TextAreaConfigDeviceKey( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_KeyboardText, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
      _ui_keyboard_set_target(ui_KeyboardText,  ui_TextAreaConfigDeviceKey);
      _ui_flag_modify( ui_KeyboardNumber, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_TextAreaConfigCurrency( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_KeyboardText, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
      _ui_keyboard_set_target(ui_KeyboardText,  ui_TextAreaConfigCurrency);
      _ui_flag_modify( ui_KeyboardNumber, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_TextAreaConfigPin( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_KeyboardNumber, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
      _ui_keyboard_set_target(ui_KeyboardNumber,  ui_TextAreaConfigPin);
      _ui_flag_modify( ui_KeyboardText, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_ButtonConfigSave( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonConfigSaveAndExitClicked( e );
      _ui_flag_modify( ui_KeyboardText, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
      _ui_flag_modify( ui_KeyboardNumber, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
      _ui_screen_change( &ui_ScreenStart, LV_SCR_LOAD_ANIM_NONE, 1, 100, &ui_ScreenStart_screen_init);
}
}
void ui_event_ButtonGoSwitches( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_KeyboardText, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
      _ui_flag_modify( ui_KeyboardNumber, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
      _ui_screen_change( &ui_ScreenSwitch1, LV_SCR_LOAD_ANIM_NONE, 5, 0, &ui_ScreenSwitch1_screen_init);
}
}
void ui_event_ButtonGoWelcome( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_KeyboardText, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
      _ui_flag_modify( ui_KeyboardNumber, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
      _ui_screen_change( &ui_ScreenWelcome, LV_SCR_LOAD_ANIM_NONE, 500, 0, &ui_ScreenWelcome_screen_init);
}
}
void ui_event_KeyboardText( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_READY) {
      _ui_flag_modify( ui_KeyboardText, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_KeyboardNumber( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_READY) {
      _ui_flag_modify( ui_KeyboardNumber, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_TextAreaSwitchName1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_KeyboardSwitchNumber1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
      _ui_flag_modify( ui_KeyboardSwitchText1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
      _ui_keyboard_set_target(ui_KeyboardSwitchText1,  ui_TextAreaSwitchName1);
}
}
void ui_event_TextAreaSwitchPrice1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_keyboard_set_target(ui_KeyboardSwitchNumber1,  ui_TextAreaSwitchPrice1);
      _ui_flag_modify( ui_KeyboardSwitchNumber1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
      _ui_flag_modify( ui_KeyboardSwitchText1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_TextAreaSwitchTime1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_KeyboardSwitchNumber1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
      _ui_keyboard_set_target(ui_KeyboardSwitchNumber1,  ui_TextAreaSwitchTime1);
      _ui_flag_modify( ui_KeyboardSwitchText1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_TextAreaSwitchRelay1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_KeyboardSwitchText1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
      _ui_flag_modify( ui_KeyboardSwitchNumber1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
      _ui_keyboard_set_target(ui_KeyboardSwitchNumber1,  ui_TextAreaSwitchRelay1);
}
}
void ui_event_ButtonGoConfig( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_ScreenConfig, LV_SCR_LOAD_ANIM_NONE, 1, 100, &ui_ScreenConfig_screen_init);
      _ui_flag_modify( ui_KeyboardSwitchText1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
      _ui_flag_modify( ui_KeyboardSwitchNumber1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_SwitchToggle1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonTestRelay1Clicked( e );
}
}
void ui_event_KeyboardSwitchText1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_READY) {
      _ui_flag_modify( ui_KeyboardSwitchText1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_KeyboardSwitchNumber1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_READY) {
      _ui_flag_modify( ui_KeyboardSwitchNumber1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_TextAreaWelcome1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_KeyboardWelcome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
      _ui_keyboard_set_target(ui_KeyboardWelcome,  ui_TextAreaWelcome1);
}
}
void ui_event_TextAreaWelcome2( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_KeyboardWelcome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
      _ui_keyboard_set_target(ui_KeyboardWelcome,  ui_TextAreaWelcome2);
}
}
void ui_event_ButtonGoConfigFromWelcome( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_ScreenConfig, LV_SCR_LOAD_ANIM_NONE, 1, 100, &ui_ScreenConfig_screen_init);
      _ui_flag_modify( ui_KeyboardWelcome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_KeyboardWelcome( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_READY) {
      _ui_flag_modify( ui_KeyboardWelcome, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_ButtonGotoScreenPin2( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_ScreenPIN, LV_SCR_LOAD_ANIM_NONE, 500, 0, &ui_ScreenPIN_screen_init);
}
}
void ui_event_ButtonCallPanelCancel( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_PanelCancel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
      HideQRCode( e );
}
}
void ui_event_ButtonYES( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_PanelCancel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
      _ui_screen_change( &ui_ScreenStart, LV_SCR_LOAD_ANIM_NONE, 500, 0, &ui_ScreenStart_screen_init);
      AddQRCode( e );
}
}
void ui_event_ButtonNO( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_PanelCancel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
      AddQRCode( e );
}
}
void ui_event_ButtonGotoScreenPlay2( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_ScreenStart, LV_SCR_LOAD_ANIM_NONE, 100, 100, &ui_ScreenStart_screen_init);
}
}
void ui_event_ImageTestButtonOrange( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      ButtonPayNow0Click( e );
}
}

///////////////////// SCREENS ////////////////////

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_ScreenStart_screen_init();
ui_ScreenPIN_screen_init();
ui_ScreenConfig_screen_init();
ui_ScreenSwitch1_screen_init();
ui_ScreenWelcome_screen_init();
ui_ScreenScan_screen_init();
ui_ScreenInfo_screen_init();
ui____initial_actions0 = lv_obj_create(NULL);
lv_disp_load_scr( ui_ScreenStart);
}
