#include <Arduino.h>
#include "Constants.h"
#include "PID/pid.h"
#include <Math.h>


pid *p = new pid(1, 2, 3);


turretMode* currentMode = (turretMode*) malloc(sizeof(turretMode));

void setup() {
    Serial.begin(115200);
    pinMode(REV_ENCODER_PIN, INPUT);
    *currentMode = PID;


// write your initialization code here
}

double getRevEncoderReading() {
    long highTime = pulseIn(REV_ENCODER_PIN, HIGH);
    long lowTime  = pulseIn(REV_ENCODER_PIN, LOW);

    float duty = (float)highTime / (highTime + lowTime);


    return  duty * 360.0 * TURRET_GEARING;
}

double getTurretTarget() {
    return 0;
}

void handleTurretPid() {
    double error = getTurretTarget() - getRevEncoderReading();
    analogWrite(POSITION_MOTOR_PIN,  p->calculate(error));
}

double getControllerInput() {
    return 0.1;
}
void handleTurretManual() {
    analogWrite(POSITION_MOTOR_PIN, getControllerInput());
}

void loop() {
    switch (*currentMode) {
        case PID :
            handleTurretPid();
        case CONTROLLER:
            handleTurretManual();

    }
}



