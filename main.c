#include <16F877A.h>
#device adc=8

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES XT                    	//Crystal osc <= 4mhz
#FUSES NOPUT                 	//No Power Up Timer
#FUSES NOPROTECT             	//Code not protected from reading
#FUSES NODEBUG               	//No Debug mode for ICD
#FUSES NOBROWNOUT            	//No brownout reset
#FUSES NOLVP                 	//No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                 	//No EE protection
#FUSES NOWRT                 	//Program memory not write protected

#use delay(clock=4000000)


void main ()
{
     setup_ADC_ports(ALL_ANALOG);   
     setup_adc(adc_clock_div_4);               
     delay_us(15);
     setup_timer_2(T2_DIV_BY_4,255,1); 
                                                                  
     setup_ccp1(CCP_PWM);       
     set_tris_a(0b11111111);       
     set_tris_b(0b00000000);
     set_tris_c(0b00000000);
     set_tris_d(0b00000000);
     set_tris_e(0b00000000);
             while (TRUE)
            {
                    set_adc_channel(0);   
                    delay_us(100);       
                    duty=read_adc(); 
                    duty=duty*1000;
                    duty=duty/1023;
                    set_pwm1_duty(duty);
             }; 
}
