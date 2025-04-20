#include <SoftwareSerial.h>

SoftwareSerial BTserial(10, 11); // RX | TX для HC-05

#define SENSOR1_PIN A0  // Первый фотодиод (вход)
#define SENSOR2_PIN A1  // Второй фотодиод (выход)
#define THRESHOLD 78    // Порог срабатывания датчика
#define TIMEOUT 1500    // Тайм-аут на прохождение человека (1.5 секунды)

int peopleCount = 0;
int peopleCounta = 0;
unsigned long sensorTriggerTime = 0;  // Время срабатывания первого датчика

// Состояния системы
enum State {
  IDLE,
  ENTRY_PHASE, // Сработал датчик 1, ждём срабатывания датчика 2 и восстановления датчика 1
  EXIT_PHASE   // Сработал датчик 2, ждём срабатывания датчика 1 и восстановления датчика 2
};

State currentState = IDLE;

void setup() {
  Serial.begin(9600);
  BTserial.begin(9600); // Инициализация Bluetooth-модуля HC-05

  Serial.println("Система подсчёта людей запущена");
  Serial.print("Людей в помещении: ");
  Serial.println(peopleCount);
  
  BTserial.println("System started");
}

void loop() {
  int sensor1_value = analogRead(SENSOR1_PIN);
  int sensor2_value = analogRead(SENSOR2_PIN);
  unsigned long currentTime = millis();  // Текущее время

  switch (currentState) {
    case IDLE:
      if (sensor1_value < THRESHOLD) {
        currentState = ENTRY_PHASE;
        sensorTriggerTime = currentTime;
        Serial.println("Начало входа (пересечён первый датчик)");
      } 
      else if (sensor2_value < THRESHOLD) {
        currentState = EXIT_PHASE;
        sensorTriggerTime = currentTime;
        Serial.println("Начало выхода (пересечён второй датчик)");
      }
      break;

    case ENTRY_PHASE:
      if (sensor2_value < THRESHOLD) {
        Serial.println("Вход подтверждён");

        while (analogRead(SENSOR1_PIN) < THRESHOLD) {
          delay(10);
        }

        peopleCount++;
        peopleCounta++;
        Serial.println("Человек вошёл");
        BTserial.println("Entered");
        
        Serial.print("Людей в помещении: ");
        Serial.println(peopleCount);
        Serial.println(peopleCounta);
        BTserial.print("People in place: ");
        BTserial.println(peopleCount);
        BTserial.println(peopleCounta);

        currentState = IDLE;
      }
      else if (currentTime - sensorTriggerTime > TIMEOUT) {
        Serial.println("Ошибка: Тайм-аут, сброс состояния");
        currentState = IDLE;
      }
      break;

    case EXIT_PHASE:
      if (sensor1_value < THRESHOLD) {
        Serial.println("Выход подтверждён");

        while (analogRead(SENSOR2_PIN) < THRESHOLD) {
          delay(10);
        }

        if (peopleCount > 0) {
         peopleCount--;
        }

        Serial.println("Человек вышел");
        BTserial.println("Exited");

        Serial.print("Людей в помещении: ");
        Serial.println(peopleCount);
        BTserial.print("People in place: ");
        BTserial.println(peopleCount);

        currentState = IDLE;
      }
      else if (currentTime - sensorTriggerTime > TIMEOUT) {
        Serial.println("Ошибка: Тайм-аут, сброс состояния");
        currentState = IDLE;
      }
      break;
  }

  delay(100);
}