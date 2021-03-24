#ifndef __CONFIG_8S003_H
#define __CONFIG_8S003_H

#include "stm8.h"

#define EEPROM_START_PTR                0x4000

#define HSI_RC_CLOCK_SPEED              16000000UL  // 16MHz
#define DEFAULT_SYSTEM_CORE_CLOCK       2000000UL   // 2MHz

#define ADC1_ISR                        ADC1_EOC_vector
#define TIM2_ISR                        TIM2_OVR_UIF_vector

#define SEVEN_SEG_COMMON_CATHODE        1
#define SEVEN_SEG_COMMON_ANODE          2


//#define BOARD_HW_V1
//#define BOARD_HW_V2
#define BOARD_HW_V3

/**
 * PDF from UpcycleElectronics states a common anode display, but
 * mine is a common cathode.
 * Use either COMMON_CATHODE or COMMON_ANODE.
 */
#if defined(BOARD_HW_V2) || defined(BOARD_HW_V1)
#define DISPLAY_TYPE                    SEVEN_SEG_COMMON_CATHODE
#elif defined(BOARD_HW_V3)
#define DISPLAY_TYPE                    SEVEN_SEG_COMMON_ANODE
#else
#error defined BOARD_HW_V?
#endif

#define ADC_SCALE                       (3.3 / 1024.0)

/* Resistance value for the combined elements R3 and RV2 from the sch */
#if defined(BOARD_HW_V2) || defined(BOARD_HW_V1)
#define AMPS_RV2                        20000.0
#define AMPS_R3                         180000.0
#elif defined(BOARD_HW_V3)
#define AMPS_RV2                        4700.0
#define AMPS_R3                         47000.0
#else
#error defined BOARD_HW_V?
#endif
#define AMPS_R3_RV2                     (AMPS_R3+(AMPS_RV2/2))

/* Resistance value for R4 from the sch */
#if defined(BOARD_HW_V2) || defined(BOARD_HW_V1)
#define AMPS_R4                         8200.0
#elif defined(BOARD_HW_V3)
#define AMPS_R4                         4200.0
#else
#error defined BOARD_HW_V?
#endif

/* Resistance value for the on-board shunt */
#if defined(BOARD_HW_V2) || defined(BOARD_HW_V1)
#define AMPS_SHUNT                      0.02
#elif defined(BOARD_HW_V3)
#define AMPS_SHUNT                      1.6
#else
#error defined BOARD_HW_V?
#endif
/* Non-inverting OpAmp formula */
#define GAIN_FOR_AMPS                   (((1 + (AMPS_R3_RV2 / AMPS_R4)) / AMPS_SHUNT) * ADC_SCALE)

/* Resistance value for the combined elements R2 and RV1 from the sch */
#if defined(BOARD_HW_V2) || defined(BOARD_HW_V1)
#define VOLTS_RV1                       20000.0
#define VOLTS_R2                        270000.0
#elif defined(BOARD_HW_V3)
#define VOLTS_RV1                       4200.0
#define VOLTS_R2                        72000.0
#else
#error defined BOARD_HW_V?
#endif
#define VOLTS_R2_RV1                    (VOLTS_R2+(VOLTS_RV1/2))

/* Resistance value for R1 from the sch */
#if defined(BOARD_HW_V2) || defined(BOARD_HW_V1)
#define VOLTS_R1                        8200.0
#elif defined(BOARD_HW_V3)
#define VOLTS_R1                        2200.0
#else
#error defined BOARD_HW_V?
#endif
/* Voltage divider formula */
#define GAIN_FOR_VOLTAGE                (((VOLTS_R1 + VOLTS_R2_RV1) / VOLTS_R1) * ADC_SCALE)


#endif /* __CONFIG_8S003_H */