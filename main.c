#include "C:\Users\Elias\Dropbox\PROJETOS\PWM - controle de motor DC\v1.0 - 16f676\main.h"


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
