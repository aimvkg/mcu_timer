#include <iostream>
#include <map>
#include <string>
#include <cmath>

#include <iostream>
#include <map>
#include <string>

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

namespace Timer
{
    double ticksToFrequency(unsigned int timerValue, double clockFrequency) {
        return clockFrequency / (timerValue + 1);
    }


    unsigned int frequencyToTicks(double desiredFrequency, unsigned int& counterValue, double clockFrequency, unsigned int counterSizeInBits) {

        unsigned int maxCounterValue = (1u << counterSizeInBits) - 1;

        counterValue = static_cast<unsigned int>((clockFrequency / desiredFrequency) - 1);

        if (counterValue > maxCounterValue) {

            counterValue = maxCounterValue;
            return -1;
        }
        else
        {
            return 0;
        }

    }

    typedef enum
    {
        NONE = 0,
        PRESCALER = 1,
        PRESCALER_TIMER = 3,
        PRESCALER_TIMER_POSTSCALER = 7,
        UNDEFINED

    }operation_t;

    unsigned int deduceAction(unsigned int& registerSize, bool isDesiredOutput, operation_t& operation)
    {

        if (registerSize)
        {

            operation = (operation_t)((operation << 1) | 1);
            return 0;
        }
        else
        {
            if (isDesiredOutput)
            {
                operation = UNDEFINED;
                return -1;
            }
            else { return 0; }
        }
    }


    typedef struct CounterRegister
    {
        unsigned int Size;
        unsigned int tick;
        Time::Frequence frequence;
        Time::Sample sample;

    } counterRegister_t;
}

int main() {
    Timer::operation_t operation = Timer::NONE;

    unsigned int measurementUnit;
    unsigned int timerSizeInBits;
    unsigned int prescalerSizeInBits;
    unsigned int postscalerSizeInBits;
    double sourceFrequency;
    double desiredPrescalerFrequency;
    double desiredTimerFrequency;
    double desiredPostscalerFrequency;
    unsigned int prescalerValue = 0;
    unsigned int timerValue = 0;
    unsigned int postscalerValue = 0;

    Time::Frequence::printUnits();

    std::cout << "Enter frequency measurement unit: ";
    std::cin >> measurementUnit;

    std::cout << "Enter prescaler register size in bits: ";
    std::cin >> prescalerSizeInBits;
    

    std::cout << "Enter timer register size in bits: ";
    std::cin >> timerSizeInBits;

    std::cout << "Enter postscaler register size in bits: ";
    std::cin >> postscalerSizeInBits;

    std::cout << "Enter source clock frequency: ";
    std::cin >> sourceFrequency;

    std::cout << "Enter desired prescaler frequency: ";
    std::cin >> desiredPrescalerFrequency;

    std::cout << "Enter desired Timer frequency: ";
    std::cin >> desiredTimerFrequency;

    std::cout << "Enter desired Postscaler frequency: ";
    std::cin >> desiredPostscalerFrequency;

    Timer::counterRegister_t oscilator = { 0, 0, Time::Frequence(sourceFrequency,(Time::Frequence::frequencyUnitsEnum_t)measurementUnit), Time::Sample(Time::frequencyToPeriod(sourceFrequency),(Time::Sample::periodUnitsEnum_t)measurementUnit)};
    Timer::counterRegister_t prescaler = { prescalerSizeInBits, 0, Time::Frequence(sourceFrequency,(Time::Frequence::frequencyUnitsEnum_t)measurementUnit), Time::Sample(Time::frequencyToPeriod(sourceFrequency),(Time::Sample::periodUnitsEnum_t)measurementUnit) };
    Timer::counterRegister_t timer = { timerSizeInBits, 0, Time::Frequence(sourceFrequency,(Time::Frequence::frequencyUnitsEnum_t)measurementUnit), Time::Sample(Time::frequencyToPeriod(sourceFrequency),(Time::Sample::periodUnitsEnum_t)measurementUnit) };
    Timer::counterRegister_t postscaler = { postscalerSizeInBits, 0, Time::Frequence(sourceFrequency,(Time::Frequence::frequencyUnitsEnum_t)measurementUnit), Time::Sample(Time::frequencyToPeriod(sourceFrequency),(Time::Sample::periodUnitsEnum_t)measurementUnit) };

    deduceAction(prescaler.Size, desiredPrescalerFrequency, operation);
    deduceAction(timer.Size, desiredTimerFrequency, operation);
    deduceAction(postscaler.Size, desiredPostscalerFrequency, operation);

    switch (operation)
    {
        case Timer::PRESCALER:
        {
            bool isPrescalerOverwhelmed = Timer::frequencyToTicks(desiredPrescalerFrequency, prescaler.tick, oscilator.frequence.getCurrentFrequency(), prescalerSizeInBits);

            prescaler.frequence.setCurrentFrequency(Timer::ticksToFrequency(prescaler.tick, oscilator.frequence.getCurrentFrequency()));
            prescaler.sample.setCurrentPeriod(Time::frequencyToPeriod(prescaler.frequence.getCurrentFrequency()));

            if (isPrescalerOverwhelmed)
            {
                std::cout << "Prescaler is overwhelmed, you cannot the desired value with it's current size!\n";
                std::cout << "Prescaler size needed: " << ceil(log2(prescaler.tick + 1)) << " \n";
            }

            break;
        }
        case Timer::PRESCALER_TIMER:
        {
            bool isPrescalerOverwhelmed = Timer::frequencyToTicks(desiredPrescalerFrequency, prescaler.tick, oscilator.frequence.getCurrentFrequency(), prescalerSizeInBits);

            prescaler.frequence.setCurrentFrequency(Timer::ticksToFrequency(prescaler.tick, oscilator.frequence.getCurrentFrequency()));
            prescaler.sample.setCurrentPeriod(Time::frequencyToPeriod(prescaler.frequence.getCurrentFrequency()));

            if ((isPrescalerOverwhelmed) && (1 < prescalerSizeInBits))
            {
                std::cout << "Prescaler is overwhelmed, you cannot the desired value with it's current size!\n";
                std::cout << "Prescaler size needed: " << ceil(log2(prescaler.tick + 1)) << " \n";
            }

            bool isTimerOverwhelmed = Timer::frequencyToTicks(desiredTimerFrequency, timer.tick, prescaler.frequence.getCurrentFrequency(), timerSizeInBits);

            timer.frequence.setCurrentFrequency(Timer::ticksToFrequency(timer.tick, prescaler.frequence.getCurrentFrequency()));
            timer.sample.setCurrentPeriod(Time::frequencyToPeriod(timer.frequence.getCurrentFrequency()));

            if (isTimerOverwhelmed)
            {
                std::cout << "Timer is overwhelmed, you cannot the desired value with it's current size!\n";
                std::cout << "Timer size needed: " << ceil(log2(timer.tick + 1)) << " \n";
            }

            break;
        }
        case Timer::PRESCALER_TIMER_POSTSCALER:
        {
            bool isPrescalerOverwhelmed = Timer::frequencyToTicks(desiredPrescalerFrequency, prescaler.tick, oscilator.frequence.getCurrentFrequency(), prescalerSizeInBits);

            prescaler.frequence.setCurrentFrequency(Timer::ticksToFrequency(prescaler.tick, oscilator.frequence.getCurrentFrequency()));
            prescaler.sample.setCurrentPeriod(Time::frequencyToPeriod(prescaler.frequence.getCurrentFrequency()));

            if ((isPrescalerOverwhelmed) && (1 < prescalerSizeInBits))
            {
                std::cout << "Prescaler is overwhelmed, you cannot the desired value with it's current size!\n";
                std::cout << "Prescaler size needed: " << ceil(log2(prescaler.tick + 1)) << " \n";
            }

            bool isTimerOverwhelmed = Timer::frequencyToTicks(desiredTimerFrequency, timer.tick, prescaler.frequence.getCurrentFrequency(), timerSizeInBits);

            timer.frequence.setCurrentFrequency(Timer::ticksToFrequency(timer.tick, prescaler.frequence.getCurrentFrequency()));
            timer.sample.setCurrentPeriod(Time::frequencyToPeriod(timer.frequence.getCurrentFrequency()));

            if ((isTimerOverwhelmed) && (1 < timerSizeInBits))
            {
                std::cout << "Timer is overwhelmed, you cannot the desired value with it's current size!\n";
                std::cout << "Timer size needed: " << ceil(log2(timer.tick + 1)) << " \n";
            }

            bool isPostscalerOverwhelmed = Timer::frequencyToTicks(desiredPostscalerFrequency, postscaler.tick, timer.frequence.getCurrentFrequency(), postscalerSizeInBits);

            postscaler.frequence.setCurrentFrequency(Timer::ticksToFrequency(postscaler.tick, timer.frequence.getCurrentFrequency()));
            postscaler.sample.setCurrentPeriod(Time::frequencyToPeriod(postscaler.frequence.getCurrentFrequency()));

            if (!isPostscalerOverwhelmed)
            {
                std::cout << "Postscaler is overwhelmed, you cannot the desired value with it's current size!\n";
                std::cout << "Postscaler size needed: " << ceil(log2(postscaler.tick + 1)) << " \n";
            }

            break;
        }
        default:
        {
            std::cout << "Invalid operation detected, you can't expect an output from a non existent register. Check register size and desired output.\n";
            break;
        }
    }

    std::cout << "Prescaler ticks: " << prescaler.tick << "\n";
    std::cout << "Timer ticks: " << timer.tick << "\n";
    std::cout << "Postscaler ticks: " << postscaler.tick << "\n";

    std::cout << "Prescaler frequency: " << prescaler.frequence.getCurrentFrequency() << "\n";
    std::cout << "Timer frequency: " << timer.frequence.getCurrentFrequency() << "\n";
    std::cout << "Postscaler frequency: " << postscaler.frequence.getCurrentFrequency() << "\n";

    prescaler.sample.convertTo(Time::Sample::MILLISECOND);
    std::cout << "Prescaler sampling: " << prescaler.sample.getCurrentPeriod() << " " << prescaler.sample.getCurrentUnit() << "\n";
    std::cout << "Timer sampling: " << timer.sample.getCurrentPeriod() << "\n";
    std::cout << "Postscaler sampling: " << postscaler.sample.getCurrentPeriod() << "\n";


    return 0;
}
