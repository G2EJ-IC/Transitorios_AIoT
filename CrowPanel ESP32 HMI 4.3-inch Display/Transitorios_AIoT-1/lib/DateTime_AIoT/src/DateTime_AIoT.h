#ifndef __SRC_DATETIME_AIOT_H__
#define __SRC_DATETIME_AIOT_H__

#ifdef __cplusplus
extern "C" {
#endif

class dhms_AIoT
{
private:

public:
    dhms_AIoT();
    ~dhms_AIoT();
    String DHMS_AIoT_get(unsigned long long);     
};

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif // __SRC_DATETIME_AIOT_H__