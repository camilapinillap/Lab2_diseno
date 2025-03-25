int rele = 6;
int ledAzul = 11;
int ledVerde = 9;
int ledRojo = 10;

#define PIN_SENSOR A0
int ValorTemp, ValorMv, ValorPWM;
void setup() {
  Serial.begin(9600);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(rele, OUTPUT);
}

void loop() {
  ValorTemp = analogRead(PIN_SENSOR);

  ValorMv = map(ValorTemp, 0, 1023, 0, 5000);
  ValorPWM = ValorMv / 10;
  Serial.println(ValorPWM);
  if (ValorPWM <= 21) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledAzul, LOW);
    digitalWrite(rele, HIGH);
    
  }
  else if (ValorPWM > 22 && ValorPWM < 24) {
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo, LOW);
    digitalWrite(rele, HIGH);
    
  }
  else if (ValorPWM >= 25) {
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(rele, LOW);
    Serial.println("Encender Ventilador");
    
  }

}