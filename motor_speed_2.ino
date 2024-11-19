//// this is to test the pwm output of your DRV8833 driver via esp32
// Define pins
#define MOTOR_IN1 14
#define MOTOR_IN2 27

// PWM properties
const int freq = 5000;
const int pwmChannel = 0;
const int resolution = 8;
const int maxSpeed = 255;
const int delayTime = 10; // Time in ms between each speed change for smooth ramp

void setup() {
  // Set motor control pins as outputs
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);

  // Configure PWM
  ledcAttach(MOTOR_IN2, freq, resolution);


  // Ensure motor is stopped initially
  digitalWrite(MOTOR_IN1, LOW);
  ledcWrite(pwmChannel, 0);
}

void loop() {
  // Ramp up speed from 0% to 100% clockwise
  digitalWrite(MOTOR_IN1, HIGH); // Set clockwise direction
  for (int speed = 0; speed <= maxSpeed; speed++) {
    ledcWrite(pwmChannel, speed); // Increase speed
    delay(delayTime);
  }

  // Ramp down speed from 100% to 0% counterclockwise
  digitalWrite(MOTOR_IN1, LOW); // Set counterclockwise direction
  for (int speed = maxSpeed; speed >= 0; speed--) {
    ledcWrite(pwmChannel, speed); // Decrease speed
    delay(delayTime);
  }
}
