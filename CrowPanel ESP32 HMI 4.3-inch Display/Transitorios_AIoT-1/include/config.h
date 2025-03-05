//////////////////////////////////////////////////////////////////////////
/*
	ESP32 | LVGL9.2.2 | Ep 0. GFX Setup (ft. LovyanGFX)
	Developing Embedded GUI with EEZ Studio
	Configuración de config.h
	Created by That Project
*/
//////////////////////////////////////////////////////////////////////////
/*
	Modificado: Ernesto José Guerrero González, Civil Engineering ud FJdC.
*/
//////////////////////////////////////////////////////////////////////////

#ifndef __CONFIG_H__
#define __CONFIG_H__

#define VERSION "0.0.0.4" 				//version number
#define _DEBUG_           				//debug switch
#define DEV_TYPE "CrowPanel 4.3 inch"
#define LVGL_TICK_PERIOD 10 			//lvgl tick period
#define ROTATION 0          			//set ui rotation
#define TOUCHPAD 						//whether the UI support touch pad
#define PIN_BL GPIO_NUM_2				//	cfg.pin_bl = 2

//----------------------------tp configaction

// Pines TFT HMI ESP32 4827S043 - ESP32-S3 480x272
static const uint16_t TFT_WIDTH = 480;
static const uint16_t TFT_HEIGHT = 272;
//----------------------------end tp configaction

//------------------------start display select
#define BUF_SIZE 80
#define DISP_BUF_SIZE (LV_HOR_RES_MAX * BUF_SIZE)
#define BUF_NUM 1
//------------------------end display select

#endif // __CONFIG_H__