#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(20, 20, 30) == NORMAL);
  REQUIRE(inferBreach(31, 20, 30) == TOO_HIGH);

  REQUIRE(inferBreach(0, 0, 10) == NORMAL);
  REQUIRE(inferBreach(-1, 0, 5) == TOO_LOW);
  REQUIRE(inferBreach(-3, -10, -5) == TOO_HIGH);
}


TEST_CASE("infers the breach according to limits of each cooling Type") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, (PASSIVE_COOLING_LOWER_LIMIT+1)) == NORMAL);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, (PASSIVE_COOLING_LOWER_LIMIT-1)) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, (PASSIVE_COOLING_HIGHER_LIMIT-1)) == NORMAL);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, (PASSIVE_COOLING_HIGHER_LIMIT+1)) == TOO_HIGH);
  
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, (HIACTIVE_COOLING_LOWER_LIMIT+1)) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, (HIACTIVE_COOLING_LOWER_LIMIT-1)) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, (HIACTIVE_COOLING_HIGHER_LIMIT-1)) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, (HIACTIVE_COOLING_HIGHER_LIMIT+1)) == TOO_HIGH);
  
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, (MEDACTIVE_COOLING_LOWER_LIMIT+1)) == NORMAL);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, (MEDACTIVE_COOLING_LOWER_LIMIT-1)) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, (MEDACTIVE_COOLING_HIGHER_LIMIT-1)) == NORMAL);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, (MEDACTIVE_COOLING_HIGHER_LIMIT+1)) == TOO_HIGH);  
}


TEST_CASE("Verify sending of allert to controller") {
  sendToController(TOO_LOW); 
  sendToController(TOO_HIGH);
  sendToController(NORMAL);
}

TEST_CASE("Verify check and allert funtion") {
	BatteryCharacter batterychar = {PASSIVE_COOLING, "PassiveNormal"};
   checkAndAlert(sendToController(TO_CONTROLLER, batteryChar, PASSIVE_COOLING_LOWER_LIMIT);
	BatteryCharacter batterychar1 = {PASSIVE_COOLING, "PassiveLow"};
   checkAndAlert(sendToController(TO_CONTROLLER, batteryChar1, (PASSIVE_COOLING_LOWER_LIMIT-1));
	BatteryCharacter batterychar2 = {PASSIVE_COOLING, "PassiveHIGH"};
   checkAndAlert(sendToController(TO_CONTROLLER, batteryChar2, (PASSIVE_COOLING_HIGHER_LIMIT+1));

	BatteryCharacter batterychar3 = {PASSIVE_COOLING, "PassiveNormal"};
   checkAndAlert(sendToController(TO_EMAIL, batteryChar3, PASSIVE_COOLING_LOWER_LIMIT); 
	BatteryCharacter batterychar4 = {PASSIVE_COOLING, "PassiveLow"};
   checkAndAlert(sendToController(TO_EMAIL, batteryChar4, (PASSIVE_COOLING_LOWER_LIMIT-1)); 
	BatteryCharacter batterychar5 = {PASSIVE_COOLING, "PassiveHIGH"};
   checkAndAlert(sendToController(TO_EMAIL, batteryChar5, (PASSIVE_COOLING_HIGHER_LIMIT+1));	
	
	BatteryCharacter batterychar6 = {HI_ACTIVE_COOLING, "HiactiveNormal"};
   checkAndAlert(sendToController(TO_CONTROLLER, batteryChar6, HIACTIVE_COOLING_LOWER_LIMIT);
	BatteryCharacter batterychar7 = {HI_ACTIVE_COOLING, "HiactiveLow"};
   checkAndAlert(sendToController(TO_CONTROLLER, batteryChar7, (HIACTIVE_COOLING_LOWER_LIMIT-1));
	BatteryCharacter batterychar8 = {HI_ACTIVE_COOLING, "HiactiveHIGH"};
   checkAndAlert(sendToController(TO_CONTROLLER, batteryChar8, (HIACTIVE_COOLING_HIGHER_LIMIT+1));

	BatteryCharacter batterychar9 = {HI_ACTIVE_COOLING, "HIactiveNormal"};
   checkAndAlert(sendToController(TO_EMAIL, batteryChar9, HIACTIVE_COOLING_LOWER_LIMIT);
	BatteryCharacter batterychar10 = {HI_ACTIVE_COOLING, "HiactiveeLow"};
   checkAndAlert(sendToController(TO_EMAIL, batteryChar10, (HIACTIVE_COOLING_LOWER_LIMIT-1));
	BatteryCharacter batterychar11 = {HI_ACTIVE_COOLING, "HiActiveHIGH"};
   checkAndAlert(sendToController(TO_EMAIL, batteryChar11, (HIACTIVE_COOLING_HIGHER_LIMIT+1));
	
	BatteryCharacter batterychar12 = {MED_ACTIVE_COOLING, "MedactiveNormal"};
   checkAndAlert(sendToController(TO_CONTROLLER, batteryChar12, MEDACTIVE_COOLING_LOWER_LIMIT);
	BatteryCharacter batterychar13 = {MED_ACTIVE_COOLING, "MedactiveLow"};
   checkAndAlert(sendToController(TO_CONTROLLER, batteryChar13, (MEDACTIVE_COOLING_LOWER_LIMIT-1));
	BatteryCharacter batterychar14 = {MED_ACTIVE_COOLING, "MedactiveHIGH"};
   checkAndAlert(sendToController(TO_CONTROLLER, batteryChar14, (MEDACTIVE_COOLING_HIGHER_LIMIT+1));

	BatteryCharacter batterychar15 = {MED_ACTIVE_COOLING, "MedactiveNormal"};
   checkAndAlert(sendToController(TO_EMAIL, batteryChar16, MEDACTIVE_COOLING_LOWER_LIMIT);
	BatteryCharacter batterychar16 = {MED_ACTIVE_COOLING, "MedactiveeLow"};
   checkAndAlert(sendToController(TO_EMAIL, batteryChar17, (MEDACTIVE_COOLING_LOWER_LIMIT-1));
	BatteryCharacter batterychar17 = {MED_ACTIVE_COOLING, "MedActiveHIGH"};
   checkAndAlert(sendToController(TO_EMAIL, batteryChar18, (MEDACTIVE_COOLING_HIGHER_LIMIT+1));
}
