#define RAIN_SENSOR_PIN 2  // Rain Sensor connected to D2
#define ENA 9   // Enable Motor 1
#define IN1 3   // Motor 1 - Input 1
#define IN2 4   // Motor 1 - Input 2
#define ENB 10  // Enable Motor 2
#define IN3 5   // Motor 2 - Input 1
#define IN4 6   // Motor 2 - Input 2

int lastRainState = HIGH;  // Stores the last sensor state

void setup() {
  Serial.begin(9600);
  
  pinMode(RAIN_SENSOR_PIN, INPUT);
  
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Enable motors with full speed
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  Serial.println("System Ready...");
}

void loop() {
  int rainState = digitalRead(RAIN_SENSOR_PIN);

  // Only react if the rain state changes
  if (rainState != lastRainState) {
    lastRainState = rainState;  // Update the stored state

    if (rainState == LOW) {  
      Serial.println("🌧 Rain Detected! Rotating Clockwise...");
      rotateClockwise();
      delay(10000);  // Run motors for 10 seconds
    } 
    else {  
      Serial.println("☀️ No Rain! Rotating Anti-Clockwise...");
      rotateAntiClockwise();
      delay(10000);  // Run motors for 10 seconds
    }

    Serial.println("🛑 Motors Stopped. Waiting for change...");
    stopMotors();
  }
}

// Rotates motors in clockwise direction
void rotateClockwise() {
  Serial.println("➡️ Motor Rotating Clockwise");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Rotates motors in anti-clockwise direction
void rotateAntiClockwise() {
  Serial.println("⬅️ Motor Rotating Anti-Clockwise");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Stops the motors
void stopMotors() {
  Serial.println("🛑 Motors Stopped");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
