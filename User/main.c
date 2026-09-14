#include "ch32v003_gpio_driver.h"

static void delay(void)
{
    volatile uint32_t i;

    for(i = 0; i < 100000; i++)
    {
        __asm volatile("nop");
    }
}

int main(void)
{
    GPIO_Handle_t gpio;

    gpio.pGPIOx = GPIOA;
    gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_1;
    gpio.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT2MHz;
    gpio.GPIO_PinConfig.GPIO_PinType = GPIO_TYPE_OUT_PP;

    GPIO_Init(&gpio);

    while(1)
    {
        GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_1);
        delay();
    }

    return 0;
}
