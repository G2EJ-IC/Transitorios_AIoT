// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: button_blue

#include "ui.h"

void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button1 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button1, 100);
    lv_obj_set_height(ui_Button1, 104);
    lv_obj_set_x(ui_Button1, -85);
    lv_obj_set_y(ui_Button1, -4);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button2 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button2, 100);
    lv_obj_set_height(ui_Button2, 166);
    lv_obj_set_x(ui_Button2, 79);
    lv_obj_set_y(ui_Button2, -3);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);

}