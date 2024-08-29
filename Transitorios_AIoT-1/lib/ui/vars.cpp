#include <Arduino.h>

#include <stdio.h>
#include <lvgl.h>

#include "vars.h"
#include "screens.h"
#include "structs.h"
#include "ui.h"

int32_t selected_item_index = 100;

extern int32_t get_var_slider_porcentaje()
{
    return selected_item_index;
}
extern void set_var_slider_porcentaje(int32_t value)
{
    selected_item_index = value;
}

extern bool get_var_connec()
{
    return true;
}

extern void set_var_connec(bool value)
{

}

extern bool get_var_re_scan()
{
    return true;
}

extern void set_var_re_scan(bool value)
{

}