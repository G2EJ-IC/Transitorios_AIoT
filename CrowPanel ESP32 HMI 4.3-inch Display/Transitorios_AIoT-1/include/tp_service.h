#ifndef __TP_SERVICE_H__
#define __TP_SERVICE_H__

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif
class tp_service
{
private:
    friend class display_service;
    friend class io_service;
    // friend class dhms_AIoT;
    // friend class tp_service;
    
public:
    tp_service();
    ~tp_service();

    void setup();
    void loop();
    
    // void lv_no_sleep(uint32_t);
    void lv_no_sleep(uint32_t);
};

#ifdef __cplusplus
}
#endif

#endif // __TP_SERVICE_H__