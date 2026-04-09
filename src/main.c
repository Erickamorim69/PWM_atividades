#include <zephyr/kernel.h>             // Funções básicas do Zephyr (ex: k_msleep, k_thread, etc.)
#include <zephyr/device.h>             // API para obter e utilizar dispositivos do sistema
#include <zephyr/drivers/gpio.h>       // API para controle de pinos de entrada/saída (GPIO)
#include <pwm_z42.h>                // Biblioteca personalizada com funções de controle do TPM (Timer/PWM Module)

#define TPM_MODULE 1000         
uint16_t duty_50  = TPM_MODULE*0;     

int main(void)
{

    pwm_tpm_Init(TPM2, TPM_PLLFLL, TPM_MODULE, TPM_CLK, PS_128, EDGE_PWM);
    pwm_tpm_Init(TPM0, TPM_PLLFLL, TPM_MODULE, TPM_CLK, PS_128, EDGE_PWM);

    pwm_tpm_Ch_Init(TPM2, 0, TPM_PWM_H, GPIOB, 18);
    pwm_tpm_Ch_Init(TPM2, 1, TPM_PWM_H, GPIOB, 19);
    pwm_tpm_Ch_Init(TPM0, 1, TPM_PWM_H, GPIOD, 1);

    int r=1000, g=1000, b=1000;
    pwm_tpm_CnV(TPM2,0,r);
    pwm_tpm_CnV(TPM2,1,g);
    pwm_tpm_CnV(TPM0,1,b);

    for (;;)
    {
        r=0;
        g=700;
        b=1000;
        pwm_tpm_CnV(TPM2,0,r);
        pwm_tpm_CnV(TPM2,1,g);
        pwm_tpm_CnV(TPM0,1,b);
        k_msleep(1000);
        r=1000;
        g=1000;
        b=1000;
        pwm_tpm_CnV(TPM2,0,r);
        pwm_tpm_CnV(TPM2,1,g);
        pwm_tpm_CnV(TPM0,1,b);

        k_msleep(1000);

    }

    return 0;
}