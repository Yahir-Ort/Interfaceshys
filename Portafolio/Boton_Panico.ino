#include "DigiKeyboard.h" // Librería especial para simular un teclado USB

const int pinBoton = 0;   // Usaremos el pin P0 de tu placa para el botón

void setup() {
  // Configuramos el pin 0 como entrada con resistencia interna.
  // Esto hace que el pin siempre lea "1" (HIGH), hasta que presionas el botón y lee "0" (LOW).
  pinMode(pinBoton, INPUT_PULLUP); 
  
  // Inicializa la librería del teclado
  DigiKeyboard.delay(500);
}

void loop() {
  // Mantiene la conexión USB viva
  DigiKeyboard.sendKeyStroke(0);
  
  // Si el botón es presionado (conecta P0 con GND)
  if (digitalRead(pinBoton) == LOW) {
    
    // EN WINDOWS: Envía "Windows + D" para ocultar todo y mostrar el escritorio
    DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
    
    // NOTA: Si usas Mac, cambia la línea de arriba por esta para ocultar ventanas:
    // DigiKeyboard.sendKeyStroke(KEY_H, MOD_GUI_LEFT); 

    // Espera 1 segundo antes de volver a leer para evitar que se repita el comando mil veces
    delay(1000); 
  }
  
  // Un pequeño retraso para estabilidad
  delay(10);
}
