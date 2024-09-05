// #include "camera_pins.h"

#if defined(TFT_ILI9488_480_320)

// Pines TFT ILI9488.
#define LCD_SCK 	18	//	cfg.pin_sclk = 	18;
#define LCD_MOSI 	23	//	cfg.pin_mosi = 	23;
#define LCD_MISO 	19	//	cfg.pin_miso = 	19;
#define LCD_SS0 	15	//	cfg.pin_cs =	15;
#define LCD_SS1 	21	//	cfg.pin_cs =	21;
#define LCD_SS2 	5	//	cfg.pin_cs =	5;

#define SPI_DC		2	//	cfg.pin_dc   = 	2;
#define PIN_RST		4	//	cfg.pin_rst = 	4;
#define PIN_BL		32	//	cfg.pin_bl =	32;

#define PIN_BUSY	-1	//	cfg.pin_busy = 	-1;
#define PIN_INT		-1	//	cfg.pin_int =	-1;

#elif defined(TFT_)

#define LCD_SCK     18    //    cfg.pin_sclk =     18;
#define LCD_MOSI    23    //    cfg.pin_mosi =     23;
#define LCD_MISO    19    //    cfg.pin_miso =     19;
#define LCD_SS0     15    //    cfg.pin_cs =    15;
#define LCD_SS1     21    //    cfg.pin_cs =    21;

#define SPI_DC		2	//	cfg.pin_dc   = 	2;
#define PIN_RST		4	//	cfg.pin_rst = 	4;
#define PIN_BL		32	//	cfg.pin_bl =	32;

#define PIN_BUSY	-1	//	cfg.pin_busy = 	-1;
#define PIN_INT		-1	//	cfg.pin_int =	-1;

#endif
