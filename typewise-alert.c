#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) 
{
  if(value < lowerLimit)
  {
    return TOO_LOW;
  }
  else if(value > upperLimit) 
  {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) 
{
  int lowerLimit = 0;
  int upperLimit = 0;
  if (coolingType == PASSIVE_COOLING) 
  {
      lowerLimit = PASSIVE_COOLING_LOWER_LIMIT;
      upperLimit = PASSIVE_COOLING_HIGHER_LIMIT;
  }	
  else if (coolingType == HI_ACTIVE_COOLING)
  {
      lowerLimit = HIACTIVE_COOLING_LOWER_LIMIT;
      upperLimit = HIACTIVE_COOLING_HIGHER_LIMIT;
  }
  else
  {  
      lowerLimit = MEDACTIVE_COOLING_LOWER_LIMIT;
      upperLimit = MEDACTIVE_COOLING_LOWER_LIMIT;
  }
  
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  switch(alertTarget)
  {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  switch(breachType) {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
    default	:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is normal\n");
      break;
  }
}
