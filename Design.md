# Design — LAPS

**Versión del documento:** 0.1  
**Estado:** Borrador inicial

## 1. Arquitectura de alto nivel
- **Control:** Arduino Nano.
- **Potencia:** 12 V de entrada; LM2596 a 5 V; L298N para motores DC; MOSFET para bomba.
- **Actuadores:** 2× Motores TT, 2× Servos MG90S, Bomba R365.
- **Protecciones:** diodos flyback, zener, capacitores, fusible.
- **Usuario:** 2 interruptores (lógica y potencia).

## 2. Diagrama de bloques (ASCII)
```
[12V DC] ──> [Fusible] ──>┬─────────> [Bomba R365 + MOSFET]
                          ├─> [LM2596 5V] ──> [Arduino Nano] ──> [Servos]
                          └─> [L298N] <──── [Arduino Nano PWM/DIR] ──> [Motores TT]
GND común en todos los módulos. Diodos flyback en cargas inductivas.
```

## 3. Flujo de energía
- 12 V alimenta Bomba y L298N.
- LM2596 convierte a 5 V para Arduino y Servos.
- Separar retorno de potencia y lógica hasta estrella de GND.

## 4. Máquina de estados
```
IDLE -> ROCIAR -> BAJAR_ESCOBILLA -> BARRER -> SUBIR_ESCOBILLA -> RETORNO -> IDLE
Eventos: tiempo agotado, tope mecánico (futuro), emergencia.
```

## 5. Mapa de pines
| Función        | Pin Arduino |
|----------------|-------------|
| Bomba (MOSFET) | A2          |
| Servo 1        | D11         |
| Servo 2        | D10         |
| Motor A ENA    | D6          |
| Motor A IN1    | A1          |
| Motor A IN2    | D7          |
| Motor B ENB    | D5          |
| Motor B IN3    | A5          |
| Motor B IN4    | A3          |

## 6. Justificación de diseño
- L298N por disponibilidad y simplicidad para motores TT (bajo par).
- MOSFET IRFZ44N para conmutar la bomba 12 V.
- LM2596 por eficiencia frente a 7805.

## 7. Interfaces
- Eléctricas: 12 V DC in; 5 V DC; GND común; headers Dupont.
- Usuario: switches de emergencia; puerto serie para logs.

## 8. Plan de mejoras
- Encoders o fin de carrera.
- Carcasa IP para intemperie.
- Telemetría y detección de lluvia/polvo.
