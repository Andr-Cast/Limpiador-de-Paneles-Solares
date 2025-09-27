# LAPS — Limpiador Automatizado de Paneles Solares

**Versión:** v1.0-prototipo  
**Estado:** Prototipo funcional  
**Responsable:** Andre Castillo — castilloworkspace@gmail.com

---

## 1. Propósito
Automatizar la limpieza periódica de paneles solares domésticos para mantener la eficiencia sin riesgo humano ni costos recurrentes.

## 2. Alcance
**Incluye:** limpieza con rociado, desplazamiento lineal y escurrido con escobilla, controlado por Arduino.  
**Excluye:** carcasa IP sellada, integración estructural definitiva al bastidor del panel y telemetría remota.

## 3. Concept of Operations (ConOps)
1. Activa bomba y rocía la superficie.
2. Baja escobilla con servos.
3. Desplaza el sistema con motores DC para cubrir el panel.
4. Escurre y retorna a la posición inicial.
**Frecuencia:** cada 4 días. **Duración:** ≈ 1 min por ciclo.  
**Modos:** Automático | Manual | Emergencia.  
**Criterio de éxito:** superficie con ≤ 10% de polvo residual y sin acumulación de agua.

## 4. Requisitos (propuestos)
- **REQ-F-001**: Ejecutar ciclo completo de limpieza en ≤ 90 s.  
- **REQ-F-002**: Remover ≥ 90% de polvo visible en una pasada típica.  
- **REQ-F-003**: Disponer de paro de emergencia independiente para lógica y potencia de motores.  
- **REQ-F-004**: Permitir configurar por software tiempos de bomba, PWM y ángulos de servos.  
- **REQ-NF-001**: Potencia pico del sistema ≤ 36 W.  
- **REQ-NF-002**: Masa del módulo móvil ≤ 1.5 kg (objetivo de prototipo).  
- **REQ-NF-003**: Operación segura entre 10–40 °C y HR 20–80% (sin clasificación IP).  
- **REQ-INT-001**: Alimentación 12 V DC y regulación a 5 V para lógica/actuadores.  
- **REQ-SEG-001**: Diodos flyback en cargas inductivas y fusible en la línea de 12 V.  
- **REQ-MNT-001**: Reemplazo de escobilla y acceso a conectores en < 10 min.

## 5. Métricas de desempeño
- Polvo residual objetivo: ≤ 10%.  
- Tiempo por ciclo: ≤ 90 s.  
- Consumo por ciclo: registrar Wh y picos de corriente.  
- Ruido y vibración: cualitativo en prototipo, cuantificar en V&V.

## 6. Arquitectura del sistema
- **Control:** Arduino Nano.  
- **Potencia:** 12 V de entrada; LM2596 a 5 V; L298N para motores DC; MOSFET para bomba.  
- **Mecánico:** chasis, ruedas, escobilla, guías.  
- **Protección:** diodos flyback, zener, capacitores de desacople, fusible.

```
LAPS/
├─ docs/
│  ├─ Requirements.md
│  ├─ Design.md
│  └─ Test_Report.md
├─ hardware/
│  ├─ esquematico.pdf
│  └─ BOM.csv
├─ software/
│  └─ sketch_mar29a_LAPS.ino
└─ media/
   └─ wiring.png
```

## 7. Hardware
- Arduino Nano  
- Driver L298N  
- 2 × Motores TT (5 V)  
- 2 × Servos MG90S (5 V)  
- Bomba R365 (12 V)  
- Regulador LM2596  
- Panel 12 V–35 W o fuente 12 V 3–5 A  
- Auxiliares: MOSFET IRFZ44N, diodos, zener, capacitores 1000 µF, cableado

### Presupuesto de potencia (estimado)
- Bomba R365: 12 V × 0.8 A ≈ **9.6 W**  
- 2 × Motores TT: 5 V × 0.6 A c/u ≈ **6 W**  
- 2 × Servos MG90S: 5 V × 0.7 A pico c/u ≈ **7 W**  
- Lógica + pérdidas ≈ **1–2 W**  
**Total pico estimado:** 24–26 W 〈 36 W (margen OK).  
> Actualizar con mediciones reales en V&V.

### Mapa de pines
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

> Añadir esquema eléctrico y calibre de cable en `hardware/` y una imagen de cableado en `media/wiring.png`.

## 8. Software / Firmware
- **Entorno:** Arduino IDE. Lenguaje C/C++. Librería `Servo.h`.  
- **Máquina de estados:** `Rociar → Bajar escobilla → Avanzar/Retroceder → Subir escobilla → Paro`.  
- **Parámetros configurables:** PWM motores (`bajaVelocidad`), tiempos de fase, ángulos de servos.  
- **Gestión de fallos:** `pararMotores()`, neutral de servos, bomba OFF por defecto, doble paro físico.

## 9. Interfaces
- **Eléctricas:** entrada 12 V, 5 V regulado; conectores DC; GND común.  
- **Usuario:** 2 interruptores físicos (lógica y potencia motores).  
- **Datos:** Puerto serie para logs y ajuste de parámetros.

## 10. Seguridad y riesgos
- **Riesgos:** atrapamiento mecánico, sobrecorriente, salpicaduras.  
- **Salvaguardas:** fusible 12 V, diodos flyback, tope mecánico, prueba en seco previa, paro doble.  
- **PPE para pruebas:** guantes, lentes.

## 11. Verificación y validación
**Trazabilidad REQ→TEST (extracto):**

| REQ         | Prueba                       | Criterio de aceptación |
|-------------|------------------------------|------------------------|
| REQ-F-001   | Cronometrar ciclo            | ≤ 90 s                 |
| REQ-F-002   | Imagen/pesaje antes-después  | ≤ 10% residual         |
| REQ-NF-001  | Pinza A + voltímetro         | Ppico ≤ 36 W           |
| REQ-SEG-001 | Osciloscopio en cargas       | Sin picos inversos     |
| REQ-MNT-001 | Simular recambio de escobilla| < 10 min               |

Registrar resultados en `docs/Test_Report.md`.

## 12. Operaciones y mantenimiento
- **Instalación:** fijar rieles, alinear ruedas alta/baja del techo, verificar tensiones.  
- **Uso:** energizar 12 V, ejecutar ciclo automático; revisar que no quede agua acumulada.  
- **Mantenimiento:** limpiar escobilla, revisar conexiones, reemplazo según desgaste.

## 13. Limitaciones y trabajo futuro
- Sin carcasa IP para intemperie.  
- Sin encoders ni fin de carrera; pendiente sensado de posición.  
- Pendiente integración de lluvia/polvo y telemetría.

## 14. Licencia y contribuciones
Licencia sugerida: **MIT** para software y **CERN-OHL-P** para hardware. PRs bienvenidos. Commits convencionales.

## 15. Referencias
Datasheets: L298N, LM2596, MG90S, R365, IRFZ44N; notas de aplicación de diodos flyback.
