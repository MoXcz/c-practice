#include <stdio.h>
// Program that prints a Celsius-Fahrenheit table

#define LOWER -20 // Lower limit of table
#define UPPER 150 // Upper limit of table
#define STEP 10   // Step size

float celsius_to_fahrenheit(float celsius_temp);

int main() {
  float celsius_temp;

  for (celsius_temp = UPPER; celsius_temp >= LOWER;
       celsius_temp = celsius_temp - STEP) {
    printf("Celsius: %3.0f\tFahrenheit: %6.1f\n", celsius_temp,
           celsius_to_fahrenheit(celsius_temp));
  }
}

float celsius_to_fahrenheit(float celsius_temp) {
  float fahrenheit_temp;
  fahrenheit_temp = (9.0 / 5.0) * (celsius_temp + 32.0);
  return fahrenheit_temp;
}
