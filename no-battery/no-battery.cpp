#include "Particle.h"

void setCharging(bool enable);

void setup() {
	Serial.begin(9600);
	setCharging(false);
}

void loop() {

}

void setCharging(bool enable) {

	PMIC pmic;

	// DisableCharging turns off charging.
	// DisableBATFET completely disconnects the battery.
	if (enable) {
		pmic.enableCharging();
		pmic.enableBATFET();
	}
	else {
		pmic.disableCharging();
		pmic.disableBATFET();
	}

	// Disabling the PMIC watchdog is necessary, otherwise it will kick in and turns
	// charging at random times, even when sleeping.

	// This disables both the watchdog and the charge safety timer in
	// Charge Termination/Timer Control Register REG05
	// pmic.disableWatchdog() disables the watchdog, but doesn't disable the
	// charge safety timer, so the red LED will start blinking slowly after
	// 1 hour if you don't do both.
	byte DATA = pmic.readChargeTermRegister();

	if (enable) {
		DATA |= 0b00111000;
	}
	else {
		// 0b11001110 = disable watchdog
		// 0b11000110 = disable watchdog and charge safety timer
		DATA &= 0b11000110;
	}

	// This would be easier if pmic.writeRegister wasn't private (or disable
	// charge safety timer had an exposed method
	Wire3.beginTransmission(PMIC_ADDRESS);
	Wire3.write(CHARGE_TIMER_CONTROL_REGISTER);
	Wire3.write(DATA);
	Wire3.endTransmission(true);

}
