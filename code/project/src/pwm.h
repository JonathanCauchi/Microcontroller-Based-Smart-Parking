//definicije registrov za periferijo PWM

//PWM0
#define IR      (*((volatile unsigned int *) 0x40014000))
#define TCR     (*((volatile unsigned int *) 0x40014004))
#define TC      (*((volatile unsigned int *) 0x40014008))
#define PR      (*((volatile unsigned int *) 0x4001400C))
#define PC      (*((volatile unsigned int *) 0x40014010))

#define MCR     (*((volatile unsigned int *) 0x40014014))
#define MR0     (*((volatile unsigned int *) 0x40014018))
#define MR1     (*((volatile unsigned int *) 0x4001401C))
#define MR2     (*((volatile unsigned int *) 0x40014020))
#define MR3     (*((volatile unsigned int *) 0x40014024))
#define MR4     (*((volatile unsigned int *) 0x40014040))
#define MR5     (*((volatile unsigned int *) 0x40014044))
#define MR6     (*((volatile unsigned int *) 0x40014048))

#define CCR     (*((volatile unsigned int *) 0x40014028))
#define CR0     (*((volatile unsigned int *) 0x4001402C))
#define CR1     (*((volatile unsigned int *) 0x40014030))

#define PCR     (*((volatile unsigned int *) 0x4001404C))
#define LER     (*((volatile unsigned int *) 0x40014050))
#define CTCR        (*((volatile unsigned int *) 0x40014070))

/*
//PWM1
#define IR      (*((volatile unsigned int *) 0x40018000))
#define TCR     (*((volatile unsigned int *) 0x40018004))
#define TC      (*((volatile unsigned int *) 0x40018008))
#define PR      (*((volatile unsigned int *) 0x4001800C))
#define PC      (*((volatile unsigned int *) 0x40018010))

#define MCR     (*((volatile unsigned int *) 0x40018014))
#define MR0     (*((volatile unsigned int *) 0x40018018))
#define MR1     (*((volatile unsigned int *) 0x4001801C))
#define MR2     (*((volatile unsigned int *) 0x40018020))
#define MR3     (*((volatile unsigned int *) 0x40018024))
#define MR4     (*((volatile unsigned int *) 0x40018040))
#define MR5     (*((volatile unsigned int *) 0x40018044))
#define MR6     (*((volatile unsigned int *) 0x40018048))

#define CCR     (*((volatile unsigned int *) 0x40018028))
#define CR0     (*((volatile unsigned int *) 0x4001802C))
#define CR1     (*((volatile unsigned int *) 0x40018030))

#define PCR     (*((volatile unsigned int *) 0x4001804C))
#define LER     (*((volatile unsigned int *) 0x40018050))
#define CTCR        (*((volatile unsigned int *) 0x40018070))
*/

void pwm_init(void);

