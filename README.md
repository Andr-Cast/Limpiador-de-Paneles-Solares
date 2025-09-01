# LAPS – Limpiador Automatizado de Paneles Solares

Proyecto de prototipo funcional para la limpieza automática de paneles solares mediante un sistema controlado con **Arduino Nano**. El sistema realiza una secuencia programada de rociado de agua, desplazamiento y limpieza con escobilla, optimizando el mantenimiento de paneles solares en ambientes con alta acumulación de polvo.

---

## Características principales
- Control secuencial mediante **Arduino Nano**.  
- Drivers de potencia: **L298N** para motores DC.  
- Fuente principal: **Panel solar 12V – 35W** o **fuente de 12V 3–5A**.  
- Regulación de voltaje: **LM2596** para alimentar motores y servos a 5V.  
- Sistema de protección: diodos flyback, Zener, capacitores de desacople.  

---

## Hardware utilizado
- 1 × Arduino Nano  
- 1 × Driver L298N  
- 2 × Motores TT (5V)  
- 2 × Servos MG90S (5V)  
- 1 × Bomba de agua R365 (12V)  
- 1 × Regulador LM2596  
- 1 × Panel solar 12V – 35W  
- 1 × Fuente de 12V 3–5A  
- Componentes auxiliares: MOSFET IRFZ44N, diodo rectificador, diodo zenner, capacitores  1000uF

---

## Funcionamiento
1. **Activación de bomba de agua** → Rociado de la superficie del panel.  
2. **Movimiento de motores TT** → Desplazamiento del sistema de limpieza.  
3. **Acción de servomotores MG90S** → Control de escobilla para remover suciedad.  
4. **Ciclo automático repetible** con posibilidad de ajustes en el código.  

---

## Instalación y uso
1. Clonar este repositorio:  
   ```bash
   git clone https://github.com/usuario/LAPS.git
