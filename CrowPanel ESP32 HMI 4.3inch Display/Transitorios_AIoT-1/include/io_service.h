#ifndef __IO_SERVICE_H__
#define __IO_SERVICE_H__

#ifdef __cplusplus
extern "C" {
#endif

class io_service
{
private:
    friend class display_service;
    // friend class io_service;
    friend class tp_service;
    // friend class dhms_AIoT;
    
    const int _pwmChannel  = 0;     // 0-15
    const int _frecuencia = 10000;  // en Hz
    const int _resolucion = 8;      // 8-16 bits de resolución.

public:
    io_service();
    ~io_service();

    void setPinBL(bool);
    void setOpacity(uint32_t);
    void TestHWM(const char *, uint32_t);
    void setup();
    void loop();
    void cronometro(uint32_t);
    uint32_t suspender(void);    
};

#ifdef __cplusplus
}
#endif

#endif // __IO_SERVICE_H__
