#include "Particle.h"

// Resets bq24195 charge controller

void writeRegister(uint8_t reg, uint8_t value);

void setup() {
	Serial.begin(9600);

	// REG00 Input Source Control Register
	writeRegister(0, 0b00110000);

	// REG01 Power-On Configuration Register
	writeRegister(1, 0b00011011);

	// REG02 Charge Current Control Register
	writeRegister(2, 0b01100000);

	// REG03 Pre-Charge/Termination Current Control Register
	writeRegister(3, 0b00010001);

	// REG04 Charge Voltage Control Register Format
	writeRegister(4, 0b10110010);

	// REG05 Charge Termination/Timer Control Register
	writeRegister(5, 0b10011010);

	// REG06 Thermal Regulation Control Register
	writeRegister(6, 0b00000011);

	// REG07 Misc Operation Control Register Format
	writeRegister(7, 0b01001011);

}

void loop() {

}


void writeRegister(uint8_t reg, uint8_t value) {
	// This would be easier if pmic.writeRegister wasn't private
	Wire3.beginTransmission(PMIC_ADDRESS);
	Wire3.write(reg);
	Wire3.write(value);
	Wire3.endTransmission(true);

}
