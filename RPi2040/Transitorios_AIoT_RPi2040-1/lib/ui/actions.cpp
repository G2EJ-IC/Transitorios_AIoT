#include <Arduino.h>

/** 
* @brief : Función Similar a cout << de C++, Debe estar despues de #include <Arduino.h> para que funcione.
* @param : T.
* @return : obj.
*/
template<class T>
inline Print &operator <<(Print &obj, T arg) { 
    obj.print(arg); 
    return obj; 
}

#include "actions.h"
#include "screens.h"
#include "vars.h"

// #include "ConectarWiFi_AIoT.h"

int counter;
// WiFi_AIoT wifi_AIoT;

extern void action_fn_connec(lv_event_t * e)
{
	// int opcion = lv_dropdown_get_selected(objects.drop_down_1);
	// wifi_AIoT.ConectarWiFi_AIoT((int)opcion);
	// if (WiFi.status() == WL_CONNECTED) {
	// 	lv_label_set_text(objects.ui_lab_ssid, wifi_AIoT.get_AIoT_SSID().c_str());
	// 	lv_label_set_text(objects.ui_lab_ip, wifi_AIoT.get_AIoT_IP().c_str());
	// 	lv_label_set_text(objects.ui_lab_dns, wifi_AIoT.get_AIoT_DNS().c_str());
	// 	lv_label_set_text(objects.ui_lab_mac, wifi_AIoT.get_AIoT_MAC().c_str());
		lv_obj_set_style_bg_color(objects.bt_conectado_main3_tab1, lv_color_hex(0x008000), LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_obj_set_style_bg_color(objects.bt_conectado_main3_tab2, lv_color_hex(0x008000), LV_PART_MAIN | LV_STATE_DEFAULT);
	// } else {
	// 	lv_label_set_text(objects.ui_lab_ssid, "Nombre WiFi (SSID)");
	// 	lv_label_set_text(objects.ui_lab_ip, "xx.xx.xx.xx");
	// 	lv_label_set_text(objects.ui_lab_dns, "xx.xx.xx.xx");
	// 	lv_label_set_text(objects.ui_lab_mac, "xx:xx:xx:xx:xx:xx");
	//  lv_obj_set_style_bg_color(objects.bt_conectado_main3_tab1, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	//  lv_obj_set_style_bg_color(objects.bt_conectado_main3_tab2, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	// }
}

extern void action_fn_re_scan(lv_event_t * e)
{
	lv_label_set_text(objects.ui_lab_ssid, "Nombre WiFi (SSID)");
	lv_label_set_text(objects.ui_lab_ip, "xx.xx.xx.xx");
	lv_label_set_text(objects.ui_lab_dns, "xx.xx.xx.xx");
	lv_label_set_text(objects.ui_lab_mac, "xx:xx:xx:xx:xx:xx");
	lv_obj_set_style_bg_color(objects.bt_conectado_main3_tab1, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(objects.bt_conectado_main3_tab2, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
	// wifi_AIoT.DisconnectWiFi_AIoT();
}



