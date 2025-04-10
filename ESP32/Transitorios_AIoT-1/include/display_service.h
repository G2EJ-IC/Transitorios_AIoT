#ifndef __DISPLAY_SERVICE_H__
#define __DISPLAY_SERVICE_H__

#define ICACHE_FLASH_ATTR

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

class display_service
{
private:
    void ICACHE_FLASH_ATTR lv_setup();
    void ICACHE_FLASH_ATTR touch_setup();
    void IRAM_ATTR lv_main();
    static void IRAM_ATTR my_disp_flush (lv_display_t *disp, const lv_area_t *area, uint8_t *pixelmap);
    static void IRAM_ATTR my_touchpad_read (lv_indev_t * indev_driver, lv_indev_data_t * data);

    // friend class display_service;
    friend class io_service;
    friend class tp_service;
    
public:
    display_service();
    ~display_service();
    void IRAM_ATTR setup();
    void IRAM_ATTR loop();
};

#ifdef __cplusplus
}
#endif

#endif // __DISPLAY_SERVICE_H__