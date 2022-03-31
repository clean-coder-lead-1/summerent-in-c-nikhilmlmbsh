#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

#define PASSIVE_COOLING_LOWER_LIMIT  	0
#define PASSIVE_COOLING_HIGHER_LIMIT 	35
#define HIACTIVE_COOLING_LOWER_LIMIT 	0
#define HIACTIVE_COOLING_HIGHER_LIMIT 	45
#define MEDACTIVE_COOLING_LOWER_LIMIT 	0
#define MEDACTIVE_COOLING_HIGHER_LIMIT 	40

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
