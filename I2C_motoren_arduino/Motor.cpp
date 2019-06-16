#include "Arduino.h"
#include "Motor.h"

#define NORMAL_SPEED 100

Motor::Motor(int pin_d, int pin_in1, int pin_in2, int pin_fb, int pin_sf) {
  _pin_d = pin_d;
  _pin_in1 = pin_in1;
  _pin_in2 = pin_in2;
  _pin_fb = pin_fb;
  _pin_sf = pin_sf;
  pinMode(_pin_d, OUTPUT);
  pinMode(_pin_in1, OUTPUT);
  pinMode(_pin_in2, OUTPUT);
  pinMode(_pin_fb, INPUT);
  pinMode(_pin_sf, INPUT);
}

void Motor::setupInterruptHandler(void (*ISR)(void), int value) {
  attachInterrupt(digitalPinToInterrupt(_pin_sf), ISR, RISING);
}

void Motor::vor() {
  digitalWrite(_pin_in1, HIGH);
  digitalWrite(_pin_in2, LOW);
  analogWrite(_pin_d, NORMAL_SPEED);
}

void Motor::vor(int speed) {
  digitalWrite(_pin_in1, HIGH);
  digitalWrite(_pin_in2, LOW);
  analogWrite(_pin_d, speed);
}

void Motor::zurueck() {
  digitalWrite(_pin_in1, LOW);
  digitalWrite(_pin_in2, HIGH);
  analogWrite(_pin_d, NORMAL_SPEED);
}

void Motor::zurueck(int speed) {
  digitalWrite(_pin_in1, LOW);
  digitalWrite(_pin_in2, HIGH);
  analogWrite(_pin_d, speed);
}

float Motor::get_current() {
  return analogRead(_pin_fb) / ( 1023 /(5 * 0.55));
}