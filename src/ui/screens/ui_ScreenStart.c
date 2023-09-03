// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: TouchDisplaySmall

#include "../ui.h"

void ui_ScreenStart_screen_init(void)
{
ui_ScreenStart = lv_obj_create(NULL);
lv_obj_clear_flag( ui_ScreenStart, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ScreenStart, lv_color_hex(0x0D3E6E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ScreenStart, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TopScreenStart = lv_obj_create(ui_ScreenStart);
lv_obj_set_width( ui_TopScreenStart, lv_pct(100));
lv_obj_set_height( ui_TopScreenStart, lv_pct(10));
lv_obj_set_align( ui_TopScreenStart, LV_ALIGN_TOP_MID );
lv_obj_clear_flag( ui_TopScreenStart, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_TopScreenStart, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_TopScreenStart, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TopScreenStart, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_TopScreenStart, LV_BORDER_SIDE_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_TopScreenStart, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TopScreenStart, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LabelTopScreenStart = lv_label_create(ui_TopScreenStart);
lv_obj_set_width( ui_LabelTopScreenStart, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelTopScreenStart, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_LabelTopScreenStart, LV_ALIGN_CENTER );
lv_label_set_text(ui_LabelTopScreenStart,"Welcome");
lv_obj_set_style_text_color(ui_LabelTopScreenStart, lv_color_hex(0x0D3E6E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LabelTopScreenStart, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_LabelTopScreenStart, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_LabelTopScreenStart, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_LabelTopScreenStart, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ImageBitcoinSwitchOrange = lv_img_create(ui_ScreenStart);
lv_img_set_src(ui_ImageBitcoinSwitchOrange, &ui_img_buttonorange_png);
lv_obj_set_width( ui_ImageBitcoinSwitchOrange, LV_SIZE_CONTENT);  /// 236
lv_obj_set_height( ui_ImageBitcoinSwitchOrange, LV_SIZE_CONTENT);   /// 300
lv_obj_set_x( ui_ImageBitcoinSwitchOrange, 10 );
lv_obj_set_y( ui_ImageBitcoinSwitchOrange, -15 );
lv_obj_set_align( ui_ImageBitcoinSwitchOrange, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ImageBitcoinSwitchOrange, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_ImageBitcoinSwitchOrange, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_ImageBitcoinSwitchGreen = lv_img_create(ui_ScreenStart);
lv_img_set_src(ui_ImageBitcoinSwitchGreen, &ui_img_buttongreen_png);
lv_obj_set_width( ui_ImageBitcoinSwitchGreen, LV_SIZE_CONTENT);  /// 236
lv_obj_set_height( ui_ImageBitcoinSwitchGreen, LV_SIZE_CONTENT);   /// 300
lv_obj_set_x( ui_ImageBitcoinSwitchGreen, 10 );
lv_obj_set_y( ui_ImageBitcoinSwitchGreen, -15 );
lv_obj_set_align( ui_ImageBitcoinSwitchGreen, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ImageBitcoinSwitchGreen, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_ImageBitcoinSwitchGreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_ImageSettings = lv_img_create(ui_ScreenStart);
lv_img_set_src(ui_ImageSettings, &ui_img_gear_wheel_100pix_gray_png);
lv_obj_set_width( ui_ImageSettings, LV_SIZE_CONTENT);  /// 100
lv_obj_set_height( ui_ImageSettings, LV_SIZE_CONTENT);   /// 101
lv_obj_set_x( ui_ImageSettings, -123 );
lv_obj_set_y( ui_ImageSettings, 205 );
lv_obj_set_align( ui_ImageSettings, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ImageSettings, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_ImageSettings, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_ImageSettings,121);

ui_ImageInfo = lv_img_create(ui_ScreenStart);
lv_img_set_src(ui_ImageInfo, &ui_img_info_100pix_gray_png);
lv_obj_set_width( ui_ImageInfo, LV_SIZE_CONTENT);  /// 100
lv_obj_set_height( ui_ImageInfo, LV_SIZE_CONTENT);   /// 100
lv_obj_set_x( ui_ImageInfo, 123 );
lv_obj_set_y( ui_ImageInfo, 205 );
lv_obj_set_align( ui_ImageInfo, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ImageInfo, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_ImageInfo, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_ImageInfo,121);

ui_PanelPINConfig = lv_obj_create(ui_ScreenStart);
lv_obj_set_width( ui_PanelPINConfig, 279);
lv_obj_set_height( ui_PanelPINConfig, 164);
lv_obj_set_x( ui_PanelPINConfig, 0 );
lv_obj_set_y( ui_PanelPINConfig, -40 );
lv_obj_set_align( ui_PanelPINConfig, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_PanelPINConfig, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_clear_flag( ui_PanelPINConfig, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_PanelPINConfig, lv_color_hex(0x0D3E6E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PanelPINConfig, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LabelEnterConfigPin = lv_label_create(ui_PanelPINConfig);
lv_obj_set_width( ui_LabelEnterConfigPin, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelEnterConfigPin, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LabelEnterConfigPin, 0 );
lv_obj_set_y( ui_LabelEnterConfigPin, -53 );
lv_obj_set_align( ui_LabelEnterConfigPin, LV_ALIGN_CENTER );
lv_label_set_text(ui_LabelEnterConfigPin,"Enter Config PIN");
lv_obj_set_style_text_color(ui_LabelEnterConfigPin, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LabelEnterConfigPin, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_LabelEnterConfigPin, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TextAreaPINConfig = lv_textarea_create(ui_PanelPINConfig);
lv_obj_set_width( ui_TextAreaPINConfig, 150);
lv_obj_set_height( ui_TextAreaPINConfig, LV_SIZE_CONTENT);   /// 70
lv_obj_set_x( ui_TextAreaPINConfig, 0 );
lv_obj_set_y( ui_TextAreaPINConfig, -6 );
lv_obj_set_align( ui_TextAreaPINConfig, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_TextAreaPINConfig,6);
lv_textarea_set_placeholder_text(ui_TextAreaPINConfig,"6 digits");
lv_textarea_set_one_line(ui_TextAreaPINConfig,true);
lv_obj_set_style_text_align(ui_TextAreaPINConfig, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TextAreaPINConfig, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_ButtonCancelPIN = lv_btn_create(ui_PanelPINConfig);
lv_obj_set_width( ui_ButtonCancelPIN, 100);
lv_obj_set_height( ui_ButtonCancelPIN, 40);
lv_obj_set_x( ui_ButtonCancelPIN, 0 );
lv_obj_set_y( ui_ButtonCancelPIN, 47 );
lv_obj_set_align( ui_ButtonCancelPIN, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ButtonCancelPIN, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_ButtonCancelPIN, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ButtonCancelPIN, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ButtonCancelPIN, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LabelCancelPIN = lv_label_create(ui_ButtonCancelPIN);
lv_obj_set_width( ui_LabelCancelPIN, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LabelCancelPIN, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_LabelCancelPIN, LV_ALIGN_CENTER );
lv_label_set_text(ui_LabelCancelPIN,"Cancel");
lv_obj_set_style_text_color(ui_LabelCancelPIN, lv_color_hex(0x0D3E6E), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LabelCancelPIN, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_LabelCancelPIN, &lv_font_montserrat_20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_KeyboardPINConfig = lv_keyboard_create(ui_ScreenStart);
lv_keyboard_set_mode(ui_KeyboardPINConfig,LV_KEYBOARD_MODE_NUMBER);
lv_obj_set_width( ui_KeyboardPINConfig, 320);
lv_obj_set_height( ui_KeyboardPINConfig, 170);
lv_obj_set_align( ui_KeyboardPINConfig, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_KeyboardPINConfig, LV_OBJ_FLAG_HIDDEN );   /// Flags

lv_obj_add_event_cb(ui_ImageBitcoinSwitchOrange, ui_event_ImageBitcoinSwitchOrange, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_ImageSettings, ui_event_ImageSettings, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_ImageInfo, ui_event_ImageInfo, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_ButtonCancelPIN, ui_event_ButtonCancelPIN, LV_EVENT_ALL, NULL);
lv_keyboard_set_textarea(ui_KeyboardPINConfig,ui_TextAreaPINConfig);

}
