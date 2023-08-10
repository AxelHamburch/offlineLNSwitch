SET(SOURCES screens/ui_ScreenStart.c
    screens/ui_ScreenPIN.c
    screens/ui_ScreenConfig.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c)

add_library(ui ${SOURCES})
