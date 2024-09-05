# Install script for directory: C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lvgl

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Transitorios_AIoT_RPi2040-2")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Program Files/Raspberry Pi/Pico SDK v1.5.1/gcc-arm-none-eabi/bin/arm-none-eabi-objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Program Files (x86)/Transitorios_AIoT_RPi2040-2/include/lvgl//src")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "C:/Program Files (x86)/Transitorios_AIoT_RPi2040-2/include/lvgl/" TYPE DIRECTORY FILES "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lvgl/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Program Files (x86)/Transitorios_AIoT_RPi2040-2/include/lvgl/lv_version.h;C:/Program Files (x86)/Transitorios_AIoT_RPi2040-2/include/lvgl/lvgl.h;C:/Program Files (x86)/Transitorios_AIoT_RPi2040-2/include/lvgl/lv_conf.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "C:/Program Files (x86)/Transitorios_AIoT_RPi2040-2/include/lvgl" TYPE FILE FILES
    "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lvgl/lv_version.h"
    "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lvgl/lvgl.h"
    "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lv_conf.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Program Files (x86)/Transitorios_AIoT_RPi2040-2/include/lvgl//examples")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "C:/Program Files (x86)/Transitorios_AIoT_RPi2040-2/include/lvgl/" TYPE DIRECTORY FILES "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lvgl/examples" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Program Files (x86)/Transitorios_AIoT_RPi2040-2/include/lvgl//demos")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "C:/Program Files (x86)/Transitorios_AIoT_RPi2040-2/include/lvgl/" TYPE DIRECTORY FILES "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lvgl/demos" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/build/lvgl/lvgl.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/build/lib/liblvgl.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lvgl" TYPE FILE FILES
    "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lvgl/lv_version.h"
    "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lvgl/lvgl.h"
    "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lv_conf.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/build/lib/liblvgl_thorvg.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lvgl" TYPE FILE FILES
    "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lvgl/lv_version.h"
    "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lvgl/lvgl.h"
    "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lv_conf.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/build/lib/liblvgl_demos.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lvgl" TYPE FILE FILES
    "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lvgl/lv_version.h"
    "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lvgl/lvgl.h"
    "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lv_conf.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/build/lib/liblvgl_examples.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lvgl" TYPE FILE FILES
    "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lvgl/lv_version.h"
    "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lvgl/lvgl.h"
    "C:/xEEZStudio/Transitorios_AIoT/RPi2040/Transitorios_AIoT_RPi2040-2/lv_conf.h"
    )
endif()

