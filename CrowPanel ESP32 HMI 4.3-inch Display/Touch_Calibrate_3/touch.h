/*******************************************************************************
 * Touch libraries:
 * FT6X36: https://github.com/strange-v/FT6X36.git
 * GT911: https://github.com/TAMCTec/gt911-arduino.git
 * XPT2046: https://github.com/PaulStoffregen/XPT2046_Touchscreen.git
 ******************************************************************************/
/* uncomment for XPT2046 */
#ifndef __TOUCH_H__
#define __TOUCH_H__

#define TOUCH_XPT2046
#define TOUCH_XPT2046_SCK 12
#define TOUCH_XPT2046_MISO 13
#define TOUCH_XPT2046_MOSI 11
#define TOUCH_XPT2046_CS 0
#define TOUCH_XPT2046_INT 36
#define TOUCH_XPT2046_ROTATION 0
#define TOUCH_MAP_X1 4000
#define TOUCH_MAP_X2 200
#define TOUCH_MAP_Y1 200
#define TOUCH_MAP_Y2 4000

int touch_last_x = 0, touch_last_y = 0;

#include <XPT2046_Touchscreen.h>
#include <SPI.h>
XPT2046_Touchscreen ts(TOUCH_XPT2046_CS, TOUCH_XPT2046_INT);

void touch_init()
{
  SPI.begin(TOUCH_XPT2046_SCK, TOUCH_XPT2046_MISO, TOUCH_XPT2046_MOSI, TOUCH_XPT2046_CS);
  ts.begin();
  ts.setRotation(TOUCH_XPT2046_ROTATION);
}

bool touch_has_signal()
{
  return ts.tirqTouched();
}

bool touch_touched()
{
  if (ts.touched())
  {
    TS_Point p = ts.getPoint();
    return true;
  }
  else
  {
    return false;
  }
}

bool touch_released()
{
  return true;
}

#endif // __TOUCH_H__