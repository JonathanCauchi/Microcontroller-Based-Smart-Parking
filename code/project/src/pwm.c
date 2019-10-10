#include "LPC4088-ioconfig.h"
#include "LPC4088-system.h"
#include "pwm.h"

void pwm_init(void){
        //omogocimo PWM0, ki ob zagonu ni prizgan
        PCONP = PCONP | (0x1<<5);

        //resetiranje PWM0
        //RSTCON0 = RSTCON0 | (0x1<<5);
        
        //nastavitev pina P1.2 kot izhoda PWM0_1 - v headerju zakomentiramo timer PWM1
        IOCON_P1_2  = IOCON_P1_2  & !(0x67F);
        IOCON_P1_2  = IOCON_P1_2  | 0x3;
        
        //nastavitev pina P1.18 kot izhoda PWM1_1 - v headerju zakomentiramo timer PWM0
        //IOCON_P1_18  = IOCON_P1_18  & !(0x67F);
        //IOCON_P1_18  = IOCON_P1_18  | 0b010;      

        //pocistimo interrupte za PWM0
        IR = IR | 0x73F;
        
        //nastavimo "individual use"
        TCR = TCR & !(1<<4);
        
        //nastavimo "Timer mode"
        CTCR = CTCR & !(0x3);
                
        //omogocimo PWMx_1 kanal (izhod)
        PCR = PCR | (1<<9);
        
        //nastavimo match register R0 tako, da ob TC == MR0 resetira
        //celotni PWM0. Uporabili bomo kanal PWM0_1 in tega setamo in 
        //resetamo z MR0 in MR1 (UM, tabela 556). 1
        MCR = MCR | (1<<1);
        MR0 = 0xFFFFF;
        MR1 = 0xFFFFF;
        
        //ko so vrednosti vpisane v MR0 in MR1, obe vrednosti omogocimo (istocasno)
        LER = LER | 0x3;

        //nastavimo "timer mode" in ne "PWM mode" (ne deluje) 
        //POZOR! Mora biti za nastavitvijo MR0/MR1
        TCR = TCR & !(1<<3);

        //vklopimo PWM0 - mora biti za nastavitvijo MR0/MR1
        //POZOR! Mora biti za nastavitvijo MR0/MR1
        TCR = TCR | (1<<0); 

        while(1);
        
}
