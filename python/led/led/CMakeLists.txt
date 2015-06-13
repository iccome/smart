PROJECT(beaglebone_led)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
CMAKE_POLICY(SET CMP0015 NEW)     # Allow find librarys in relative path
include (${CMAKE_HOME_DIRECTORY}/config/ver.cmake)

#option (PLATFORM_BRCM "build for platform boardcom chips" OFF)
#option (PLATFORM_CSR "build for platform csr chips" ON)
option (RELEASE "Release Version" OFF)
#option (HCI_USE_USB "Whether use usb " OFF)
#option(STACK_INCLUDE_DECODER "Whether sbc decoder in stack " OFF)
#option(STACK_INCLUDE_WBS "Whether open wbs,only BRCM platform support it " OFF)
#option(DECODER_INCLUDE_ALSA "decoder include alsa play "  OFF)

#include (${CMAKE_HOME_DIRECTORY}/config/toolchain-cross.cmake)

# judge platform first
#set(var 0)

#judge platform
IF( "${CMAKE_SIZEOF_VOID_P}" EQUAL "8" )
    # MESSAGE(system64)
    if (PLATFORM_CSR)
        set(var 1)
    endif (PLATFORM_CSR)
ELSEIF( "${CMAKE_SIZEOF_VOID_P}" EQUAL "4" )
    # MESSAGE(system32)
ENDIF()
if(var)
# MESSAGE(m32 compile)
    SET(CMAKE_C_FLAGS "-W -g -m32 -O2 -Wdeclaration-after-statement")
    SET(CMAKE_CXX_FLAGS "-W -g -m32 -O2 ")
else(var)
    SET(CMAKE_C_FLAGS "-W -g -O2 -Wdeclaration-after-statement")
    SET(CMAKE_CXX_FLAGS "-W -g -O2")
endif(var)

#add_definitions("-DPSET_INCLUDE_PBDL -DPSET_INCLUDE_AV -DPSET_INCLUDE_PAN -DPSET_INCLUDE_MSG")
#add_definitions("-DPSET_INCLUDE_HID -DPSET_INCLUDE_SPP -DPSET_INCLUDE_DUN -DPSET_INCLUDE_HFP")
add_definitions("-Wno-multichar -Wa,--noexecstack -Werror=format-security -Wall -Wno-unused -Winit-self -Wpointer-arith")
add_definitions("-Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -DNDEBUG")
#add_definitions("-Wstrict-aliasing -Wno-unused-parameter")
#add_definitions("-DENABLE_SHUTDOWN")
add_definitions("-Werror=pointer-to-int-cast -Wno-unused-result")

#if (PLATFORM_BRCM)
#if (STACK_INCLUDE_WBS)
#    add_definitions("-DENABLE_WBS")
#endif (STACK_INCLUDE_WBS)
#endif (PLATFORM_BRCM)

if (RELEASE)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DBEAGLEBONE_RELEASE")
endif (RELEASE)


configure_file(
    "${CMAKE_HOME_DIRECTORY}/config/beaglebone_global_config.h.in"
    "${CMAKE_HOME_DIRECTORY}/config/beaglebone_global_config.h"
)

# find all the header file 
FILE(GLOB_RECURSE HEADER_LIST "include/*.h")
SET (INCLUDE_DIRS "")
FOREACH(_headerFile ${HEADER_LIST})
get_filename_component(_dir ${_headerFile} PATH)
LIST(APPEND INCLUDE_DIRS ${_dir}) 
ENDFOREACH()

LIST(REMOVE_DUPLICATES INCLUDE_DIRS)
# find all the source file under src
FILE(GLOB_RECURSE SRC_LIST "function/*.c")


#if (PLATFORM_BRCM)
#    FILE(GLOB_RECURSE VENDOR_LIST "transport/vendor/brcm/*.c")
#else (PLATFORM_BRCM)
#    FILE(GLOB_RECURSE VENDOR_LIST "transport/vendor/csr/*.c")
#endif (PLATFORM_BRCM)

#message(STATUS ${VENDOR_LIST})

# find the include directories
LIST(REMOVE_DUPLICATES INCLUDE_DIRS)
INCLUDE_DIRECTORIES(${INCLUDE_DIRS})
INCLUDE_DIRECTORIES("/usr/local/include/")
LINK_DIRECTORIES(.)

FIND_PACKAGE(Threads)

# Compile static library
#ADD_LIBRARY(bt_profile STATIC ${SRC_LIST} ${GKI_LIST} ${HCI_LIST}
#    ${UTIL_LIST} ${PROF_LIST} ${VENDOR_LIST})
# Compile shared library
ADD_LIBRARY(beaglebone_led SHARED ${SRC_LIST})
#TARGET_LINK_LIBRARIES(bt_stack bt_profile)
TARGET_LINK_LIBRARIES(beaglebone_led ${CMAKE_THREAD_LIBS_INIT})
TARGET_LINK_LIBRARIES(beaglebone_led rt)
TARGET_LINK_LIBRARIES(beaglebone_led dl)


#TARGET_LINK_LIBRARIES(bt_stack util)

ADD_EXECUTABLE(led_test  "test/test.c")
TARGET_LINK_LIBRARIES(led_test beaglebone_led)




