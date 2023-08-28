#pragma once
#include <map>
#include <string>
#include <cmath>

#include <iostream>
#include <map>
#include <string>
#error "Hello"
namespace Time 
{
    class Sample {
    public:
        typedef enum {
            YOTTASECOND,
            ZETTASECOND,
            EXASECOND,
            PETASECOND,
            TERASECOND,
            GIGASECOND,
            MEGASECOND,
            KILOSECOND,
            HECTOSECOND,
            DECASECOND,
            SECOND,
            DECISECOND,
            CENTISECOND,
            MILLISECOND,
            MICROSECOND,
            NANOSECOND,
            PICOSECOND,
            FEMTOSECOND,
            ATTOSECOND,
            ZEPTOSECOND,
            YOCTOSECOND,
            NO_OF_UNITS
        } periodUnitsEnum_t;


        typedef struct period_metric_unit_map
        {
            double unitValue;
            std::string unitName;

        }periodUnit_t;

        static periodUnit_t periodUnitMapping[NO_OF_UNITS];
        Sample(double period, periodUnitsEnum_t unit) : currentPeriod(period), currentUnit(unit) {}

        void convertTo(periodUnitsEnum_t desiredUnit) {
            if (desiredUnit != currentUnit) {
                currentPeriod = currentPeriod / periodUnitMapping[desiredUnit].unitValue;
                currentUnit = desiredUnit;
            }
        }

        void setCurrentPeriod(double newPeriod) {
            currentPeriod = newPeriod;
        }

        double getCurrentPeriod() const {
            return currentPeriod;
        }

        std::string  getCurrentUnit() const {
            return periodUnitMapping[currentUnit].unitName;
        }

        static void printUnits(void) {
            for (uint8_t index = 0; index < NO_OF_UNITS; index++) {
                std::cout << "(" << (unsigned int)index << ")" << periodUnitMapping[index].unitName << "\n";
            }
        }

    private:
        double currentPeriod;
        periodUnitsEnum_t currentUnit;

    };

    Sample::periodUnit_t Sample::periodUnitMapping[Sample::NO_OF_UNITS] = {
        {1e-24		, "YOTTASECOND"},
        {1e-21		, "ZETTASECOND"},
        {1e-18		, "EXASECOND"},
        {1e-15		, "PETASECOND"},
        {1e-12		, "TERASECOND"},
        {1e-9		, "GIGASECOND"},
        {1e-6		, "MEGASECOND"},
        {1e-3		, "KILOSECOND"},
        {1e-2		, "HECTOSECOND"},
        {1e-1		, "DECASECOND"},
        {1.0		,  "SECOND"},
        {1e1		, "DECISECOND"},
        {1e2		, "CENTISECOND"},
        {1e3		, "MILLISECOND"},
        {1e6		, "MICROSECOND"},
        {1e9		, "NANOSECOND"},
        {1e12		, "PICOSECOND"},
        {1e15		, "FEMTOSECOND"},
        {1e18		, "ATTOSECOND"},
        {1e21		, "ZEPTOSECOND"},
        {1e24		, "YOCTOSECOND"}
    };

    class Frequence {
    public:

        typedef enum {
            YOCTOHERTZ,
            ZEPTOHERTZ,
            ATTOHERTZ,
            FEMTOHERTZ,
            PICOHERTZ,
            NANOHERTZ,
            MICROHERTZ,
            MILLIHERTZ,
            CENTIHERTZ,
            DECIHERTZ,
            HERTZ,
            DECAHERTZ,
            HECTOHERTZ,
            KILOHERTZ,
            MEGAHERTZ,
            GIGAHERTZ,
            TERAHERTZ,
            PETAHERTZ,
            EXAHERTZ,
            ZETTAHERTZ,
            YOTTAHERTZ,
            NO_OF_UNITS
        } frequencyUnitsEnum_t;


        typedef struct frequency_metric_unit_map
        {
            double unitValue;
            std::string unitName;

        }frequencyUnit_t;

        static frequencyUnit_t frequencyUnitMapping[NO_OF_UNITS];

        Frequence(double frequency, frequencyUnitsEnum_t unit) : currentFrequency(frequency), currentUnit(unit) {}

        void convertTo(frequencyUnitsEnum_t desiredUnit) {
            if (desiredUnit != currentUnit) {

                currentFrequency = currentFrequency / frequencyUnitMapping[desiredUnit].unitValue;
                currentUnit = desiredUnit;
            }else{ /* Do nothing... */ }
        }

        double getCurrentFrequency() const {
            return currentFrequency;
        }

        void setCurrentFrequency(double newFrequency) {
            currentFrequency = newFrequency;
        }

        std::string getCurrentUnit() const {
            return frequencyUnitMapping[currentUnit].unitName;
        }

        static void printUnits(void) {
            for (uint8_t index = 0; index < NO_OF_UNITS; index++) {
                std::cout << "(" << (unsigned int)index << ")" << frequencyUnitMapping[index].unitName << "\n";
            }
        }

    private:
        double currentFrequency;
        frequencyUnitsEnum_t currentUnit;

    };
	
    Frequence::frequencyUnit_t Frequence::frequencyUnitMapping[Frequence::NO_OF_UNITS] = {
           {1e-24, "YOCTOHERTZ"},
           {1e-21, "ZEPTOHERTZ"},
           {1e-18, "ATTOHERTZ"},
           {1e-15, "FEMTOHERTZ"},
           {1e-12, "PICOHERTZ"},
           {1e-9, "NANOHERTZ"},
           {1e-6, "MICROHERTZ"},
           {1e-3, "MILLIHERTZ"},
           {1e-2, "CENTIHERTZ"},
           {1e-1, "DECIHERTZ"},
           {1.0, "HERTZ"},
           {1e1, "DECAHERTZ"},
           {1e2, "HECTOHERTZ"},
           {1e3, "KILOHERTZ"},
           {1e6, "MEGAHERTZ"},
           {1e9, "GIGAHERTZ"},
           {1e12, "TERAHERTZ"},
           {1e15, "PETAHERTZ"},
           {1e18, "EXAHERTZ"},
           {1e21, "ZETTAHERTZ"},
           {1e24, "YOTTAHERTZ"}
    };


    double frequencyToPeriod(double frequency) {
        if (frequency == 0.0) {
            return 0.0; // Avoid division by zero
        }
        return 1.0 / frequency;
    }

    double periodToFrequency(double period) {
        if (period == 0.0) {
            return 0.0; // Avoid division by zero
        }
        return 1.0 / period;
    }

}
