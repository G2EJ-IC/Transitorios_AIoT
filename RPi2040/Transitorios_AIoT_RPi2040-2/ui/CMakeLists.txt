SET(SOURCES 
    actions.h
    eez-flow-lz4.c
    eez-flow-lz4.h
    eez-flow.cpp
    eez-flow.h
    fonts.h
    images.c
    images.h
    screens.c
    screens.h
    structs.h
    styles.c
    styles.h
    ui.c
    ui.h
    ui_image_aio_t.c
    ui_image_aio_t_235x157.c
    ui_image_ud_fjd_c.c
    ui_image_ud_fjd_c_058x077.c
    vars.h
    )

add_library(ui ${SOURCES})