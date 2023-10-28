// webhandling.h
#pragma once

#ifndef _WEBHANDLING_h
#define _WEBHANDLING_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <IotWebConf.h>
#include <IotWebConfOptionalGroup.h>
#include "common.h"

void websetup();
void webloop();

extern void handleChannel(uint8_t Channel_);
extern bool ChannelIsOn(uint8_t Channel_);

class ActionGroup : public iotwebconf::ChainedParameterGroup
{
public:
    ActionGroup(const char* id) : ChainedParameterGroup(id, "Output")
    {
        // -- Update parameter Ids to have unique ID for all parameters within the application.
        snprintf(DesignationId, STRING_LEN, "%s-designation", this->getId());
        snprintf(ModeId, STRING_LEN, "%s-mode", this->getId());
        snprintf(NumberId, STRING_LEN, "%s-number", this->getId());
        snprintf(AddressId, STRING_LEN, "%s-address", this->getId());
        snprintf(TimeOnId, STRING_LEN, "%s-timeon", this->getId());
        snprintf(TimeOffId, STRING_LEN, "%s-timeoff", this->getId());
        snprintf(MultiplierId, STRING_LEN, "%s-multiplier", this->getId());
        snprintf(TimeOnFadeId, STRING_LEN, "%s-onfade", this->getId());
        snprintf(TimeOffFadeId, STRING_LEN, "%s-offfade", this->getId());

        // -- Add parameters to this group.
        this->addItem(&this->DesignationParam);
        this->addItem(&this->ModeParam);
        this->addItem(&this->NumberParam);
        this->addItem(&this->AddressParam);
        this->addItem(&this->TimeOnParam);
        this->addItem(&this->TimeOffParam);
        this->addItem(&this->MultiplierParam);
        this->addItem(&this->TimeOnFadeParam);
        this->addItem(&this->TimeOffFadeParam);
    }

    char DesignationValue[STRING_LEN];
    char ModeValue[STRING_LEN];
    char NumberValue[NUMBER_LEN];
    char AddressValue[NUMBER_LEN];
    char TimeOnValue[NUMBER_LEN];
    char TimeOffValue[NUMBER_LEN];
    char MultiplierValue[NUMBER_LEN];
    char TimeOnFadeValue[NUMBER_LEN];
    char TimeOffFadeValue[NUMBER_LEN];

    iotwebconf::TextParameter DesignationParam =
        iotwebconf::TextParameter("Designation", DesignationId, DesignationValue, STRING_LEN);
    iotwebconf::SelectParameter ModeParam =
        iotwebconf::SelectParameter("Mode", ModeId, ModeValue, STRING_LEN, (char*)DecoderModeValues, (char*)DecoderModeNames, sizeof(DecoderModeValues) / STRING_LEN, STRING_LEN);

    iotwebconf::NumberParameter NumberParam =
        iotwebconf::NumberParameter("Number of outputs", NumberId, NumberValue, NUMBER_LEN, "1", "1..15", "min='1' max='15' step='1'");

    iotwebconf::NumberParameter AddressParam =
        iotwebconf::NumberParameter("DCC Address", AddressId, AddressValue, NUMBER_LEN, "3", "1..1024", "min='1' max='1024' step='1'");

    iotwebconf::NumberParameter TimeOnParam =
        iotwebconf::NumberParameter("Time on (ms)", TimeOnId, TimeOnValue, NUMBER_LEN, "10", "1..255", "min='1' max='255' step='1'");

    iotwebconf::NumberParameter TimeOffParam =
        iotwebconf::NumberParameter("time off (ms)", TimeOffId, TimeOffValue, NUMBER_LEN, "10", "1..255", "min='1' max='255' step='1'");

    iotwebconf::NumberParameter MultiplierParam =
        iotwebconf::NumberParameter("Multiplier", MultiplierId, MultiplierValue, NUMBER_LEN, "10", "1..255", "min='1' max='255' step='1'");

    iotwebconf::NumberParameter TimeOnFadeParam =
        iotwebconf::NumberParameter("Fader on (ms)", TimeOnFadeId, TimeOnFadeValue, NUMBER_LEN, "1", "1..255", "min='1' max='255' step='1'");

    iotwebconf::NumberParameter TimeOffFadeParam =
        iotwebconf::NumberParameter("Fader off (ms)", TimeOffFadeId, TimeOffFadeValue, NUMBER_LEN, "1", "1..255", "min='1' max='255' step='1'");

private:
    char DesignationId[STRING_LEN];
    char ModeId[STRING_LEN];
    char NumberId[STRING_LEN];
    char AddressId[STRING_LEN];
    char TimeOnId[STRING_LEN];
    char TimeOffId[STRING_LEN];
    char MultiplierId[STRING_LEN];
    char TimeOnFadeId[STRING_LEN];
    char TimeOffFadeId[STRING_LEN];
};


extern ActionGroup OutputGroup1;
extern ActionGroup OutputGroup2;
extern ActionGroup OutputGroup3;
extern ActionGroup OutputGroup4;
extern ActionGroup OutputGroup5;
extern ActionGroup OutputGroup6;
extern ActionGroup OutputGroup7;
extern ActionGroup OutputGroup8;
extern ActionGroup OutputGroup9;
extern ActionGroup OutputGroup10;

#endif

