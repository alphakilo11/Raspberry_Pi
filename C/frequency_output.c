/* 
With this code Frequency up to about 7 kHz are possible.
based on: http://wiringpi.com/examples/blink/ */
#include <wiringPi.h>
#include <stdio.h>
#include <time.h>

#define RUNNING_TIME 10 // s
#define FREQUENCY 8000 // Hz
#define DUTY_CYCLE 50 // %

int main (void)
{
  wiringPiSetup () ;
  pinMode (0, OUTPUT) ;
  double delay_ms = 1000 / FREQUENCY; // ms
  long start = time(0);
  for (int i = 0; i < (RUNNING_TIME * FREQUENCY); i++)
  {
    digitalWrite (0, HIGH) ; delay (delay_ms * DUTY_CYCLE / 100) ;
    //printf("%li: Off\n", time(0));
    digitalWrite (0,  LOW) ; delay (delay_ms * (100 - DUTY_CYCLE) / 100);
    //printf("On\n");
  }
  printf("Done in %li s.", time(0) - start);
  return 0 ;
}
