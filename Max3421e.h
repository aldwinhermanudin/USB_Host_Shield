/* Copyright 2009-2011 Oleg Mazurov, Circuits At Home, http://www.circuitsathome.com */
/* MAX3421E functions */
#ifndef _MAX3421E_H_
#define _MAX3421E_H_

// Arduino 1.0 compatibility
#if defined(ARDUINO) && ARDUINO >= 100
    #include <Arduino.h>
#else
    #include <WProgram.h>
#endif
#include "Max3421e_constants.h"
#include <SPI.h>

class MAX3421E /* : public SPI */ {
    // byte vbusState;
    public:
        MAX3421E( void );
        byte getVbusState( void );
//        void toggle( byte pin );
        static void regWr( byte, byte );
        char * bytesWr( byte, byte, char * );
        static void gpioWr( byte );
        byte regRd( byte );
        char * bytesRd( byte, byte, char * );
        byte gpioRd( void );
        boolean reset();
        boolean vbusPwr ( boolean );
        void busprobe( void );
        void powerOn();
        byte IntHandler();
        byte GpxHandler();
        byte Task();
    private:
      static void spi_init() {
                SPI.begin(SCK_PIN,MISO_PIN,MOSI_PIN,SS_PIN); // The SPI library with transaction will take care of setting up the pins - settings is set in beginTransaction()
                //SPI_SS::SetDirWrite();
                pinMode(SS_PIN, OUTPUT);
                //SPI_SS::Set();
                digitalWrite(SS_PIN, HIGH);
       }
//        void init();
    friend class Max_LCD;        
};




#endif //_MAX3421E_H_
