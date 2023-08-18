// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.1
// LVGL version: 8.3.6
// Project name: TouchDisplaySmall

#include "../ui.h"

void ui_ScreenSwitch1_screen_init(void)
{
    ui_ScreenSwitch1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenSwitch1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenSwitch1, lv_color_hex(0x424344), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenSwitch1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TopScreenConfig1 = lv_obj_create(ui_ScreenSwitch1);
    lv_obj_set_width(ui_TopScreenConfig1, lv_pct(100));
    lv_obj_set_height(ui_TopScreenConfig1, lv_pct(10));
    lv_obj_set_align(ui_TopScreenConfig1, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_TopScreenConfig1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_TopScreenConfig1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TopScreenConfig1, lv_color_hex(0x828284), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TopScreenConfig1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_TopScreenConfig1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTopScreenSwitch2 = lv_label_create(ui_TopScreenConfig1);
    lv_obj_set_width(ui_LabelTopScreenSwitch2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelTopScreenSwitch2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelTopScreenSwitch2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelTopScreenSwitch2, "Set up switch 1");
    lv_obj_set_style_text_color(ui_LabelTopScreenSwitch2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTopScreenSwitch2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTopScreenSwitch2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelSwitch1 = lv_label_create(ui_ScreenSwitch1);
    lv_obj_set_width(ui_LabelSwitch1, LV_SIZE_CONTENT);   /// -95
    lv_obj_set_height(ui_LabelSwitch1, LV_SIZE_CONTENT);    /// 3
    lv_obj_set_x(ui_LabelSwitch1, -104);
    lv_obj_set_y(ui_LabelSwitch1, -158);
    lv_obj_set_align(ui_LabelSwitch1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelSwitch1, "Switch 1");
    lv_obj_set_style_text_color(ui_LabelSwitch1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSwitch1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_LabelSwitch1, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSwitch1, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTestFunction1 = lv_label_create(ui_ScreenSwitch1);
    lv_obj_set_width(ui_LabelTestFunction1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelTestFunction1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelTestFunction1, -75);
    lv_obj_set_y(ui_LabelTestFunction1, 135);
    lv_obj_set_align(ui_LabelTestFunction1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelTestFunction1, "Test function:");
    lv_obj_set_style_text_color(ui_LabelTestFunction1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTestFunction1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_LabelTestFunction1, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonTestRelay1 = lv_btn_create(ui_ScreenSwitch1);
    lv_obj_set_width(ui_ButtonTestRelay1, 159);
    lv_obj_set_height(ui_ButtonTestRelay1, 43);
    lv_obj_set_x(ui_ButtonTestRelay1, 60);
    lv_obj_set_y(ui_ButtonTestRelay1, 143);
    lv_obj_set_align(ui_ButtonTestRelay1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonTestRelay1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonTestRelay1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonTestRelay1, lv_color_hex(0xE5FE5C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonTestRelay1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonTestRelay1, lv_color_hex(0xF5FD00), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_ButtonTestRelay1, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_ButtonTestRelay1, lv_color_hex(0xF9F14B), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_ButtonTestRelay1, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_ButtonTestRelay1, 20, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_ButtonTestRelay1, 5, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelTestRelay1 = lv_label_create(ui_ButtonTestRelay1);
    lv_obj_set_width(ui_LabelTestRelay1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelTestRelay1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelTestRelay1, -1);
    lv_obj_set_y(ui_LabelTestRelay1, 0);
    lv_obj_set_align(ui_LabelTestRelay1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelTestRelay1, "Switch 1");
    lv_obj_set_style_text_color(ui_LabelTestRelay1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTestRelay1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTestRelay1, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextAreaSwitchName1 = lv_textarea_create(ui_ScreenSwitch1);
    lv_obj_set_width(ui_TextAreaSwitchName1, 200);
    lv_obj_set_height(ui_TextAreaSwitchName1, LV_SIZE_CONTENT);    /// 39
    lv_obj_set_x(ui_TextAreaSwitchName1, 48);
    lv_obj_set_y(ui_TextAreaSwitchName1, -130);
    lv_obj_set_align(ui_TextAreaSwitchName1, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_TextAreaSwitchName1, "Your choise");
    lv_textarea_set_one_line(ui_TextAreaSwitchName1, true);

    ui_LabelSwitchName1 = lv_label_create(ui_ScreenSwitch1);
    lv_obj_set_width(ui_LabelSwitchName1, LV_SIZE_CONTENT);   /// -95
    lv_obj_set_height(ui_LabelSwitchName1, LV_SIZE_CONTENT);    /// 3
    lv_obj_set_x(ui_LabelSwitchName1, -105);
    lv_obj_set_y(ui_LabelSwitchName1, -130);
    lv_obj_set_align(ui_LabelSwitchName1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelSwitchName1, "Name:");
    lv_obj_set_style_text_color(ui_LabelSwitchName1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSwitchName1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextAreaSwitchPrice1 = lv_textarea_create(ui_ScreenSwitch1);
    lv_obj_set_width(ui_TextAreaSwitchPrice1, 200);
    lv_obj_set_height(ui_TextAreaSwitchPrice1, LV_SIZE_CONTENT);    /// 39
    lv_obj_set_x(ui_TextAreaSwitchPrice1, 48);
    lv_obj_set_y(ui_TextAreaSwitchPrice1, -88);
    lv_obj_set_align(ui_TextAreaSwitchPrice1, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_TextAreaSwitchPrice1, "e.g. 1 sat or 1.00 EUR");
    lv_textarea_set_one_line(ui_TextAreaSwitchPrice1, true);

    ui_LabelSwitchPrice1 = lv_label_create(ui_ScreenSwitch1);
    lv_obj_set_width(ui_LabelSwitchPrice1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelSwitchPrice1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelSwitchPrice1, -105);
    lv_obj_set_y(ui_LabelSwitchPrice1, -88);
    lv_obj_set_align(ui_LabelSwitchPrice1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelSwitchPrice1, "Price:");
    lv_obj_set_style_text_color(ui_LabelSwitchPrice1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSwitchPrice1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextAreaSwitchTime1 = lv_textarea_create(ui_ScreenSwitch1);
    lv_obj_set_width(ui_TextAreaSwitchTime1, 200);
    lv_obj_set_height(ui_TextAreaSwitchTime1, LV_SIZE_CONTENT);    /// 39
    lv_obj_set_x(ui_TextAreaSwitchTime1, 48);
    lv_obj_set_y(ui_TextAreaSwitchTime1, -47);
    lv_obj_set_align(ui_TextAreaSwitchTime1, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_TextAreaSwitchTime1, "Time in ms");
    lv_textarea_set_one_line(ui_TextAreaSwitchTime1, true);

    ui_LabelSwitchTime1 = lv_label_create(ui_ScreenSwitch1);
    lv_obj_set_width(ui_LabelSwitchTime1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelSwitchTime1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelSwitchTime1, -103);
    lv_obj_set_y(ui_LabelSwitchTime1, -46);
    lv_obj_set_align(ui_LabelSwitchTime1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelSwitchTime1, "Time:");
    lv_obj_set_style_text_color(ui_LabelSwitchTime1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSwitchTime1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelSwitchRelay1 = lv_label_create(ui_ScreenSwitch1);
    lv_obj_set_width(ui_LabelSwitchRelay1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelSwitchRelay1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelSwitchRelay1, -103);
    lv_obj_set_y(ui_LabelSwitchRelay1, -7);
    lv_obj_set_align(ui_LabelSwitchRelay1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelSwitchRelay1, "GPIO:");
    lv_obj_set_style_text_color(ui_LabelSwitchRelay1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSwitchRelay1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextAreaSwitchRelay1 = lv_textarea_create(ui_ScreenSwitch1);
    lv_obj_set_width(ui_TextAreaSwitchRelay1, 200);
    lv_obj_set_height(ui_TextAreaSwitchRelay1, LV_SIZE_CONTENT);    /// 39
    lv_obj_set_x(ui_TextAreaSwitchRelay1, 48);
    lv_obj_set_y(ui_TextAreaSwitchRelay1, -6);
    lv_obj_set_align(ui_TextAreaSwitchRelay1, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_TextAreaSwitchRelay1, 6);
    lv_textarea_set_placeholder_text(ui_TextAreaSwitchRelay1, "21 (or 22)");
    lv_textarea_set_one_line(ui_TextAreaSwitchRelay1, true);
    lv_obj_set_style_text_color(ui_TextAreaSwitchRelay1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TextAreaSwitchRelay1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextAreaSwitchRelay1, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TextAreaSwitchRelay1, lv_color_hex(0x919191), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TextAreaSwitchRelay1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonGoConfig = lv_btn_create(ui_ScreenSwitch1);
    lv_obj_set_width(ui_ButtonGoConfig, 120);
    lv_obj_set_height(ui_ButtonGoConfig, 41);
    lv_obj_set_x(ui_ButtonGoConfig, -64);
    lv_obj_set_y(ui_ButtonGoConfig, 207);
    lv_obj_set_align(ui_ButtonGoConfig, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonGoConfig, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonGoConfig, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonGoConfig, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonGoConfig, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonGoConfig, lv_color_hex(0x131212), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonGoConfig, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonGoConfig, lv_color_hex(0x939393), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_ButtonGoConfig, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelButtonGoConfig = lv_label_create(ui_ButtonGoConfig);
    lv_obj_set_width(ui_LabelButtonGoConfig, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelButtonGoConfig, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelButtonGoConfig, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelButtonGoConfig, "Config");
    lv_obj_set_style_text_font(ui_LabelButtonGoConfig, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeyboardSwitchText1 = lv_keyboard_create(ui_ScreenSwitch1);
    lv_obj_set_width(ui_KeyboardSwitchText1, 320);
    lv_obj_set_height(ui_KeyboardSwitchText1, 170);
    lv_obj_set_align(ui_KeyboardSwitchText1, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_KeyboardSwitchText1, LV_OBJ_FLAG_HIDDEN);     /// Flags

    ui_KeyboardSwitchNumber1 = lv_keyboard_create(ui_ScreenSwitch1);
    lv_keyboard_set_mode(ui_KeyboardSwitchNumber1, LV_KEYBOARD_MODE_NUMBER);
    lv_obj_set_width(ui_KeyboardSwitchNumber1, 320);
    lv_obj_set_height(ui_KeyboardSwitchNumber1, 170);
    lv_obj_set_align(ui_KeyboardSwitchNumber1, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_KeyboardSwitchNumber1, LV_OBJ_FLAG_HIDDEN);     /// Flags

    lv_obj_add_event_cb(ui_ButtonTestRelay1, ui_event_ButtonTestRelay1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaSwitchName1, ui_event_TextAreaSwitchName1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaSwitchPrice1, ui_event_TextAreaSwitchPrice1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaSwitchTime1, ui_event_TextAreaSwitchTime1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaSwitchRelay1, ui_event_TextAreaSwitchRelay1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonGoConfig, ui_event_ButtonGoConfig, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_KeyboardSwitchText1, ui_event_KeyboardSwitchText1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_KeyboardSwitchNumber1, ui_event_KeyboardSwitchNumber1, LV_EVENT_ALL, NULL);

}
