#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main1_img_der_pag2_main1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_main3_img_izq_pag2_main3_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_main3_bt_connec_wi_fi_main3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_fn_connec(e);
    }
}

static void event_handler_cb_main3_bt_re_scan_wi_fi_main3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        action_fn_re_scan(e);
    }
}

static void event_handler_cb_main3_img_der_pag1_main3_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 14, 0, e);
    }
}

static void event_handler_cb_main3_img_izq_pag2_main3_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 25, 0, e);
    }
}

static void event_handler_cb_main3_img_der_pag1_main3_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 29, 0, e);
    }
}

static void event_handler_cb_main2_img_izq_pag1_main2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_main2_slider_porcentaje(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            if (tick_value_change_obj != ta) {
                assignIntegerProperty(flowState, 7, 3, value, "Failed to assign Value in Slider widget");
            }
        }
    }
}

static void event_handler_cb_main2_img_der_pag3_main2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

void create_screen_main1() {
    void *flowState = getFlowState(0, 0);
    lv_obj_t *obj = lv_obj_create(0);
    objects.main1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 272);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Container_Main1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.container_main1 = obj;
            lv_obj_set_pos(obj, LV_PCT(2), LV_PCT(2));
            lv_obj_set_size(obj, LV_PCT(96), LV_PCT(96));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Panel_AIoT
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.panel_aio_t = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, -9, -18);
                            lv_obj_set_size(obj, 443, 77);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // Img_ud_FJdC_58x77
                                    lv_obj_t *obj = lv_img_create(parent_obj);
                                    objects.img_ud_fjd_c_58x77 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 58, 77);
                                    lv_img_set_src(obj, &img_ud_fjd_c_058x077);
                                    lv_img_set_pivot(obj, 0, 0);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_ADV_HITTEST|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                                }
                                {
                                    // PanelNombre
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.panel_nombre = obj;
                                    lv_obj_set_pos(obj, 62, 15);
                                    lv_obj_set_size(obj, 320, 50);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(115), LV_PCT(250));
                                            lv_label_set_text(obj, "ERNESTO JOSE GUERRERO GONZALEZ\nAIoT Transitorios Hidraulicos");
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                    }
                                }
                                {
                                    // ButImgDerPag2_Main1
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.but_img_der_pag2_main1 = obj;
                                    lv_obj_set_pos(obj, 385, 0);
                                    lv_obj_set_size(obj, 58, 77);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // ImgDerPag2_Main1
                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                            objects.img_der_pag2_main1 = obj;
                                            lv_obj_set_pos(obj, 13, 23);
                                            lv_obj_set_size(obj, 32, 32);
                                            lv_obj_add_event_cb(obj, event_handler_cb_main1_img_der_pag2_main1, LV_EVENT_ALL, flowState);
                                            lv_obj_set_style_radius(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj0 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text(obj, "");
                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            lv_obj_set_pos(obj, 96, 67);
                            lv_obj_set_size(obj, 235, 157);
                            lv_img_set_src(obj, &img_aio_t_235x157);
                            lv_img_set_pivot(obj, 0, 0);
                        }
                    }
                }
            }
        }
    }
    
    tick_screen_main1();
}

void tick_screen_main1() {
    void *flowState = getFlowState(0, 0);
    {
        const char *new_val = evalTextProperty(flowState, 9, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj0);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj0;
            lv_label_set_text(objects.obj0, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_main3() {
    void *flowState = getFlowState(0, 1);
    lv_obj_t *obj = lv_obj_create(0);
    objects.main3 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 272);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Container_Main3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.container_main3 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 272);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // TabViewMain2
                    lv_obj_t *obj = lv_tabview_create(parent_obj);
                    lv_tabview_set_tab_bar_position(obj, LV_DIR_TOP);
                    lv_tabview_set_tab_bar_size(obj, 30);
                    objects.tab_view_main2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 480, 272);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Pag2
                            lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Connec To WiFi");
                            objects.pag2 = obj;
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, -16, -16);
                                    lv_obj_set_size(obj, 480, 245);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // Panel02_3
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.panel02_3 = obj;
                                            lv_obj_set_pos(obj, LV_PCT(2), 2);
                                            lv_obj_set_size(obj, LV_PCT(96), LV_PCT(18));
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ImgIzqPag2_Main3.1
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.img_izq_pag2_main3_1 = obj;
                                                    lv_obj_set_pos(obj, LV_PCT(0), -12);
                                                    lv_obj_set_size(obj, 32, 32);
                                                    lv_obj_add_event_cb(obj, event_handler_cb_main3_img_izq_pag2_main3_1, LV_EVENT_ALL, flowState);
                                                    lv_obj_set_style_radius(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.obj1 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "");
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_transform_rotation(obj, 1800, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_transform_pivot_x(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_transform_pivot_y(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                                {
                                                    // Bt_Connec_WiFi_Main3
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.bt_connec_wi_fi_main3 = obj;
                                                    lv_obj_set_pos(obj, 74, -11);
                                                    lv_obj_set_size(obj, LV_PCT(25), 30);
                                                    lv_obj_add_event_cb(obj, event_handler_cb_main3_bt_connec_wi_fi_main3, LV_EVENT_ALL, flowState);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 9, -3);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "Connec");
                                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                                {
                                                    // Bt_Conectado_Main3_Tab1
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.bt_conectado_main3_tab1 = obj;
                                                    lv_obj_set_pos(obj, 196, -12);
                                                    lv_obj_set_size(obj, 32, 32);
                                                    lv_obj_set_style_radius(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.obj2 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "");
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                                {
                                                    // Bt_Re-Scan_WiFi_Main3
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.bt_re_scan_wi_fi_main3 = obj;
                                                    lv_obj_set_pos(obj, 242, -11);
                                                    lv_obj_set_size(obj, LV_PCT(25), 30);
                                                    lv_obj_add_event_cb(obj, event_handler_cb_main3_bt_re_scan_wi_fi_main3, LV_EVENT_ALL, flowState);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 8, -3);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "Re-Scan");
                                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                                {
                                                    // ImgDerPag1_Main3.1
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.img_der_pag1_main3_1 = obj;
                                                    lv_obj_set_pos(obj, LV_PCT(93), -12);
                                                    lv_obj_set_size(obj, 32, 32);
                                                    lv_obj_add_event_cb(obj, event_handler_cb_main3_img_der_pag1_main3_1, LV_EVENT_ALL, flowState);
                                                    lv_obj_set_style_radius(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.obj3 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "");
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            // Panel03_4
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.panel03_4 = obj;
                                            lv_obj_set_pos(obj, LV_PCT(2), 50);
                                            lv_obj_set_size(obj, LV_PCT(96), LV_PCT(77));
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // Label_WiFi_SSID_Pag1
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.label_wi_fi_ssid_pag1 = obj;
                                                    lv_obj_set_pos(obj, -177, -70);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                                                    lv_label_set_text(obj, "WiFi (SSID).:");
                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                }
                                                {
                                                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                                    lv_obj_set_pos(obj, 127, -14);
                                                    lv_obj_set_size(obj, 307, 40);
                                                    lv_dropdown_set_options(obj, "");
                                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                }
                                                {
                                                    // Label_WiFi_Pass_Pag1
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.label_wi_fi_pass_pag1 = obj;
                                                    lv_obj_set_pos(obj, -161, -28);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                                                    lv_label_set_text(obj, "WiFi Passwords.:");
                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                }
                                                {
                                                    // TextAreaPassword
                                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                                    objects.text_area_password = obj;
                                                    lv_obj_set_pos(obj, 127, 28);
                                                    lv_obj_set_size(obj, 307, 40);
                                                    lv_textarea_set_max_length(obj, 128);
                                                    lv_textarea_set_placeholder_text(obj, "Enter Passwords");
                                                    lv_textarea_set_one_line(obj, false);
                                                    lv_textarea_set_password_mode(obj, true);
                                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                }
                                                {
                                                    // Keyboard
                                                    lv_obj_t *obj = lv_keyboard_create(parent_obj);
                                                    objects.keyboard = obj;
                                                    lv_obj_set_pos(obj, -12, 68);
                                                    lv_obj_set_size(obj, 449, 100);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // Pag3
                            lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "AIoT Transitorios");
                            objects.pag3 = obj;
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, -16, -16);
                                    lv_obj_set_size(obj, 480, 245);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // Panel02_2
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.panel02_2 = obj;
                                            lv_obj_set_pos(obj, LV_PCT(2), 2);
                                            lv_obj_set_size(obj, LV_PCT(96), LV_PCT(18));
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ImgIzqPag2_Main3.2
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.img_izq_pag2_main3_2 = obj;
                                                    lv_obj_set_pos(obj, LV_PCT(0), -12);
                                                    lv_obj_set_size(obj, 32, 32);
                                                    lv_obj_add_event_cb(obj, event_handler_cb_main3_img_izq_pag2_main3_2, LV_EVENT_ALL, flowState);
                                                    lv_obj_set_style_radius(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.obj4 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "");
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_transform_rotation(obj, 1800, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_transform_pivot_x(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_transform_pivot_y(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                                {
                                                    // Bt_Conectado_Main3_Tab2
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.bt_conectado_main3_tab2 = obj;
                                                    lv_obj_set_pos(obj, 196, -12);
                                                    lv_obj_set_size(obj, 32, 32);
                                                    lv_obj_set_style_radius(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.obj5 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "");
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                                {
                                                    // ImgDerPag1_Main3.2
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.img_der_pag1_main3_2 = obj;
                                                    lv_obj_set_pos(obj, LV_PCT(93), -12);
                                                    lv_obj_set_size(obj, 32, 32);
                                                    lv_obj_add_event_cb(obj, event_handler_cb_main3_img_der_pag1_main3_2, LV_EVENT_ALL, flowState);
                                                    lv_obj_set_style_radius(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.obj6 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "");
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            // Panel03_5
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.panel03_5 = obj;
                                            lv_obj_set_pos(obj, LV_PCT(2), 50);
                                            lv_obj_set_size(obj, LV_PCT(96), LV_PCT(77));
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ContainerLabel
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.container_label = obj;
                                                    lv_obj_set_pos(obj, -16, -18);
                                                    lv_obj_set_size(obj, 130, 188);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // Label_Red_WiFi_SSID
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.label_red_wi_fi_ssid = obj;
                                                            lv_obj_set_pos(obj, LV_PCT(5), LV_PCT(15));
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "Red WiFi (SSID).:");
                                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                        {
                                                            // Label_Direccion_IP
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.label_direccion_ip = obj;
                                                            lv_obj_set_pos(obj, LV_PCT(5), LV_PCT(35));
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "Direccion IP.:");
                                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                        {
                                                            // Label_Direccion_DNS
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.label_direccion_dns = obj;
                                                            lv_obj_set_pos(obj, 5, LV_PCT(55));
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "Direccion DNS.:");
                                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                        {
                                                            // Label_Direccion_MAC
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.label_direccion_mac = obj;
                                                            lv_obj_set_pos(obj, LV_PCT(5), LV_PCT(75));
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "Direccion MAC.:");
                                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                                {
                                                    // ContainerResultados
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.container_resultados = obj;
                                                    lv_obj_set_pos(obj, 114, -18);
                                                    lv_obj_set_size(obj, 328, 188);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_LabSSID
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_lab_ssid = obj;
                                                            lv_obj_set_pos(obj, LV_PCT(5), LV_PCT(15));
                                                            lv_obj_set_size(obj, 295, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "Nombre WiFi (SSID).");
                                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                        {
                                                            // ui_LabIP
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_lab_ip = obj;
                                                            lv_obj_set_pos(obj, LV_PCT(5), LV_PCT(35));
                                                            lv_obj_set_size(obj, 140, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "xx.xx.xx.xx");
                                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                        {
                                                            // ui_LabMAC
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_lab_mac = obj;
                                                            lv_obj_set_pos(obj, LV_PCT(5), LV_PCT(55));
                                                            lv_obj_set_size(obj, 140, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "xx:xx:xx:xx:xx:xx");
                                                            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                        {
                                                            // ui_LabDNS
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_lab_dns = obj;
                                                            lv_obj_set_pos(obj, LV_PCT(5), LV_PCT(75));
                                                            lv_obj_set_size(obj, 140, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "xx.xx.xx.xx");
                                                            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 10, 111);
                                            lv_obj_set_size(obj, 460, 126);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_img_create(parent_obj);
                                                    lv_obj_set_pos(obj, 386, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_img_set_src(obj, &img_ud_fjd_c_058x077);
                                                    lv_img_set_pivot(obj, 0, 0);
                                                }
                                                {
                                                    // Bt_DHMS_2
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.bt_dhms_2 = obj;
                                                    lv_obj_set_pos(obj, 239, 86);
                                                    lv_obj_set_size(obj, 200, 30);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // LabelDHMS_2
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.label_dhms_2 = obj;
                                                            lv_obj_set_pos(obj, 0, -1);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text(obj, "00d 00h 00m 00.000s");
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    lv_keyboard_set_textarea(objects.keyboard, objects.text_area_password);
    
    tick_screen_main3();
}

void tick_screen_main3() {
    void *flowState = getFlowState(0, 1);
    {
        const char *new_val = evalTextProperty(flowState, 7, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj1;
            lv_label_set_text(objects.obj1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 11, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj2;
            lv_label_set_text(objects.obj2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 15, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj3;
            lv_label_set_text(objects.obj3, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 26, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj4);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj4;
            lv_label_set_text(objects.obj4, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 28, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj5);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj5;
            lv_label_set_text(objects.obj5, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 30, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj6);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj6;
            lv_label_set_text(objects.obj6, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_main2() {
    void *flowState = getFlowState(0, 2);
    lv_obj_t *obj = lv_obj_create(0);
    objects.main2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 272);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Container_Main2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.container_main2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 480, 272);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 480, 32);
                    lv_label_set_text(obj, "AIoT Transitorios Hidraulicos");
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 30);
                    lv_obj_set_size(obj, 480, 242);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Panel02_1
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.panel02_1 = obj;
                            lv_obj_set_pos(obj, LV_PCT(2), 2);
                            lv_obj_set_size(obj, LV_PCT(96), LV_PCT(18));
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // ImgIzqPag1_Main2
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.img_izq_pag1_main2 = obj;
                                    lv_obj_set_pos(obj, LV_PCT(0), -12);
                                    lv_obj_set_size(obj, 32, 32);
                                    lv_obj_add_event_cb(obj, event_handler_cb_main2_img_izq_pag1_main2, LV_EVENT_ALL, flowState);
                                    lv_obj_set_style_radius(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj7 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "");
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_transform_rotation(obj, 1800, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_transform_pivot_x(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_transform_pivot_y(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                    }
                                }
                                {
                                    // SliderPorcentaje
                                    lv_obj_t *obj = lv_slider_create(parent_obj);
                                    objects.slider_porcentaje = obj;
                                    lv_obj_set_pos(obj, 64, -7);
                                    lv_obj_set_size(obj, LV_PCT(70), 10);
                                    lv_slider_set_range(obj, 10, 100);
                                    lv_obj_add_event_cb(obj, event_handler_cb_main2_slider_porcentaje, LV_EVENT_ALL, flowState);
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 195, 4);
                                    lv_obj_set_size(obj, 35, LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // LabelSliderPorcentaje
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.label_slider_porcentaje = obj;
                                            lv_obj_set_pos(obj, 0, 1);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "");
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 23, 1);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "%");
                                        }
                                    }
                                }
                                {
                                    // ImgDerPag3_Main2
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.img_der_pag3_main2 = obj;
                                    lv_obj_set_pos(obj, LV_PCT(93), -12);
                                    lv_obj_set_size(obj, 32, 32);
                                    lv_obj_add_event_cb(obj, event_handler_cb_main2_img_der_pag3_main2, LV_EVENT_ALL, flowState);
                                    lv_obj_set_style_radius(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj8 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "");
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // Panel03_3
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.panel03_3 = obj;
                            lv_obj_set_pos(obj, LV_PCT(2), 49);
                            lv_obj_set_size(obj, LV_PCT(96), LV_PCT(77));
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc8c8c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // DropDown
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.drop_down = obj;
                                    lv_obj_set_pos(obj, 7, -18);
                                    lv_obj_set_size(obj, 410, 65);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // Suspender
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.suspender = obj;
                                            lv_obj_set_pos(obj, 0, 5);
                                            lv_obj_set_size(obj, 200, 60);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 200, 20);
                                                    lv_label_set_text(obj, "Suspender");
                                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                }
                                                {
                                                    // DropDown_Suspender
                                                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                                    objects.drop_down_suspender = obj;
                                                    lv_obj_set_pos(obj, 0, 20);
                                                    lv_obj_set_size(obj, 200, 40);
                                                    lv_dropdown_set_options(obj, "15 Segundos\n30 Segundos\n1  minuto\n2  minuto\n5  minuto\n10 minuto");
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                }
                                            }
                                        }
                                        {
                                            // Método de Conección
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.m_todo_de_conecci_n = obj;
                                            lv_obj_set_pos(obj, 213, 5);
                                            lv_obj_set_size(obj, 200, 60);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 200, 20);
                                                    lv_label_set_text(obj, "Metodo de Coneccion");
                                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                }
                                                {
                                                    // DropDown_1
                                                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                                    objects.drop_down_1 = obj;
                                                    lv_obj_set_pos(obj, 0, 20);
                                                    lv_obj_set_size(obj, 200, 40);
                                                    lv_dropdown_set_options(obj, "WiFi Multi\nWiFi Manager");
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, -18, 47);
                                    lv_obj_set_size(obj, 460, 131);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // Bt_DHMS_1
                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                            objects.bt_dhms_1 = obj;
                                            lv_obj_set_pos(obj, 22, 76);
                                            lv_obj_set_size(obj, 200, 30);
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // LabelDHMS_1
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.label_dhms_1 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text(obj, "00d 00h 00m 00.000s");
                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_img_create(parent_obj);
                                            lv_obj_set_pos(obj, 377, 27);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_img_set_src(obj, &img_ud_fjd_c_058x077);
                                            lv_img_set_pivot(obj, 0, 0);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    tick_screen_main2();
}

void tick_screen_main2() {
    void *flowState = getFlowState(0, 2);
    {
        const char *new_val = evalTextProperty(flowState, 6, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj7);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj7;
            lv_label_set_text(objects.obj7, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 7, 3, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.slider_porcentaje);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_porcentaje;
            lv_slider_set_value(objects.slider_porcentaje, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 9, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_slider_porcentaje);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_slider_porcentaje;
            lv_label_set_text(objects.label_slider_porcentaje, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj8);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj8;
            lv_label_set_text(objects.obj8, new_val);
            tick_value_change_obj = NULL;
        }
    }
}


static const char *screen_names[] = { "Main1", "Main3", "Main2" };
static const char *object_names[] = { "main1", "main3", "main2", "img_der_pag2_main1", "img_izq_pag2_main3_1", "bt_connec_wi_fi_main3", "bt_re_scan_wi_fi_main3", "img_der_pag1_main3_1", "img_izq_pag2_main3_2", "img_der_pag1_main3_2", "img_izq_pag1_main2", "slider_porcentaje", "img_der_pag3_main2", "container_main1", "panel_aio_t", "img_ud_fjd_c_58x77", "panel_nombre", "but_img_der_pag2_main1", "obj0", "container_main3", "tab_view_main2", "pag2", "panel02_3", "bt_conectado_main3_tab1", "panel03_4", "label_wi_fi_ssid_pag1", "label_wi_fi_pass_pag1", "text_area_password", "keyboard", "pag3", "panel02_2", "bt_conectado_main3_tab2", "panel03_5", "container_label", "label_red_wi_fi_ssid", "label_direccion_ip", "label_direccion_dns", "label_direccion_mac", "container_resultados", "ui_lab_ssid", "ui_lab_ip", "ui_lab_mac", "ui_lab_dns", "bt_dhms_2", "label_dhms_2", "obj1", "obj2", "obj3", "obj4", "obj5", "obj6", "container_main2", "panel02_1", "label_slider_porcentaje", "panel03_3", "drop_down", "suspender", "drop_down_suspender", "m_todo_de_conecci_n", "drop_down_1", "bt_dhms_1", "label_dhms_1", "obj7", "obj8" };


typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main1,
    tick_screen_main3,
    tick_screen_main2,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main1();
    create_screen_main3();
    create_screen_main2();
}
