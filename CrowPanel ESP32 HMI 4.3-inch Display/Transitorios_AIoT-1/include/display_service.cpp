#include <Arduino.h>
#include <lvgl.h>
#include "config.h"
#include <SPI.h>
#include "LovyanGFX_Class_CrowPanel.h"

#include "display_service.h"
#include "io_service.h"
#include "tp_service.h"

#include "esp_freertos_hooks.h"
#include "ui.h"

static LGFX tft;            // load tft service
extern tp_service tp;       // load tp service
extern io_service io_tp;    // load IO control service

display_service::display_service() {}
display_service::~display_service() {}

/* #define DISP_STATE_INIT_WAIT_TIME (2000u)
#define DISP_STATE_WIFI_SSID_SCANNED_DONE_TIME (1000u)
#define WIFI_CONNECT_MAX_RETRY (5u)

/*Change to your screen resolution*/

static const uint16_t N = 15u; // N = {10, 12, 15, 16, 20, 24, 25, 32}

enum { SCREENBUFFER_SIZE_PIXELS = (TFT_WIDTH * TFT_HEIGHT / N) * (LV_COLOR_DEPTH / 8) };
static lv_color_t buf [SCREENBUFFER_SIZE_PIXELS];
uint32_t draw_buf[SCREENBUFFER_SIZE_PIXELS / 4];

/*LVGL draw into this buffer, 1/10 screen size usually works well. The size is in bytes*/
unsigned long lastTickMillis = 0;

static lv_display_t *disp;

#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))

/*Set tick routine needed for LVGL internal timings*/
inline static uint32_t my_tick_get_cb (void){ return millis(); }

#if LV_USE_LOG != 0
    /* Serial debugging */
    void my_print(const char *buf1)
    {
        Serial.printf(buf1);
        Serial.flush();
    }
#endif 

/* =============================icache functions========================= */
void ICACHE_FLASH_ATTR display_service::lv_setup()
{
    lv_init();
    tft.begin();                /* TFT init */
    tft.setRotation(ROTATION);  /* Landscape orientation, flipped */
    String LVGL_Arduino = "Hello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
    Serial.println(LVGL_Arduino);
    Serial.println("I am LVGL_Arduino");

#if LV_USE_LOG != 0
    lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif
}

void ICACHE_FLASH_ATTR display_service::touch_setup()
{
    tp.setup();         /* TFT setup*/
    Serial.begin(115200); /* prepare for possible serial debug */

    //************************************************************************************************
    // tft.setBrightness(255);
    // uint16_t calData[] = { 120, 3120, 170, 170, 4880, 3030, 4770, 50};
    uint16_t calData[] = {239, 3926, 233, 265, 3856, 3896, 3714, 308};
    tft.setTouchCalibrate(calData);
    lv_init();
    //************************************************************************************************

    String LVGL_Arduino = "Hello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

    Serial.println( LVGL_Arduino );
    Serial.println( "I am LVGL_Arduino" );

    lv_init();

#if LV_USE_LOG != 0
    lv_log_register_print_cb( my_print ); /* register print function for debugging */
#endif

    tft.begin();          /* TFT init */
    tft.setRotation( 3 ); /* Landscape orientation, flipped */

    static lv_disp_t* disp;
    disp = lv_display_create( TFT_WIDTH, TFT_HEIGHT );
    lv_display_set_buffers( disp, buf, NULL, SCREENBUFFER_SIZE_PIXELS * sizeof(lv_color_t), LV_DISPLAY_RENDER_MODE_PARTIAL );
    lv_display_set_flush_cb( disp, my_disp_flush );

    static lv_indev_t* indev;
    indev = lv_indev_create();
    lv_indev_set_type( indev, LV_INDEV_TYPE_POINTER );
    lv_indev_set_read_cb( indev, my_touchpad_read );

    lv_tick_set_cb( my_tick_get_cb );

    ui_init();

    Serial.println( "Setup done" );
}

void IRAM_ATTR display_service::lv_main()
{
    Serial.print(F("[INFO] LV GUI started.\n"));
    // header_create();
    // body_create();
}

/* Display flushing */
// void my_disp_flush( lv_display_t *disp, const lv_area_t *area, uint8_t * px_map)
void display_service::my_disp_flush (lv_display_t *disp, const lv_area_t *area, uint8_t *pixelmap)
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    if (LV_COLOR_16_SWAP) {
        size_t len = lv_area_get_size( area );
        lv_draw_sw_rgb565_swap( pixelmap, len );
    }

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h);
    tft.pushColors( (uint16_t*) pixelmap, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp );
}

/*Read the touchpad*/
void display_service::my_touchpad_read (lv_indev_t * indev_driver, lv_indev_data_t * data)
{
    uint16_t touchX = 0, touchY = 0;

    // bool touched = false;//tft.getTouch(&touchX, &touchY, 600);
    bool touched = tft.getTouch(&touchX, &touchY);

    if (!touched)
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->state = LV_INDEV_STATE_PR;

        /*Set the coordinates*/
        data->point.x = touchX;
        data->point.y = touchY;

        Serial.print( "Data x " );
        Serial.println( touchX );

        Serial.print( "Data y " );
        Serial.println( touchY );
    }
}

/* =============================iram functions=============================== */
void ICACHE_FLASH_ATTR display_service::setup()
{
    lv_setup();
    // esp_register_freertos_tick_hook(lv_tick_task);

    Serial.print(F("[INFO] Display GUI setup finished! \n"));
    touch_setup();
    // lv_main();
} // end display service setup

void IRAM_ATTR display_service::loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    ui_tick();
    vTaskDelay(pdMS_TO_TICKS(5)); // delay( 5 );
} // end loop */
