/*
 * DHT11.cpp
 *
 * Created: 25-07-2022 00:26:02
 * Author : Sumit
 */ 

#define SET_BIT()
#define F_CPU16000000UL
#include <avr/io.h>
#include 
#define timer0_value TCNT0

void DHT_init()
{
	TCCR1B=(1<<CS12)|(1<<CS10);
	TCNT1=0;
	TCCR0B|=(1<<CS01);
	
	SET_BIT(DDRB,PB4);
	CLEAR_BIT(PORTB,PORTB4);
	
	TCNT1=0;
	while(TCNT1<=281);
	
	SET_BIT(PORTB,PORTB4);
	TCNT0=0;
	while(TCNT0<=80);
	CLEAR_BIT(DDRB,PORTB4);
	
	
}

uint8_t DHT_response()
{
	if (!(IS_SET(PORTB,PORTB4)))
	{
		TCNT0=0;
		while(TCNT0<=170);
	}
	else
	{
		return 1;
	}
	if (IS_SET(PINB,PORTB4))
	{
		TCNT0=0;
		while(TCNT0<=170);
	}
	else
	{
		return 2;
	}
}

uint8_t data[5];
int DHT11_recieve(uint8_t *x)
{
uint8_t check;
volatile uint8_t count=40;
	for (uint8_t z=0;z<5;z++)
	{
		for (uint8_t j=7;j>=0;j--)
		{
			TCNT0=0;
			while(!IS_SET(PINB,PINB4))
			{
				if (TCNT0>=120)
				{
					decimel=(TCNT0);
					return 12;
				}
			}
			TCNT0=0;
			while(IS_SET(PINB,PINB4))
			{
				if(TCNT0<=160)
				cnt=TCNT0=0;
				else
				{
					decimal0(TCNT0);
					printstring0("\n");
					return 1;
				}
			}
		}
		if ((count>=40)&(count<=70))
		CLEAR_BIT(data[z],j);
		
		else if((count>=120)&(count<=160))
		SET_BIT(data[z],j);
		
		else
		{
			printstring("error 2\n"); decimal(count);
			return 2;
		}
		
	}
	check = data(data[0]+data[1]+data[2]+data[3]) & 0xFF;
	if (check!=data[4]) return 3;
	for(uint8_t w=0;w<=4;w++)
	{
		x[w]=data[w];
	}
	return 4;
}

int main(void)
{
	UART_Begin();
	uint8_t x[5];
	uint8_t y[5];
	
    while (1) 
    {
		DHT_init();
		DHT_response();
		DHT11_recieve(x);
		display_string("\nHumidity of DHT11 ");
		
		decimal(x[0]);
		display_string(".");
		decimal(x[1]);
		
		display_string("\nTemperature of The DHT11");
		
		decimal(x[2]);
		display_string(".");
		display_string(x[3]);
		
		_delay_ms(2000);
		display_string("\n");
    }
}

