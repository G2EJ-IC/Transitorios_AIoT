#include "Arduino.h"

#include "pico/stdlib.h"
#include "TFT_eSPI.h"
#include "lvgl.h"
#include "ui.h"

#include "config.h"

    enum ScreenSettings { PICO_FRAME_PERIOD = 10 /*milliseconds*/ ,
                          PICO_HORIZONTAL_RESOLUTION = 320,
                          PICO_VERTICAL_RESOLUTION   = 480,
                          PICO_SCREEN_ROTATION = /*__UI_PROJECT_ROTATION__*/ 0,
                          PICO_TOUCH_START_X = 300, PICO_TOUCH_START_Y=300, PICO_TOUCH_END_X = 3500, PICO_TOUCH_END_Y = 3500,
                          PICO_TOUCH_ROTATION = /*PICO_SCREEN_ROTATION &*/ 0, PICO_TOUCH_INVERT_X = 0, PICO_TOUCH_INVERT_Y = 1,
                          PICO_SCREENBUFFER_SIZE = (PICO_HORIZONTAL_RESOLUTION * PICO_VERTICAL_RESOLUTION / 10) };

static uint16_t TouchScreen_Calibration_Data[5] = { PICO_TOUCH_START_X, PICO_TOUCH_END_X, PICO_TOUCH_START_Y, PICO_TOUCH_END_Y
                                                        , (PICO_TOUCH_ROTATION)|(PICO_TOUCH_INVERT_X<<1)|(PICO_TOUCH_INVERT_Y<<2) };

static lv_color_t buf [PICO_SCREENBUFFER_SIZE];

static TFT_eSPI TFT_eSPI_screen = TFT_eSPI(PICO_HORIZONTAL_RESOLUTION, PICO_VERTICAL_RESOLUTION); /* TFT instance */

void my_disp_flush( lv_display_t *display, const lv_area_t *area, uint8_t *pixelmap );
void my_touchpad_read( lv_indev_t * indev, lv_indev_data_t * data );

/*Set tick routine needed for LVGL internal timings*/
static uint32_t my_tick_get_cb (void) { return millis(); }

void setup()
{


    stdio_init_all(); //if (cyw43_arch_init()) return -1; //cyw43_arch_gpio_put(BUILTIN_LED,0);

    lv_init();
    TFT_eSPI_screen.begin();
    TFT_eSPI_screen.setRotation( PICO_SCREEN_ROTATION );
    TFT_eSPI_screen.setTouch(TouchScreen_Calibration_Data);

    static lv_disp_t* disp;
    disp = lv_display_create( PICO_HORIZONTAL_RESOLUTION, PICO_VERTICAL_RESOLUTION );
    lv_display_set_buffers( disp, buf, NULL, PICO_SCREENBUFFER_SIZE * sizeof(lv_color_t), LV_DISPLAY_RENDER_MODE_PARTIAL );
    lv_display_set_flush_cb( disp, my_disp_flush );
    lv_display_set_user_data( disp, (void*) &TFT_eSPI_screen );

    static lv_indev_t* indev;
    indev = lv_indev_create();
    lv_indev_set_type( indev, LV_INDEV_TYPE_POINTER );
    lv_indev_set_read_cb( indev, my_touchpad_read );
    lv_indev_set_user_data( indev, (void*) &TFT_eSPI_screen );

    lv_tick_set_cb( my_tick_get_cb );

    ui_init();

}

void setup1()
{

}

void loop()
{
        lv_timer_handler(); // let the GUI do its work
        sleep_ms(PICO_FRAME_PERIOD);
}

void loop1()
{

}

/* Display flushing */
void my_disp_flush( lv_display_t *display, const lv_area_t *area, uint8_t *pixelmap )
{
    static TFT_eSPI * TFT_eSPI_ptr;

    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    if (LV_COLOR_16_SWAP) {
        size_t len = lv_area_get_size( area );
        lv_draw_sw_rgb565_swap( pixelmap, len );
    }

    TFT_eSPI_ptr = (TFT_eSPI*) lv_display_get_user_data( display );
    TFT_eSPI_ptr->startWrite();
    TFT_eSPI_ptr->setAddrWindow( area->x1, area->y1, w, h );
    TFT_eSPI_ptr->pushColors( ( uint16_t * )pixelmap, w * h, true );
    TFT_eSPI_ptr->endWrite();

    lv_disp_flush_ready( display );
}

/*Read the touchpad*/
void my_touchpad_read( lv_indev_t * indev, lv_indev_data_t * data )
{
    static TFT_eSPI * TFT_eSPI_ptr;
    uint16_t touchX = 0, touchY = 0;

    TFT_eSPI_ptr = (TFT_eSPI*) lv_indev_get_user_data( indev );
    bool touched = TFT_eSPI_ptr->getTouch( &touchX, &touchY, 600 );

    if( !touched )
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->state = LV_INDEV_STATE_PR;

        /*Set the coordinates*/
        data->point.x = touchX;
        data->point.y = touchY;
    }
}

