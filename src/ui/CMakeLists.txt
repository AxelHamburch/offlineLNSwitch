SET(SOURCES screens/ui_ScreenStart.c
    screens/ui_ScreenPIN.c
    screens/ui_ScreenConfig.c
    screens/ui_ScreenSwitch1.c
    screens/ui_ScreenScan.c
    screens/ui_ScreenPlayground.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_offlinebitcoinswitch_svg_2023_08_24_14_52_14_0_png.c
    images/ui_img_166440904.c)

add_library(ui ${SOURCES})
