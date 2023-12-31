// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: TouchDisplaySmall

#include "../ui.h"

void ui_ScreenSwitch1_screen_init(void)
{
ui_ScreenSwitch1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_ScreenSwitch1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ScreenSwitch1, lv_color_hex(0x0D3E6E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ScreenSwitch1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TopScreenConfigSwitch1 = lv_obj_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_TopScreenConfigSwitch1, lv_pct(100));
lv_obj_set_height( ui_TopScreenConfigSwitch1, lv_pct(10));
lv_obj_set_align( ui_TopScreenConfigSwitch1, LV_ALIGN_TOP_MID );
lv_obj_clear_flag( ui_TopScreenConfigSwitch1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_TopScreenConfigSwitch1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_TopScreenConfigSwitch1, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TopScreenConfigSwitch1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_TopScreenConfigSwitch1, LV_BORDER_SIDE_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LabelTopScreenSwitch1 = lv_label_create(ui_TopScreenConfigSwitch1);
lv_obj_set_width( ui_LabelTopScreenSwitch1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelTopScreenSwitch1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_LabelTopScreenSwitch1, LV_ALIGN_CENTER );
lv_label_set_text(ui_LabelTopScreenSwitch1,"Set up options");
lv_obj_set_style_text_color(ui_LabelTopScreenSwitch1, lv_color_hex(0x0D3E6E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LabelTopScreenSwitch1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_LabelTopScreenSwitch1, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_LabelTopScreenSwitch1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_LabelTopScreenSwitch1, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LabelSwitch1 = lv_label_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_LabelSwitch1, LV_SIZE_CONTENT);  /// -95
lv_obj_set_height( ui_LabelSwitch1, LV_SIZE_CONTENT);   /// 3
lv_obj_set_x( ui_LabelSwitch1, 0 );
lv_obj_set_y( ui_LabelSwitch1, -170 );
lv_obj_set_align( ui_LabelSwitch1, LV_ALIGN_CENTER );
lv_label_set_text(ui_LabelSwitch1,"Switch and Energy Mode");
lv_obj_set_style_text_color(ui_LabelSwitch1, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LabelSwitch1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_decor(ui_LabelSwitch1, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_LabelSwitch1, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LabelTestFunction1 = lv_label_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_LabelTestFunction1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelTestFunction1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LabelTestFunction1, -35 );
lv_obj_set_y( ui_LabelTestFunction1, 146 );
lv_obj_set_align( ui_LabelTestFunction1, LV_ALIGN_CENTER );
lv_label_set_text(ui_LabelTestFunction1,"Toggle Switch:");
lv_obj_set_style_text_color(ui_LabelTestFunction1, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LabelTestFunction1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_decor(ui_LabelTestFunction1, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TextAreaSwitchName1 = lv_textarea_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_TextAreaSwitchName1, 200);
lv_obj_set_height( ui_TextAreaSwitchName1, LV_SIZE_CONTENT);   /// 39
lv_obj_set_x( ui_TextAreaSwitchName1, 48 );
lv_obj_set_y( ui_TextAreaSwitchName1, -130 );
lv_obj_set_align( ui_TextAreaSwitchName1, LV_ALIGN_CENTER );
lv_textarea_set_placeholder_text(ui_TextAreaSwitchName1,"Your choice");
lv_textarea_set_one_line(ui_TextAreaSwitchName1,true);



ui_LabelSwitchName1 = lv_label_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_LabelSwitchName1, LV_SIZE_CONTENT);  /// -95
lv_obj_set_height( ui_LabelSwitchName1, LV_SIZE_CONTENT);   /// 3
lv_obj_set_x( ui_LabelSwitchName1, -105 );
lv_obj_set_y( ui_LabelSwitchName1, -130 );
lv_obj_set_align( ui_LabelSwitchName1, LV_ALIGN_CENTER );
lv_label_set_text(ui_LabelSwitchName1,"Name:");
lv_obj_set_style_text_color(ui_LabelSwitchName1, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LabelSwitchName1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TextAreaSwitchPrice1 = lv_textarea_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_TextAreaSwitchPrice1, 200);
lv_obj_set_height( ui_TextAreaSwitchPrice1, LV_SIZE_CONTENT);   /// 39
lv_obj_set_x( ui_TextAreaSwitchPrice1, 48 );
lv_obj_set_y( ui_TextAreaSwitchPrice1, -88 );
lv_obj_set_align( ui_TextAreaSwitchPrice1, LV_ALIGN_CENTER );
lv_textarea_set_placeholder_text(ui_TextAreaSwitchPrice1,"e.g. 1 sat or 1.00 EUR");
lv_textarea_set_one_line(ui_TextAreaSwitchPrice1,true);



ui_LabelSwitchPrice1 = lv_label_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_LabelSwitchPrice1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelSwitchPrice1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LabelSwitchPrice1, -105 );
lv_obj_set_y( ui_LabelSwitchPrice1, -88 );
lv_obj_set_align( ui_LabelSwitchPrice1, LV_ALIGN_CENTER );
lv_label_set_text(ui_LabelSwitchPrice1,"Price:");
lv_obj_set_style_text_color(ui_LabelSwitchPrice1, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LabelSwitchPrice1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TextAreaSwitchTime1 = lv_textarea_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_TextAreaSwitchTime1, 200);
lv_obj_set_height( ui_TextAreaSwitchTime1, LV_SIZE_CONTENT);   /// 39
lv_obj_set_x( ui_TextAreaSwitchTime1, 48 );
lv_obj_set_y( ui_TextAreaSwitchTime1, -47 );
lv_obj_set_align( ui_TextAreaSwitchTime1, LV_ALIGN_CENTER );
lv_textarea_set_placeholder_text(ui_TextAreaSwitchTime1,"Time in ms");
lv_textarea_set_one_line(ui_TextAreaSwitchTime1,true);



ui_LabelSwitchTime1 = lv_label_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_LabelSwitchTime1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelSwitchTime1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LabelSwitchTime1, -105 );
lv_obj_set_y( ui_LabelSwitchTime1, -46 );
lv_obj_set_align( ui_LabelSwitchTime1, LV_ALIGN_CENTER );
lv_label_set_text(ui_LabelSwitchTime1,"Time:");
lv_obj_set_style_text_color(ui_LabelSwitchTime1, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LabelSwitchTime1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LabelSwitchRelay1 = lv_label_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_LabelSwitchRelay1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelSwitchRelay1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LabelSwitchRelay1, -105 );
lv_obj_set_y( ui_LabelSwitchRelay1, -7 );
lv_obj_set_align( ui_LabelSwitchRelay1, LV_ALIGN_CENTER );
lv_label_set_text(ui_LabelSwitchRelay1,"GPIO:");
lv_obj_set_style_text_color(ui_LabelSwitchRelay1, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LabelSwitchRelay1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TextAreaSwitchRelay1 = lv_textarea_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_TextAreaSwitchRelay1, 200);
lv_obj_set_height( ui_TextAreaSwitchRelay1, LV_SIZE_CONTENT);   /// 39
lv_obj_set_x( ui_TextAreaSwitchRelay1, 48 );
lv_obj_set_y( ui_TextAreaSwitchRelay1, -6 );
lv_obj_set_align( ui_TextAreaSwitchRelay1, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_TextAreaSwitchRelay1,6);
lv_textarea_set_placeholder_text(ui_TextAreaSwitchRelay1,"21 (Currently fixed)");
lv_textarea_set_one_line(ui_TextAreaSwitchRelay1,true);
lv_obj_clear_flag( ui_TextAreaSwitchRelay1, LV_OBJ_FLAG_CLICKABLE );    /// Flags
lv_obj_set_style_text_color(ui_TextAreaSwitchRelay1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TextAreaSwitchRelay1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TextAreaSwitchRelay1, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_TextAreaSwitchRelay1, lv_color_hex(0x919191), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TextAreaSwitchRelay1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_LabelEnergyMode = lv_label_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_LabelEnergyMode, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelEnergyMode, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LabelEnergyMode, -105 );
lv_obj_set_y( ui_LabelEnergyMode, 33 );
lv_obj_set_align( ui_LabelEnergyMode, LV_ALIGN_CENTER );
lv_label_set_text(ui_LabelEnergyMode,"Energy\nMode:");
lv_obj_set_style_text_color(ui_LabelEnergyMode, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LabelEnergyMode, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_LabelEnergyMode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TextAreaEnergyMode = lv_textarea_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_TextAreaEnergyMode, 200);
lv_obj_set_height( ui_TextAreaEnergyMode, LV_SIZE_CONTENT);   /// 39
lv_obj_set_x( ui_TextAreaEnergyMode, 48 );
lv_obj_set_y( ui_TextAreaEnergyMode, 34 );
lv_obj_set_align( ui_TextAreaEnergyMode, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_TextAreaEnergyMode,1);
lv_textarea_set_placeholder_text(ui_TextAreaEnergyMode,"0 (standard), 1 or 2");
lv_textarea_set_one_line(ui_TextAreaEnergyMode,true);



ui_LabelEnergyModeExplain = lv_label_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_LabelEnergyModeExplain, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelEnergyModeExplain, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LabelEnergyModeExplain, 51 );
lv_obj_set_y( ui_LabelEnergyModeExplain, 88 );
lv_obj_set_align( ui_LabelEnergyModeExplain, LV_ALIGN_CENTER );
lv_label_set_text(ui_LabelEnergyModeExplain,"0 = energy saving off\n1 = software deep sleep\n2 = external hardware relay \nNote: Read documentation");
lv_obj_set_style_text_color(ui_LabelEnergyModeExplain, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LabelEnergyModeExplain, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ButtonGoConfig = lv_btn_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_ButtonGoConfig, 120);
lv_obj_set_height( ui_ButtonGoConfig, 41);
lv_obj_set_x( ui_ButtonGoConfig, -70 );
lv_obj_set_y( ui_ButtonGoConfig, 207 );
lv_obj_set_align( ui_ButtonGoConfig, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ButtonGoConfig, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_ButtonGoConfig, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ButtonGoConfig, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ButtonGoConfig, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_ButtonGoConfig, lv_color_hex(0x131212), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_ButtonGoConfig, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_ButtonGoConfig, lv_color_hex(0x939393), LV_PART_MAIN | LV_STATE_PRESSED );
lv_obj_set_style_bg_opa(ui_ButtonGoConfig, 255, LV_PART_MAIN| LV_STATE_PRESSED);

ui_LabelButtonGoConfig = lv_label_create(ui_ButtonGoConfig);
lv_obj_set_width( ui_LabelButtonGoConfig, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelButtonGoConfig, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_LabelButtonGoConfig, LV_ALIGN_CENTER );
lv_label_set_text(ui_LabelButtonGoConfig,"Config");
lv_obj_set_style_text_color(ui_LabelButtonGoConfig, lv_color_hex(0x0D3E6E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LabelButtonGoConfig, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_LabelButtonGoConfig, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SwitchToggle1 = lv_switch_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_SwitchToggle1, 50);
lv_obj_set_height( ui_SwitchToggle1, 25);
lv_obj_set_x( ui_SwitchToggle1, 61 );
lv_obj_set_y( ui_SwitchToggle1, 147 );
lv_obj_set_align( ui_SwitchToggle1, LV_ALIGN_CENTER );


ui_KeyboardSwitchText1 = lv_keyboard_create(ui_ScreenSwitch1);
lv_obj_set_width( ui_KeyboardSwitchText1, 320);
lv_obj_set_height( ui_KeyboardSwitchText1, 170);
lv_obj_set_align( ui_KeyboardSwitchText1, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_KeyboardSwitchText1, LV_OBJ_FLAG_HIDDEN );   /// Flags

ui_KeyboardSwitchNumber1 = lv_keyboard_create(ui_ScreenSwitch1);
lv_keyboard_set_mode(ui_KeyboardSwitchNumber1,LV_KEYBOARD_MODE_NUMBER);
lv_obj_set_width( ui_KeyboardSwitchNumber1, 320);
lv_obj_set_height( ui_KeyboardSwitchNumber1, 170);
lv_obj_set_align( ui_KeyboardSwitchNumber1, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_KeyboardSwitchNumber1, LV_OBJ_FLAG_HIDDEN );   /// Flags

lv_obj_add_event_cb(ui_TextAreaSwitchName1, ui_event_TextAreaSwitchName1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_TextAreaSwitchPrice1, ui_event_TextAreaSwitchPrice1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_TextAreaSwitchTime1, ui_event_TextAreaSwitchTime1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_TextAreaSwitchRelay1, ui_event_TextAreaSwitchRelay1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_TextAreaEnergyMode, ui_event_TextAreaEnergyMode, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_ButtonGoConfig, ui_event_ButtonGoConfig, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_SwitchToggle1, ui_event_SwitchToggle1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_KeyboardSwitchText1, ui_event_KeyboardSwitchText1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_KeyboardSwitchNumber1, ui_event_KeyboardSwitchNumber1, LV_EVENT_ALL, NULL);

}
