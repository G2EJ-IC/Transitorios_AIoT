#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main1;
    lv_obj_t *main3;
    lv_obj_t *main2;
    lv_obj_t *bt_conectado_3;
    lv_obj_t *bt_connec_wi_fi_main3;
    lv_obj_t *bt_dhms_1;
    lv_obj_t *bt_dhms_2;
    lv_obj_t *bt_re_scan_wi_fi_main3;
    lv_obj_t *btn_counter;
    lv_obj_t *btu_minus;
    lv_obj_t *but_plus;
    lv_obj_t *container_label;
    lv_obj_t *container_resultados;
    lv_obj_t *drop_down_1;
    lv_obj_t *drop_down_suspender;
    lv_obj_t *img_der_pag1_main3_1;
    lv_obj_t *img_der_pag1_main3_2;
    lv_obj_t *img_der_pag2;
    lv_obj_t *img_der_pag2_main1;
    lv_obj_t *img_der_pag3_main2;
    lv_obj_t *img_izq_pag1_main2;
    lv_obj_t *img_izq_pag2_main3_1;
    lv_obj_t *img_izq_pag2_main3_2;
    lv_obj_t *img_ud_fjd_c_58x77;
    lv_obj_t *keyboard;
    lv_obj_t *lab_suspender_counter;
    lv_obj_t *label_dhms_1;
    lv_obj_t *label_dhms_2;
    lv_obj_t *label_direccion_dns;
    lv_obj_t *label_direccion_ip;
    lv_obj_t *label_direccion_mac;
    lv_obj_t *label_red_wi_fi_ssid;
    lv_obj_t *label_wi_fi_pass_pag1;
    lv_obj_t *label_wi_fi_ssid_pag1;
    lv_obj_t *pag2;
    lv_obj_t *pag3;
    lv_obj_t *panel_aio_t;
    lv_obj_t *panel_nombre;
    lv_obj_t *panel02_1;
    lv_obj_t *panel02_2;
    lv_obj_t *panel02_3;
    lv_obj_t *panel03_3;
    lv_obj_t *panel03_4;
    lv_obj_t *panel03_5;
    lv_obj_t *tab_view_main2;
    lv_obj_t *text_area_password;
    lv_obj_t *ui_lab_dns;
    lv_obj_t *ui_lab_ip;
    lv_obj_t *ui_lab_mac;
    lv_obj_t *ui_lab_ssid;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN1 = 1,
    SCREEN_ID_MAIN3 = 2,
    SCREEN_ID_MAIN2 = 3,
};

void create_screen_main1();
void tick_screen_main1();

void create_screen_main3();
void tick_screen_main3();

void create_screen_main2();
void tick_screen_main2();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/