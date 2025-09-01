#include <Servo.h>

// Creacion de las variables para los Servos
Servo miServo1;
Servo miServo2;

// Pin de entrada de la bomba
const int pinBomba = A2;

// Variable velocidad de los motores
const int bajaVelocidad = 175;

// Motor A (TT 1)
const int ENA = 6;
const int IN1 = A1;
const int IN2 = 7;

// Motor B (TT 2)
const int ENB = 5;l
const int IN3 = A5;
const int IN4 = A3;

void setup() {
  // Set up de los Servos
  miServo1.attach(11);
  miServo2.attach(10);
  miServo1.write(0);
  miServo2.write(0);

  // Set up de la bomba
  pinMode(pinBomba, OUTPUT);
  digitalWrite(pinBomba, LOW);

  // Set up de los motores
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pararMotores(); // Se los inicia apagados
}

void loop() {

  delay(5000); // Espera inicial de seguridad

  // Primer proceso: Encender bomba para lubricar superficie
  digitalWrite(pinBomba, HIGH);

  // Segundo proceso: Desplazamiento horizontal
  for (int i = 0; i < 2; i++) {
    moverMotores(true, 2000);    // Adelante 2 s
    pararMotores();
    delay(1500);                 // Pausa 1.5 s

    moverMotores(false, 2000);   // Atrás 2 s
    pararMotores();
    delay(1500);                 // Pausa 1.5 s
  }
  moverMotores(true, 2000);    // Adelante 2 s

  // Apagar bomba y motores
  digitalWrite(pinBomba, LOW);
  pararMotores();

  // Tercer proceso: Bajar escobilla para empezar secado
  // Previo al movimiento para evitar sobrecorriente
  for (int pos = 0; pos <= 180; pos++) {
    miServo1.write(pos);
    miServo2.write(pos);
    delay(20);
  }
  delay(2000);

  // Cuarto proceso: Motores atrás 2s (limpieza con escobilla)
  moverMotores(false, 2000);
  pararMotores();

  // Final: Subir escobilla
  for (int pos = 180; pos >= 0; pos--) {
    miServo1.write(pos);
    miServo2.write(pos);
    delay(20);
  }

  // Repetir ciclo
}

// Función para mover motores con polaridad invertida en Motor B
void moverMotores(bool adelante, int tiempoMs) {
  if (adelante) {
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);   // Motor A adelante
    digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);  // Motor B adelante
  } else {
    digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);  // Motor A atrás
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);   // Motor B atrás
  }
  analogWrite(ENA, bajaVelocidad);
  analogWrite(ENB, bajaVelocidad);
  delay(tiempoMs);
}

// Función para parar motores
void pararMotores() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}
