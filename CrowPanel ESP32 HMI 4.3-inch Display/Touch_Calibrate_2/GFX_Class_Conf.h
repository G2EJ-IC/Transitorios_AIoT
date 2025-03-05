//////////////////////////////////////////////////////////////////////////////
/*
	ESP32 | LVGL9 | GFX_Class_Conf
    LovyanGFX
    https://github.com/lovyan03/LovyanGFX
    
    Modificado: Ernesto José Guerrero González, Civil Engineering ud FJdC.
*/
//////////////////////////////////////////////////////////////////////////////

#ifndef __CLASSCROWPANEL_H__
#define __CLASSCROWPANEL_H__

#include <Arduino.h>
#define LGFX_USE_V1
#include "config.h"
#include <LovyanGFX.hpp>

#if defined (HMI_TFT_ILI9488_39_480x320)



#elif defined (HMI_TFT_CrowPanel_43_480x272)

#include <lgfx/v1/platforms/esp32s3/Panel_RGB.hpp>
#include <lgfx/v1/platforms/esp32s3/Bus_RGB.hpp>
#include <lgfx/v1/platforms/esp32/Light_PWM.hpp>
#include <lgfx/v1/touch/Touch_XPT2046.hpp>

#include <driver/i2c.h>

enum BoardConstants { TFT_BL=2, SERIAL_BAUD=9600, LVGL_BUFFER_RATIO = 6 };

class LGFX : public lgfx::LGFX_Device
{
public:
    lgfx::Panel_RGB     _panel_instance;
    lgfx::Bus_RGB       _bus_instance;
    lgfx::Light_PWM     _light_instance;
    
    lgfx::Touch_XPT2046 _touch_instance;

    LGFX(void)
    {
        {
            auto cfg = _panel_instance.config();
			//Pines GPIO.
			cfg.memory_width = TFT_WIDTH;	    // Ancho máximo admitido por el controlador IC
			cfg.memory_height = TFT_HEIGHT;	    // Altura máxima admitida por el controlador IC
			cfg.panel_width = TFT_WIDTH;		// Ancho visualizable real
			cfg.panel_height = TFT_HEIGHT;	    // Altura de visualización real
			cfg.offset_x = 0;				    // Cantidad de desplazamiento de dirección del panel X
			cfg.offset_y = 0;				    // Cantidad de compensación de dirección del panel Y
			_panel_instance.config(cfg);
        }

        {
            auto cfg = _bus_instance.config();
            cfg.panel = &_panel_instance;

            cfg.pin_d0 = GPIO_NUM_8;        // B0
            cfg.pin_d1 = GPIO_NUM_3;        // B1
            cfg.pin_d2 = GPIO_NUM_46;       // B2
            cfg.pin_d3 = GPIO_NUM_9;        // B3
            cfg.pin_d4 = GPIO_NUM_1;        // B4
            
            cfg.pin_d5 = GPIO_NUM_5;        // G0
            cfg.pin_d6 = GPIO_NUM_6;        // G1
            cfg.pin_d7 = GPIO_NUM_7;        // G2
            cfg.pin_d8 = GPIO_NUM_15;       // G3
            cfg.pin_d9 = GPIO_NUM_16;       // G4
            cfg.pin_d10 = GPIO_NUM_4;       // G5
            
            cfg.pin_d11 = GPIO_NUM_45;      // R0
            cfg.pin_d12 = GPIO_NUM_48;      // R1
            cfg.pin_d13 = GPIO_NUM_47;      // R2
            cfg.pin_d14 = GPIO_NUM_21;      // R3
            cfg.pin_d15 = GPIO_NUM_14;      // R4

            cfg.pin_henable = GPIO_NUM_40;
            cfg.pin_vsync = GPIO_NUM_41;
            cfg.pin_hsync = GPIO_NUM_39;
            cfg.pin_pclk =  GPIO_NUM_42; //GPIO_NUM_0; //  GPIO_NUM_42;
            cfg.freq_write = 8000000;  // 8000000;

            // hsync
            cfg.hsync_polarity    = 0;
            cfg.hsync_front_porch = 8;
            cfg.hsync_pulse_width = 4;
            cfg.hsync_back_porch  = 43;

            // vsync
            cfg.vsync_polarity    = 0;
            cfg.vsync_front_porch = 8;
            cfg.vsync_pulse_width = 4;
            cfg.vsync_back_porch  = 12;

            // polaridad del reloj PCLK
            cfg.pclk_active_neg = 1;
            cfg.de_idle_high = 0;
            cfg.pclk_idle_high = 0;

            _bus_instance.config(cfg);
            // _panel_instance.setBus(&_bus_instance);
        }

        {
            auto cfg = _light_instance.config();
            cfg.pin_bl = GPIO_NUM_2;
            _light_instance.config(cfg);
            _panel_instance.light(&_light_instance);
        }

        {
            auto touch_cfg = _touch_instance.config();
            touch_cfg.x_min      = 100;  	        // Valor mínimo de X obtenido de la pantalla táctil (valor bruto)
            touch_cfg.x_max      = 4000;  	        // Valor máximo de X obtenido de la pantalla táctil (valor bruto)
            touch_cfg.y_min      = 100;    	        // Valor mínimo de Y obtenido de la pantalla táctil (valor bruto)
            touch_cfg.y_max      = 4000;  	        // Valor máximo de Y obtenido de la pantalla táctil (valor bruto)
            touch_cfg.pin_int    = GPIO_NUM_36;   	// Número de pin al que está conectado INT
            touch_cfg.bus_shared = true; 	        // Configurar como true si se utiliza el mismo bus que la pantalla
            touch_cfg.offset_rotation = ROTATION;   // Ajuste para cuando la orientación de la pantalla y la del táctil no coinciden, configurar con un valor de 0 a 7

            // En el caso de una conexión SPI
            touch_cfg.spi_host   = SPI2_HOST; 		// HSPI_HOST; // Seleccionar el SPI a utilizar (HSPI_HOST o VSPI_HOST)
            touch_cfg.freq       = 1000000;     	// Configurar la frecuencia del reloj SPI
            touch_cfg.pin_sclk   = GPIO_NUM_12;     // Número de pin al que está conectado SCLK
            touch_cfg.pin_mosi   = GPIO_NUM_11;     // Número de pin al que está conectado MOSI
            touch_cfg.pin_miso   = GPIO_NUM_13;     // Número de pin al que está conectado MISO
            touch_cfg.pin_cs     = GPIO_NUM_0;     	// Número de pin al que está conectado CS

            _touch_instance.config(touch_cfg);
            _panel_instance.setTouch(&_touch_instance);  // Configura la pantalla táctil en el panel.
        }
        _panel_instance.setBus(&_bus_instance);
        setPanel(&_panel_instance);
    }
};

#endif // defined (HMI_TFT_ ....)

LGFX tft; //  load tft service

#endif // __CLASSCROWPANEL_H__