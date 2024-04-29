//--------------------------------------------------------------------------------------------
/**
 * 1) A escala Kelvin é uma escala de temperatura termodinâmica onde 0 define o ponto no qual as
 * moléculas não emitem nenhum calor e o movimento térmico cessa. Faça:
 *          a. Uma função para converter de Kelvin para Fahrenheit (ºF = 1.8 x (K - 273) + 32).
 *          b. Uma função para converter de Kelvin para Celsius (ºC = K – 273).
 *          c. Um programa para testar as funções criadas.
*/
//--------------------------------------------------------------------------------------------
#include <stdio.h>

float kelvin_to_fahrenheit(float temp_em_kelvin)
{
    return ((1.8 * (temp_em_kelvin - 273.0)) + 32.0);
}

float kelvin_to_celsius(float temp_em_kelvin)
{
    return ((temp_em_kelvin - 273));
}

void transforma_temps(float temp_em_kelvin, float *temp_em_fahrenheit, float *temp_em_celsius)
{
    *temp_em_fahrenheit = kelvin_to_fahrenheit(temp_em_kelvin);
    *temp_em_celsius = kelvin_to_celsius(temp_em_kelvin);
}

int main ()
{
    float temp_em_kelvin, temp_em_fahrenheit, temp_em_celsius;

    printf("Informe a temperatura em Kelvin: \n");
    scanf("%f", &temp_em_kelvin);

    transforma_temps(temp_em_kelvin, &temp_em_fahrenheit, &temp_em_celsius);

    printf("\n\t ----------------------------TEMPERATURAS -------------\n\n"); 
    printf("TEMP A SER CONVERTIDA: %.2f K\n\n em Fahrenheit: %.2f\n em Celsius: %.2f\n", temp_em_kelvin, temp_em_fahrenheit, temp_em_celsius);

    return 0;
}