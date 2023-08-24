// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.1
// LVGL version: 8.3.6
// Project name: TouchDisplaySmall

#include "../ui.h"

void ui_ScreenScan_screen_init(void)
{
    ui_ScreenScan = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenScan, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenScan, lv_color_hex(0x424344), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenScan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TopScreenScan = lv_obj_create(ui_ScreenScan);
    lv_obj_set_width(ui_TopScreenScan, lv_pct(100));
    lv_obj_set_height(ui_TopScreenScan, lv_pct(10));
    lv_obj_set_align(ui_TopScreenScan, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_TopScreenScan, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_TopScreenScan, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TopScreenScan, lv_color_hex(0x828284), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TopScreenScan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_TopScreenScan, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTopScreenScan = lv_label_create(ui_TopScreenScan);
    lv_obj_set_width(ui_LabelTopScreenScan, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelTopScreenScan, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelTopScreenScan, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelTopScreenScan, "ScreenScan");
    lv_obj_set_style_text_color(ui_LabelTopScreenScan, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTopScreenScan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTopScreenScan, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonGotoScreenPin2 = lv_btn_create(ui_ScreenScan);
    lv_obj_set_width(ui_ButtonGotoScreenPin2, 176);
    lv_obj_set_height(ui_ButtonGotoScreenPin2, 50);
    lv_obj_set_x(ui_ButtonGotoScreenPin2, 49);
    lv_obj_set_y(ui_ButtonGotoScreenPin2, 202);
    lv_obj_set_align(ui_ButtonGotoScreenPin2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonGotoScreenPin2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonGotoScreenPin2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonGotoScreenPin2, lv_color_hex(0xFFBA00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonGotoScreenPin2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonGotoScreenPin2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonGotoScreenPin2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonGotoScreenPin2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelButtonGotoScreenPin2 = lv_label_create(ui_ButtonGotoScreenPin2);
    lv_obj_set_width(ui_LabelButtonGotoScreenPin2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelButtonGotoScreenPin2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelButtonGotoScreenPin2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelButtonGotoScreenPin2, "Enter SECRET");
    lv_obj_set_style_text_color(ui_LabelButtonGotoScreenPin2, lv_color_hex(0x2C2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelButtonGotoScreenPin2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelButtonGotoScreenPin2, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonCallPanelCancel = lv_btn_create(ui_ScreenScan);
    lv_obj_set_width(ui_ButtonCallPanelCancel, 81);
    lv_obj_set_height(ui_ButtonCallPanelCancel, 37);
    lv_obj_set_x(ui_ButtonCallPanelCancel, -90);
    lv_obj_set_y(ui_ButtonCallPanelCancel, 207);
    lv_obj_set_align(ui_ButtonCallPanelCancel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonCallPanelCancel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonCallPanelCancel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonCallPanelCancel, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonCallPanelCancel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ButtonCallPanelCancel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelButtonGotoScreenPin3 = lv_label_create(ui_ButtonCallPanelCancel);
    lv_obj_set_width(ui_LabelButtonGotoScreenPin3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelButtonGotoScreenPin3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelButtonGotoScreenPin3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelButtonGotoScreenPin3, "Cancel");
    lv_obj_set_style_text_color(ui_LabelButtonGotoScreenPin3, lv_color_hex(0x424344), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelButtonGotoScreenPin3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelButtonGotoScreenPin3, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageScanQRCodeBorder = lv_img_create(ui_ScreenScan);
    lv_img_set_src(ui_ImageScanQRCodeBorder, &ui_img_166440904);
    lv_obj_set_width(ui_ImageScanQRCodeBorder, LV_SIZE_CONTENT);   /// 274
    lv_obj_set_height(ui_ImageScanQRCodeBorder, LV_SIZE_CONTENT);    /// 274
    lv_obj_set_x(ui_ImageScanQRCodeBorder, 7);
    lv_obj_set_y(ui_ImageScanQRCodeBorder, 7);
    lv_obj_set_align(ui_ImageScanQRCodeBorder, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageScanQRCodeBorder, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageScanQRCodeBorder, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelProduct = lv_label_create(ui_ScreenScan);
    lv_obj_set_width(ui_LabelProduct, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelProduct, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelProduct, -3);
    lv_obj_set_y(ui_LabelProduct, -173);
    lv_obj_set_align(ui_LabelProduct, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelProduct, "-Product-");
    lv_obj_set_style_text_color(ui_LabelProduct, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelProduct, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelProduct, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelPriceAndCurrency = lv_label_create(ui_ScreenScan);
    lv_obj_set_width(ui_LabelPriceAndCurrency, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelPriceAndCurrency, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelPriceAndCurrency, 0);
    lv_obj_set_y(ui_LabelPriceAndCurrency, -149);
    lv_obj_set_align(ui_LabelPriceAndCurrency, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelPriceAndCurrency, "-PriceAndCurrency-");
    lv_obj_set_style_text_color(ui_LabelPriceAndCurrency, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelPriceAndCurrency, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPriceAndCurrency, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_ScreenScan);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, -3);
    lv_obj_set_y(ui_Label2, 148);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "Scan, pay and check SECRET");
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelCancel = lv_obj_create(ui_ScreenScan);
    lv_obj_set_width(ui_PanelCancel, 301);
    lv_obj_set_height(ui_PanelCancel, 200);
    lv_obj_set_align(ui_PanelCancel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PanelCancel, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_PanelCancel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelCancel, lv_color_hex(0xFB4B4B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCancel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelPanelCancel = lv_label_create(ui_PanelCancel);
    lv_obj_set_width(ui_LabelPanelCancel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelPanelCancel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelPanelCancel, 0);
    lv_obj_set_y(ui_LabelPanelCancel, -36);
    lv_obj_set_align(ui_LabelPanelCancel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelPanelCancel, "Are you sure?\nIf you have already paid\nyou will lose the money?");
    lv_obj_set_style_text_align(ui_LabelPanelCancel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPanelCancel, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonYES = lv_btn_create(ui_PanelCancel);
    lv_obj_set_width(ui_ButtonYES, 66);
    lv_obj_set_height(ui_ButtonYES, 34);
    lv_obj_set_x(ui_ButtonYES, -88);
    lv_obj_set_y(ui_ButtonYES, 48);
    lv_obj_set_align(ui_ButtonYES, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonYES, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonYES, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonYES, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonYES, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelYES = lv_label_create(ui_ButtonYES);
    lv_obj_set_width(ui_LabelYES, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelYES, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelYES, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelYES, "YES");
    lv_obj_set_style_text_color(ui_LabelYES, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelYES, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelYES, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonNO = lv_btn_create(ui_PanelCancel);
    lv_obj_set_width(ui_ButtonNO, 161);
    lv_obj_set_height(ui_ButtonNO, 62);
    lv_obj_set_x(ui_ButtonNO, 42);
    lv_obj_set_y(ui_ButtonNO, 46);
    lv_obj_set_align(ui_ButtonNO, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonNO, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonNO, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonNO, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonNO, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelNO = lv_label_create(ui_ButtonNO);
    lv_obj_set_width(ui_LabelNO, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelNO, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelNO, -1);
    lv_obj_set_y(ui_LabelNO, 1);
    lv_obj_set_align(ui_LabelNO, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelNO, "NO\ntake me back");
    lv_obj_set_style_text_color(ui_LabelNO, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelNO, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelNO, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelNO, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelSECRET = lv_obj_create(ui_ScreenScan);
    lv_obj_set_width(ui_PanelSECRET, 237);
    lv_obj_set_height(ui_PanelSECRET, 232);
    lv_obj_set_x(ui_PanelSECRET, -1);
    lv_obj_set_y(ui_PanelSECRET, -1);
    lv_obj_set_align(ui_PanelSECRET, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelSECRET, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelSECRET, lv_color_hex(0xFFBA00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelSECRET, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelSECRETpin = lv_label_create(ui_PanelSECRET);
    lv_obj_set_width(ui_LabelSECRETpin, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelSECRETpin, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelSECRETpin, 3);
    lv_obj_set_y(ui_LabelSECRETpin, -79);
    lv_obj_set_align(ui_LabelSECRETpin, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelSECRETpin, "Enter SECRET pin");
    lv_obj_set_style_text_font(ui_LabelSECRETpin, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonCheckSECRET = lv_btn_create(ui_PanelSECRET);
    lv_obj_set_width(ui_ButtonCheckSECRET, 120);
    lv_obj_set_height(ui_ButtonCheckSECRET, 50);
    lv_obj_set_x(ui_ButtonCheckSECRET, 49);
    lv_obj_set_y(ui_ButtonCheckSECRET, 25);
    lv_obj_set_align(ui_ButtonCheckSECRET, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonCheckSECRET, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonCheckSECRET, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonCheckSECRET, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonCheckSECRET, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelCheckSECRET = lv_label_create(ui_ButtonCheckSECRET);
    lv_obj_set_width(ui_LabelCheckSECRET, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelCheckSECRET, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelCheckSECRET, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelCheckSECRET, "Check pin");
    lv_obj_set_style_text_color(ui_LabelCheckSECRET, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelCheckSECRET, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelCheckSECRET, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextAreaSECRETpin = lv_textarea_create(ui_PanelSECRET);
    lv_obj_set_width(ui_TextAreaSECRETpin, 150);
    lv_obj_set_height(ui_TextAreaSECRETpin, LV_SIZE_CONTENT);    /// 43
    lv_obj_set_x(ui_TextAreaSECRETpin, 0);
    lv_obj_set_y(ui_TextAreaSECRETpin, -33);
    lv_obj_set_align(ui_TextAreaSECRETpin, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_TextAreaSECRETpin, 4);
    lv_textarea_set_placeholder_text(ui_TextAreaSECRETpin, "4 digits");
    lv_textarea_set_one_line(ui_TextAreaSECRETpin, true);
    lv_obj_set_style_text_align(ui_TextAreaSECRETpin, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextAreaSECRETpin, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonCheckSECRETCancel = lv_btn_create(ui_PanelSECRET);
    lv_obj_set_width(ui_ButtonCheckSECRETCancel, 90);
    lv_obj_set_height(ui_ButtonCheckSECRETCancel, 50);
    lv_obj_set_x(ui_ButtonCheckSECRETCancel, -63);
    lv_obj_set_y(ui_ButtonCheckSECRETCancel, 25);
    lv_obj_set_align(ui_ButtonCheckSECRETCancel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonCheckSECRETCancel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonCheckSECRETCancel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonCheckSECRETCancel, lv_color_hex(0xCFCFD7), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonCheckSECRETCancel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelCheckSECRETCancel = lv_label_create(ui_ButtonCheckSECRETCancel);
    lv_obj_set_width(ui_LabelCheckSECRETCancel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelCheckSECRETCancel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelCheckSECRETCancel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelCheckSECRETCancel, "Cancel");
    lv_obj_set_style_text_color(ui_LabelCheckSECRETCancel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelCheckSECRETCancel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelCheckSECRETCancel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelWrongPin = lv_obj_create(ui_PanelSECRET);
    lv_obj_set_width(ui_PanelWrongPin, 150);
    lv_obj_set_height(ui_PanelWrongPin, 43);
    lv_obj_set_x(ui_PanelWrongPin, 0);
    lv_obj_set_y(ui_PanelWrongPin, -33);
    lv_obj_set_align(ui_PanelWrongPin, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PanelWrongPin, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_PanelWrongPin, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelWrongPin, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelWrongPin, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelWrongPin = lv_label_create(ui_PanelWrongPin);
    lv_obj_set_width(ui_LabelWrongPin, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelWrongPin, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelWrongPin, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelWrongPin, "Wrong pin");
    lv_obj_set_style_text_font(ui_LabelWrongPin, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeyboardCheckSECRET = lv_keyboard_create(ui_ScreenScan);
    lv_keyboard_set_mode(ui_KeyboardCheckSECRET, LV_KEYBOARD_MODE_NUMBER);
    lv_obj_set_width(ui_KeyboardCheckSECRET, 320);
    lv_obj_set_height(ui_KeyboardCheckSECRET, 170);
    lv_obj_set_align(ui_KeyboardCheckSECRET, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_KeyboardCheckSECRET, LV_OBJ_FLAG_HIDDEN);     /// Flags

    lv_obj_add_event_cb(ui_ButtonGotoScreenPin2, ui_event_ButtonGotoScreenPin2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonCallPanelCancel, ui_event_ButtonCallPanelCancel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonYES, ui_event_ButtonYES, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonNO, ui_event_ButtonNO, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonCheckSECRET, ui_event_ButtonCheckSECRET, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaSECRETpin, ui_event_TextAreaSECRETpin, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonCheckSECRETCancel, ui_event_ButtonCheckSECRETCancel, LV_EVENT_ALL, NULL);
    lv_keyboard_set_textarea(ui_KeyboardCheckSECRET, ui_TextAreaSECRETpin);

}
