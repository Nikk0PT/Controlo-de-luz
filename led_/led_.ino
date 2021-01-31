#include <Adafruit_NeoPixel.h>
#ifdef _AVR_
 #include <avr/power.h> // (Necessário)
#endif

#define LED_PIN    2

#define LED_COUNT 13
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
int k;
int val;

void setup()
{
Serial.begin(9600);
#if defined(_AVR_ATtiny85_) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  strip.begin();           // Iniciar a biblioteca NeoPixel (Necessário)
  strip.show();            // Desligar todos os pixeis
  strip.setBrightness(50); // Setar o brilho de 1/5 (max = 255)
}

void loop()
{
  if (Serial.available())
  {
   val = Serial.read();
       if (val == 'R') //Rainbow
       {
        rainbow(10); 
       }
       if (val == 'r') // red
       {
        colorWipe(strip.Color(255, 0, 0), 50);    
       }
       if (val == 'g') // green
       {
        colorWipe(strip.Color(0, 255, 0), 50);    
       }
        if (val == 'b') // blue
       {
        colorWipe(strip.Color(0, 0, 255), 50);    
       }
        if (val == 'w') // white
       {
        colorWipe(strip.Color(255, 255, 255), 50); 
       }
        if (val == 'y') //yellow
       {
        colorWipe(strip.Color(255, 255, 0), 50); 
       }
        if (val == 'm') //magenta
       {
        colorWipe(strip.Color(255, 0, 255), 50); 
       }
        if (val == 'c') //cyan
       {
        colorWipe(strip.Color(0, 255, 255), 50); 
       }
        if (val == 'o') //off
       {
        colorWipe(strip.Color(0, 0, 0), 50); 
       }
  }  
}
  
void rainbow(int wait) { //1
    for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
    strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show(); // Atualização da fita
    delay(wait);  // Pequena pausa
  }
}




void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, color);         //  Mudança de cor do pixel
    strip.show();                          //  Atualização da fita
    delay(wait);                           //  Pequena pausa
  }
}
