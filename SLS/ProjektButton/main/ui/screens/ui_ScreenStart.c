// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.1
// LVGL version: 8.3.6
// Project name: TouchDisplaySmall

#include "../ui.h"

void ui_ScreenStart_screen_init(void)
{
    ui_ScreenStart = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenStart, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenStart, lv_color_hex(0x424344), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenStart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TopScreenStart = lv_obj_create(ui_ScreenStart);
    lv_obj_set_width(ui_TopScreenStart, lv_pct(100));
    lv_obj_set_height(ui_TopScreenStart, lv_pct(10));
    lv_obj_set_align(ui_TopScreenStart, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_TopScreenStart, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_TopScreenStart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TopScreenStart, lv_color_hex(0x828284), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TopScreenStart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_TopScreenStart, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTopScreenStart = lv_label_create(ui_TopScreenStart);
    lv_obj_set_width(ui_LabelTopScreenStart, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelTopScreenStart, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelTopScreenStart, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelTopScreenStart, "ScreenStart");
    lv_obj_set_style_text_color(ui_LabelTopScreenStart, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTopScreenStart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTopScreenStart, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonGotoScreenPin = lv_btn_create(ui_ScreenStart);
    lv_obj_set_width(ui_ButtonGotoScreenPin, 100);
    lv_obj_set_height(ui_ButtonGotoScreenPin, 50);
    lv_obj_set_x(ui_ButtonGotoScreenPin, -103);
    lv_obj_set_y(ui_ButtonGotoScreenPin, 205);
    lv_obj_set_align(ui_ButtonGotoScreenPin, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonGotoScreenPin, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonGotoScreenPin, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonGotoScreenPin, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonGotoScreenPin, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonGotoScreenPin, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelButtonGotoScreenPin = lv_label_create(ui_ButtonGotoScreenPin);
    lv_obj_set_width(ui_LabelButtonGotoScreenPin, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelButtonGotoScreenPin, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelButtonGotoScreenPin, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelButtonGotoScreenPin, "Config");
    lv_obj_set_style_text_color(ui_LabelButtonGotoScreenPin, lv_color_hex(0x2C2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelButtonGotoScreenPin, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelButtonGotoScreenPin, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonGotoScreenPinDirekt = lv_btn_create(ui_ScreenStart);
    lv_obj_set_width(ui_ButtonGotoScreenPinDirekt, 100);
    lv_obj_set_height(ui_ButtonGotoScreenPinDirekt, 50);
    lv_obj_set_x(ui_ButtonGotoScreenPinDirekt, 1);
    lv_obj_set_y(ui_ButtonGotoScreenPinDirekt, 206);
    lv_obj_set_align(ui_ButtonGotoScreenPinDirekt, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonGotoScreenPinDirekt, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonGotoScreenPinDirekt, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonGotoScreenPinDirekt, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonGotoScreenPinDirekt, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonGotoScreenPinDirekt, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelButtonGotoScreenPinDirekt = lv_label_create(ui_ButtonGotoScreenPinDirekt);
    lv_obj_set_width(ui_LabelButtonGotoScreenPinDirekt, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelButtonGotoScreenPinDirekt, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelButtonGotoScreenPinDirekt, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelButtonGotoScreenPinDirekt, "direkt");
    lv_obj_set_style_text_color(ui_LabelButtonGotoScreenPinDirekt, lv_color_hex(0x2C2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelButtonGotoScreenPinDirekt, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelButtonGotoScreenPinDirekt, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonGotoScreenPlayground = lv_btn_create(ui_ScreenStart);
    lv_obj_set_width(ui_ButtonGotoScreenPlayground, 100);
    lv_obj_set_height(ui_ButtonGotoScreenPlayground, 50);
    lv_obj_set_x(ui_ButtonGotoScreenPlayground, 106);
    lv_obj_set_y(ui_ButtonGotoScreenPlayground, 206);
    lv_obj_set_align(ui_ButtonGotoScreenPlayground, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonGotoScreenPlayground, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonGotoScreenPlayground, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonGotoScreenPlayground, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonGotoScreenPlayground, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonGotoScreenPlayground, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonGotoScreenPlayground, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonGotoScreenPlayground, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelButtonGotoScreenPlayground = lv_label_create(ui_ButtonGotoScreenPlayground);
    lv_obj_set_width(ui_LabelButtonGotoScreenPlayground, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelButtonGotoScreenPlayground, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelButtonGotoScreenPlayground, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelButtonGotoScreenPlayground, "Playgr.");
    lv_obj_set_style_text_color(ui_LabelButtonGotoScreenPlayground, lv_color_hex(0x2C2D2D),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelButtonGotoScreenPlayground, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelButtonGotoScreenPlayground, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonPayNow = lv_btn_create(ui_ScreenStart);
    lv_obj_set_width(ui_ButtonPayNow, 299);
    lv_obj_set_height(ui_ButtonPayNow, 50);
    lv_obj_set_x(ui_ButtonPayNow, 1);
    lv_obj_set_y(ui_ButtonPayNow, 146);
    lv_obj_set_align(ui_ButtonPayNow, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonPayNow, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonPayNow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonPayNow, lv_color_hex(0xFFBA00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPayNow, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonPayNow, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelButtonPayNowClick = lv_label_create(ui_ButtonPayNow);
    lv_obj_set_width(ui_LabelButtonPayNowClick, LV_SIZE_CONTENT);   /// -714
    lv_obj_set_height(ui_LabelButtonPayNowClick, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelButtonPayNowClick, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelButtonPayNowClick, "Start bitcoinSwitch");
    lv_obj_set_style_text_color(ui_LabelButtonPayNowClick, lv_color_hex(0x2C2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelButtonPayNowClick, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelButtonPayNowClick, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image2 = lv_img_create(ui_ScreenStart);
    lv_img_set_src(ui_Image2, &ui_img_bsapp256_png);
    lv_obj_set_width(ui_Image2, LV_SIZE_CONTENT);   /// 256
    lv_obj_set_height(ui_Image2, LV_SIZE_CONTENT);    /// 256
    lv_obj_set_x(ui_Image2, 2);
    lv_obj_set_y(ui_Image2, -34);
    lv_obj_set_align(ui_Image2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_ButtonGotoScreenPin, ui_event_ButtonGotoScreenPin, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonGotoScreenPinDirekt, ui_event_ButtonGotoScreenPinDirekt, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonGotoScreenPlayground, ui_event_ButtonGotoScreenPlayground, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonPayNow, ui_event_ButtonPayNow, LV_EVENT_ALL, NULL);

}