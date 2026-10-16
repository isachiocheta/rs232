#include <Arduino.h>

void setup() {
    Serial.begin(115200);

    // RX = GPIO16 (RX2), TX = GPIO17 (TX2)
    Serial2.begin(9600, SERIAL_8N1, 16, 17);
    Serial2.setTimeout(500);

    delay(1000);
    Serial.println("Teste iniciado!");
}

void loop() {
    while (Serial2.available()) {
        Serial2.read();
    }

    Serial2.println("TESTE");

    String resposta = Serial2.readStringUntil('\n');
    resposta.trim();

    if (resposta == "TESTE") {
        Serial.println("OK: comunicacao funcionando!");
    } else {
        Serial.println("FALHOU: confira o jumper entre TX2 e RX2.");
    }

    delay(2000);
}
