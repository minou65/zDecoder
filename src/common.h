// common.h

#ifndef _COMMON_h
#define _COMMON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define STRING_LEN 30
#define NUMBER_LEN 5

extern bool ResetDCCDecoder;
extern char Version[];

static char DecoderModeValues[][STRING_LEN] = {
    "40",
    "50",
    "51",
    "80",
    "81",
    "82",
    "52",
    "53",
    "54",
    "60",
    "61",
    "62",
    "102",
    "103",
    "104",
    "105",
    "106",
    "110",
    "70",
    "201",
    "202",
    "230"
};

static char DecoderModeNames[][STRING_LEN] = {
    "einfacher Ausgang (1)",  // ok
    "Blinker (1)",  // ok, fading ok
    "Wechselblinker (2)", // ok
    "Fernseher (1)",  // ok
    "Schweisslicht (3)", // ok
    "Feuer (3)", // ok
    "Lauflicht 1 (1..16)", // ok
    "Lauflicht 2 (1..16)",  // ok
    "Lauflicht 3 (1..16)",  // ok

    "Hausbeleuchtung (1..16)", // ok
    "Neonlampen (1..16)", // ok
    "Natriumlampen (1..16)", // ok
    "SBB_Hauptsignal_102 (2)",
    "SBB_Hauptsignal_103 (3)",
    "SBB_Hauptsignal_104 (4)",
    "SBB_Hauptsignal_105 (5)",
    "SBB_Hauptsignal_106 (5)",
    "SBB_Zwergsignal_110 (3)",
    "Strassen_Signal_70 (3)",
    "Entkuppler (1)", // ok
    "Weiche (2)",  // ok
    "Servo (1)"
};

#endif
