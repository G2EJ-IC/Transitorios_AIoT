#ifndef __IO_SERVICE_H__
#define __IO_SERVICE_H__

#define ICACHE_FLASH_ATTR

class io_service
{
private:
    friend class display_service;
    // friend class io_service;
    friend class tp_service;
    // friend class dhms_AIoT;    

public:
    io_service();
    ~io_service();

    void setPin32(bool);
    void ParpadeoLED(void);
    void TestHWM(const char *, uint32_t);
    void memoria_ESP(void);
    void setup();
    void loop();
    void cronometro(uint32_t);
    uint32_t suspender(void); 
};

#endif // __IO_SERVICE_H__
