# Requirements — LAPS

**Versión del documento:** 0.1  
**Estado:** Borrador inicial

## 1. Alcance
Este documento captura los requisitos del prototipo LAPS. Sirve como base para verificación y cambios de diseño.

## 2. Definiciones
- REQ-F-*: Requisitos funcionales.
- REQ-NF-*: No funcionales.
- REQ-INT-*: Interfaz.
- REQ-SEG-*: Seguridad.
- REQ-MNT-*: Mantenibilidad.

## 3. Requisitos

### 3.1 Funcionales
- **REQ-F-001**: Ejecutar ciclo completo de limpieza en ≤ 90 s.
- **REQ-F-002**: Remover ≥ 90% de polvo visible en una pasada típica.
- **REQ-F-003**: Paro de emergencia independiente para lógica y potencia de motores.
- **REQ-F-004**: Configuración por software de tiempos de bomba, PWM y ángulos de servos.

### 3.2 No funcionales
- **REQ-NF-001**: Potencia pico del sistema ≤ 36 W.
- **REQ-NF-002**: Masa del módulo móvil ≤ 1.5 kg (objetivo prototipo).
- **REQ-NF-003**: Operación segura entre 10–40 °C y HR 20–80% (sin IP).

### 3.3 Interfaz
- **REQ-INT-001**: Alimentación 12 V DC; regulación a 5 V para lógica/actuadores.
- **REQ-INT-002**: Puerto serie para logs y ajuste de parámetros.

### 3.4 Seguridad
- **REQ-SEG-001**: Diodos flyback en cargas inductivas y fusible en la línea de 12 V.

### 3.5 Mantenibilidad
- **REQ-MNT-001**: Reemplazo de escobilla y acceso a conectores en < 10 min.

## 4. Trazabilidad REQ→TEST
| REQ         | TEST-ID | Método             | Criterio |
|-------------|---------|--------------------|----------|
| REQ-F-001   | T-001   | Cronometrar ciclo  | ≤ 90 s   |
| REQ-F-002   | T-002   | Imagen/Pesaje      | ≤ 10%    |
| REQ-NF-001  | T-003   | Corriente/Voltaje  | ≤ 36 W   |
| REQ-SEG-001 | T-004   | Inspección/Scope   | OK       |
| REQ-MNT-001 | T-005   | Ensayo de recambio | < 10 min |

## 5. Pendientes
- Definir masas y márgenes reales del prototipo.
- Completar requisitos ambientales si habrá intemperie (IP, UV, lluvia).
