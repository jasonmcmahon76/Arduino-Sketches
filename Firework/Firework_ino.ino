#include <Adafruit_NeoPixel.h>
#include <TrueRandom.h>
#define PIN 6 // Data pin on Arduino

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

void setup() {
  strip.begin();
  strip.show();   // Initialize all pixels to 'off'
  }

void loop() 
  {
  int randomairspeed = (TrueRandom.random(41,51));  // Height of firework explosion.
  int explosionsize = (TrueRandom.random(5,8));  // Size of firework explosion.
  int randomdelay = (TrueRandom.random(20,60));  //Random delay between fireworks.
  int i = 0;  // position of the head of the firework
  
  for(int d=0; d<randomdelay; d++);
  for(int i=0; i<randomairspeed; i++) {    
        // airspeed determines how far the pixel travels along the strip.
        // Draw 4 pixels trailing from pos.  setPixelColor() will clip any
        // pixels off the ends of the strip, we don't need to watch for that.
        strip.setBrightness(10);
        strip.setPixelColor(i - 2, 30,0,0); // Darkest red
        strip.setPixelColor(i - 1, 90, 90, 0); // Dark red
        strip.setPixelColor(i, 127,127,127); // First pixel is brightest red
        
  
        strip.show();
        delay((10+pow((0.095*i),2)));
  
          for(int j=-4; j<= 0; j++) {
            strip.setPixelColor(i+j, 0);
            // Rather than being sneaky and erasing just the tail pixels,
            // it's easier to erase it all and draw a new one next time.
          }
    }
        strip.setBrightness(255);   
        delay(75);
        strip.setPixelColor(randomairspeed - 1, 0xFFFFFF); // White
        strip.setPixelColor(randomairspeed    , 0xFFFFFF); // White
        strip.setPixelColor(randomairspeed + 1, 0xFFFFFF); // White
        strip.show();
        for(int j=-1; j<= 1; j++) strip.setPixelColor(randomairspeed+j, 0);
        delay(50);
        int r = (TrueRandom.random(1,255));
        int g = (TrueRandom.random(1,255));
        int b = (TrueRandom.random(1,255));
        strip.setPixelColor(randomairspeed - 1, r,g,b); // Red
        strip.setPixelColor(randomairspeed    , r,g,b); // Medium Red
        strip.setPixelColor(randomairspeed + 1, r,g,b); // Red
        strip.show();
        delay(10);
        for(int j=-1; j<= 1; j++) strip.setPixelColor(randomairspeed+j, 0);
        
          for (int airburst = 1; airburst < explosionsize; airburst++) {
            int pixela=(randomairspeed-airburst);
            int pixelb=(randomairspeed+airburst);
            strip.setPixelColor(pixela-1, r,g,b); // Red
            strip.setPixelColor(pixela, r,g,b); // Medium Red
            strip.setPixelColor(pixelb, r,g,b); // Medium Red
            strip.setPixelColor(pixelb+1, r,g,b); // Red
            strip.show();
            delay(50);
            for(int j=(-airburst)-1; j<= (airburst + 1); j++) strip.setPixelColor(randomairspeed+j, 0);
       
       }
  }
