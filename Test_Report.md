# Test Report — LAPS

**Versión del documento:** 0.1  
**Estado:** Borrador inicial

## 1. Objetivo
Validar que el prototipo cumple los requisitos definidos en `Requirements.md`.

## 2. Equipo y banco de pruebas
- Fuente 12 V 5 A o panel 12 V–35 W.
- Multímetro/pinza amperimétrica, cronómetro.
- Superficie acrílica/panel con polvo controlado.
- Cámara o balanza para evidencia antes/después.

## 3. Procedimientos

### T-001 — Tiempo de ciclo (REQ-F-001)
1. Preparar sistema en posición inicial.
2. Iniciar ciclo y cronometrar.
3. Registrar duración total.
**Criterio:** ≤ 90 s.

### T-002 — Eficacia de limpieza (REQ-F-002)
1. Documentar estado inicial (foto o masa de polvo).
2. Ejecutar una pasada estándar.
3. Documentar estado final.
**Criterio:** polvo residual ≤ 10%.

### T-003 — Potencia pico (REQ-NF-001)
1. Medir V y A máximos durante el ciclo.
2. Calcular Ppico = V·A.
**Criterio:** ≤ 36 W.

### T-004 — Protección y reversos (REQ-SEG-001)
1. Verificar diodos flyback y fusible.
2. Observar con osciloscopio al apagar cargas.
**Criterio:** sin picos inversos peligrosos.

### T-005 — Mantenimiento rápido (REQ-MNT-001)
1. Simular recambio de escobilla.
**Criterio:** < 10 min.

## 4. Resultados
| TEST-ID | Fecha | Resultado | Evidencia |
|---------|-------|-----------|-----------|
| T-001   | yyyy-mm-dd | Pendiente |  |
| T-002   | yyyy-mm-dd | Pendiente |  |
| T-003   | yyyy-mm-dd | Pendiente |  |
| T-004   | yyyy-mm-dd | Pendiente |  |
| T-005   | yyyy-mm-dd | Pendiente |  |

## 5. Observaciones y acciones
- Pendiente añadir mediciones de corriente por fase.
- Registrar temperatura de motores y servos si se calientan.
