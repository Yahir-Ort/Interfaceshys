# Proyecto: Botón de Pánico USB (Simulador de Teclado)

Este proyecto utiliza una placa de desarrollo basada en **ATtiny85** para simular un teclado USB (dispositivo HID). Al presionar un botón físico conectado a la placa, el sistema envía una combinación de teclas automática para ocultar de inmediato todas las ventanas abiertas en la computadora.

---

## ¿Qué hace este código?
*   **Monitoreo constante:** El microcontrolador revisa continuamente el estado de un botón físico conectado al pin `P0`.
*   **Comando automático:** Al detectar la pulsación (lectura en `LOW`), emite el atajo de teclado:
    *   **Windows:** `Win + D` (Muestra el escritorio / oculta todas las ventanas).
    *   *Nota:* Se puede adaptar para macOS cambiando el comando a `Cmd + H`.
*   **Anti-rebote simple:** Incluye un retraso de 1 segundo (`delay(1000)`) tras la activación para evitar que el comando se envíe múltiples veces por accidente.

---

## Componentes de Hardware Necesarios
1.  **Placa de desarrollo Digispark ATtiny85** (o cualquier placa compatible con emulación HID USB).
2.  **Botón pulsador (Push button)** de dos pines.
3.  **Cables de conexión (Jumpers)**.
4.  **Conexión física:** Un pin del botón va conectado al **Pin 0 (P0)** de la placa y el otro pin va conectado a **GND**. *(No requiere resistencia externa ya que el código activa la resistencia `INPUT_PULLUP` interna)*.

---

## Configuración en el IDE de Arduino (Software)

Para poder compilar y subir este código a tu placa, debes configurar tu entorno de desarrollo con los siguientes pasos:

### 1. Instalar el soporte para placas Digispark
1. Abre el IDE de Arduino y ve a **Archivo > Preferencias**.
2. En el campo *Gestor de URLs Adicionales de Tarjetas*, añade la siguiente URL:
   `http://digistump.com`
3. Ve a **Herramientas > Placa > Gestor de tarjetas**.
4. Busca `Digistump AVR Boards` e instálalo.

### 2. Librerías requeridas
*   **DigiKeyboard.h:** Esta librería viene incluida de forma automática al instalar el paquete de placas de Digistump mencionado en el paso anterior. No necesitas descargarla por separado.

---
*Proyecto documentado para el Portafolio de GitHub.*
