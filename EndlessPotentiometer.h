#pragma once

class EndlessPotentiometer {
public:
	EndlessPotentiometer(float, int);
	~EndlessPotentiometer();
	float getAngle(int, int);
	float getStep();
private:
	float mAngleStep;
	uint8_t mSamples;
};

EndlessPotentiometer::EndlessPotentiometer(float step, int samples) {
	mAngleStep = step;
	mSamples = samples;
}

EndlessPotentiometer::~EndlessPotentiometer() {

}

float EndlessPotentiometer::getAngle(int pinA, int pinB) {
	float adc1, adc2, x, y, atanResult;
	adc1 = adc2 = 0;
	for (int i = 0; i < mSamples; i++) {
		adc1 += analogRead(pinA);
		adc2 += analogRead(pinB);
	}
	adc1 = adc1 / mSamples;
	adc2 = adc2 / mSamples;
	x = ((512 - adc2) / 512);
	y = ((512 - adc1) / 512);
	atanResult = atan2(y, x);
	atanResult *= 180 / PI;
	atanResult += 180;
	return atanResult;
}

float EndlessPotentiometer::getStep() {
	return mAngleStep;
}

EndlessPotentiometer pot(2.07f, 2);
