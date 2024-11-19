const int pwmPin = 23;         // GPIO pin for PWM output
const int pwmFrequency = 1000; // PWM frequency in Hz
const int pwmResolution = 8;   // PWM resolution in bits (8 bits = 0-255 duty cycle)

// For 8-bit resolution, the max duty cycle value is 255
const int dutyCycle = 127; // 50% duty cycle

void setup() {
  // Configure PWM using the new ledcAttach function
  ledcAttach(pwmPin, pwmFrequency, pwmResolution);

  // Set the duty cycle to 50%
  ledcWrite(pwmPin, dutyCycle);
}

void loop() {
  // No need for code in loop, PWM output is continuous
}
