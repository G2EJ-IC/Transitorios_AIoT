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

int counter;

//*****************************************************************//
extern void action_fn_pagina_1_uno(lv_event_t * e)
{
	lv_scr_load(objects.pag1);
}

extern void action_fn_pagina_2_dos(lv_event_t * e)
{
	lv_scr_load(objects.pag2);
}

extern void action_fn_pagina_3_tres(lv_event_t * e)
{	
	lv_scr_load(objects.pag3);
}

//*****************************************************************//
extern void action_fn_conectar_wi_fi(lv_event_t * e)
{

}

extern void action_fn_desconectar_wi_fi(lv_event_t * e)
{

}

extern void action_fn_rescan_wi_fi(lv_event_t * e)
{
	
}



