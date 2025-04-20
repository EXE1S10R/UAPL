const int sensorPin = A0;  // Пин, к которому подключен фотодиод

void setup() {
  Serial.begin(115200);
  Serial.println("Считывание значений фотодиода...");
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Читаем значение
  Serial.println(sensorValue); // Выводим в монитор порта
  
  delay(200); // Задержка для удобства чтения
}
