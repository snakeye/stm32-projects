#include <Arduino.h>
#include <WS2812FX.h>

#define LED_COUNT 8
#define LED_PIN PB9

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

unsigned long last_change = 0;
unsigned long now = 0;

#define TIMER_MS 5000

void setup()
{
    ws2812fx.init();
    ws2812fx.setBrightness(255);
    ws2812fx.setSpeed(1000);
    ws2812fx.setColor(0x007BFF);
    ws2812fx.setMode(FX_MODE_STATIC);
    ws2812fx.start();
}

void loop()
{
    now = millis();

    ws2812fx.service();

    if (now - last_change > TIMER_MS)
    {
        ws2812fx.setMode((ws2812fx.getMode() + 1) % ws2812fx.getModeCount());
        last_change = now;
    }
}