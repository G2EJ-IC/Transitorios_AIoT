#ifndef __CONFIG_H__
#define __CONFIG_H__
//////////////////////////////////////////////////////////////////////////
/*
	ESP32 | LVGL8.3.11 | Ep 0. GFX Setup (ft. LovyanGFX)
	Developing Embedded GUI with EEZ Studio
	Configuración de config.h
	Created by That Project
*/
//////////////////////////////////////////////////////////////////////////
/*
	Modificado: Ernesto José Guerrero González, Civil Engineering ud FJdC.
*/
//////////////////////////////////////////////////////////////////////////
#define HMI_TFT_CrowPanel_43_480x272

#define VERSION "0.0.0.4" 	//version number
#define _DEBUG_           	//debug switch
#define DEV_TYPE "esp32dev"
#define LVGL_TICK_PERIOD 10 //lvgl tick period
#define ROTATION 1          //set ui rotation
#define TOUCHPAD 			//whether the UI support touch pad
// #define _TP_DEBUG_ //TP debug

//----------------------------tp configaction
#if defined(HMI_TFT_ILI9488_39_480x320)
// Pines TFT ILI9488 480x320.
static const uint16_t TFT_WIDTH = 480;
static const uint16_t TFT_HEIGHT = 320;

#define LCD_SCK 	GPIO_NUM_18		//	cfg.pin_sclk = 	18;
#define LCD_MOSI 	GPIO_NUM_23		//	cfg.pin_mosi = 	23;
#define LCD_MISO 	GPIO_NUM_19		//	cfg.pin_miso = 	19;
#define LCD_SS0 	GPIO_NUM_15		//	cfg.pin_cs =	15;
#define LCD_SS1 	GPIO_NUM_21		//	cfg.pin_cs =	21;
#define LCD_SS2 	-1				//	cfg.pin_cs =	5;

#define SPI_DC		GPIO_NUM_2		//	cfg.pin_dc   = 	2;
#define PIN_RST		GPIO_NUM_4		//	cfg.pin_rst = 	4;
#define PIN_BL		GPIO_NUM_32		//	cfg.pin_bl =	32;

#define PIN_BUSY	-1				//	cfg.pin_busy = 	-1;
#define PIN_INT		-1				//	cfg.pin_int =	-1;

#define TOUCH_CS 	GPIO_NUM_21 	// Pin CS del panel táctil
#define PinLED 		GPIO_NUM_2		// LED_BUILTIN

#elif defined(HMI_TFT_CrowPanel_43_480x272)
// Pines TFT HMI ESP32 4827S043 - ESP32-S3 480x320
static const uint16_t TFT_WIDTH = 480;
static const uint16_t TFT_HEIGHT = 272;

#define LCD_SCK     GPIO_NUM_12 	//  cfg.pin_sclk =  12;
#define LCD_MOSI    GPIO_NUM_11 	//  cfg.pin_mosi =  11;
#define LCD_MISO    GPIO_NUM_13 	//  cfg.pin_miso =  13;
#define LCD_SS0     GPIO_NUM_10 	//  cfg.pin_cs =    10;
#define LCD_SS1 	GPIO_NUM_0		//	cfg.pin_cs =	 0;

#define PIN_BL		GPIO_NUM_2		//	cfg.pin_bl =	2;

#define PIN_INT		GPIO_NUM_36		//	cfg.pin_int =	-1;

#define TOUCH_CS 	GPIO_NUM_10 	//  Pin CS del panel táctil
#define PinLED 		-1				// 	LED_BUILTIN

#endif
//----------------------------end tp configaction

//------------------------start display select
#define BUF_SIZE 80
#define DISP_BUF_SIZE (LV_HOR_RES_MAX * BUF_SIZE)
#define BUF_NUM 1
#define ICACHE_FLASH_ATTR
//------------------------end display select

#endif // __CONFIG_H__
