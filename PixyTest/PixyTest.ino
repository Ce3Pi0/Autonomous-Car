#include <Pixy2.h>

#define RED 1
#define GREEN 3

Pixy2 pixy;

void setup() {
  Serial.begin(9600);
  pixy.init();
}

void loop() {
  pixy.ccc.getBlocks();

  for (int i = 0; i < pixy.ccc.numBlocks; i++) {
    // Print the signature;
    // Serial.println(pixy.ccc.blocks[i].m_signature);

    switch (pixy.ccc.blocks[i].m_signature) {
      case GREEN:
        Serial.println("Green light detected ");
        break;
      case RED:
        Serial.println("Red light detected ");
        break;
    }
 }

}
