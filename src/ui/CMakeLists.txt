SET(SOURCES screens/ui_ScreenStart.c
    screens/ui_ScreenPIN.c
    screens/ui_ScreenConfig.c
    screens/ui_ScreenSwitch1.c
    screens/ui_ScreenScan.c
    screens/ui_ScreenPlayground.c
    screens/ui_ScreenInfo.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_buttonorange_png.c
    images/ui_img_buttongreen_png.c
    images/ui_img_gear_wheel_100pix_gray_png.c
    images/ui_img_info_100pix_gray_png.c
    images/ui_img_166440904.c
    images/ui_img_buttontestgreen_png.c
    images/ui_img_buttontestorange_png.c
    images/ui_img_ereignishorizont_xyz_128_png.c)

add_library(ui ${SOURCES})
