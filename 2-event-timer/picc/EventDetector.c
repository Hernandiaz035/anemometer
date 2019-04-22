#include <18F2550.h>
#DEVICE ADC = 10
#DEVICE HIGH_INTS=TRUE

#FUSES NOWDT NOWRT NOLVP NOCPD NOPROTECT NOVREGEN NOUSBDIV
// #FUSES MCLR NOBROWNOUT HSPLL PLL4 CPUDIV1
#FUSES MCLR NOBROWNOUT HS

#USE delay(clock = 48MHz)

#USE RS232(baud = 115200, STREAM = BUS , xmit=PIN_C6, rcv=PIN_C7 , bits=8 , parity=N , STOP=1 )

BOOLEAN timer1rolledOver;
int16 elapsedTime;
int variableDelay;

#INT_EXT HIGH
void handlerExt() {
   // Esta interrupcion es usada para captar la señal esperada
   elapsedTime = get_timer1();
   if(!timer1rolledOver) {
      fprintf(BUS, "EXT, ticks count: %Lu\r\n", elapsedTime);
   } else {
      fprintf(BUS, "EXT, timer missed!\r\n");
   }
}

#INT_TIMER1
void handlerTimer1() {
   // Esta interrupcion es usada para time-out a la señal esperada
   timer1rolledOver = TRUE;
   setup_timer_1(T1_DISABLED);
}

void init();
void timer1restart();

void main(){
   init();   

   while(TRUE) {
      // fprintf(BUS, "OK\r\n");
      // output_toggle(PIN_C0);
      
      output_low(PIN_C0);
      timer1restart();
      delay_ms(variableDelay++);
      output_high(PIN_C0);
      delay_ms(250);
      
      variableDelay = (variableDelay >= 5)?0:variableDelay;
   }
}

void init() {
   // Configuracion de puertos
   set_tris_b(0xFF);
   set_tris_c(0b10000000);
   output_c(0b01000000);

   // Configurar Timer0
   set_timer1(0);
   setup_timer_1(T1_DISABLED);
   enable_interrupts(INT_TIMER1);

   // Configuracion de Interrupciones
   //ext_int_edge(0, H_TO_L);
   ext_int_edge(0, L_TO_H);
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
}

void timer1restart() {
   timer1rolledOver = FALSE;
   set_timer1(0);
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
}
