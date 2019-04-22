#include <18F2550.h>
#DEVICE ADC = 10
#DEVICE HIGH_INTS=TRUE
// #include <stdio.h>
// #include <stdlib.h>

#FUSES NOWDT NOWRT NOLVP NOCPD NOPROTECT NOVREGEN NOUSBDIV
// #FUSES MCLR NOBROWNOUT HSPLL PLL4 CPUDIV1
#FUSES MCLR NOBROWNOUT HS

#USE delay(clock = 48MHz)

#USE RS232(baud = 115200, STREAM = BUS , xmit=PIN_C6, rcv=PIN_C7 , bits=8 , parity=N , STOP=1 )

void main(){
   setup_timer_2(T2_DIV_BY_4,74,1);   //CONFIG FRECUENCIA
   setup_ccp1(CCP_PWM);                //CONFIG COMO PWM

   set_tris_c(0b10000000);
   output_c(0b01000000);

   /*set_tris_c(0x00);
   output_c(0x00);*/

   set_pwm1_duty(37);

   while(TRUE) {
      // fprintf(BUS, "OK\r\n");
      // output_toggle(PIN_C0);
      delay_us(10);
      set_pwm1_duty(0);
      delay_us(10);
      set_pwm1_duty(37);
   }
}
