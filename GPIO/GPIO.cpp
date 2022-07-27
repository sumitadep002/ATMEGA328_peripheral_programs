void pinMode(uint8_t pin,bool Mode)
{
	if (pin<=7)
	{
	if(Mode==OUTPUT)
	DDRD|=(1<<pin);
	else if(Mode==INPUT)
	DDRD&=(~(1<<pin));
	}
	else
	{
		if(Mode==OUTPUT)
		DDRB|=(1<<pin);
		else if(Mode==INPUT)
		DDRB&=(~(1<<pin));
	}
	
}

void digitalWrite(uint8_t pin,bool Mode)
{
	if (pin<=7)
	{
		if(Mode==OUTPUT)
		PORTD|=(1<<pin);
		else if(Mode==INPUT)
		DDRD&=(~(1<<pin));
	}
	else
	{
		if(Mode==OUTPUT)
		PORTD|=(1<<pin);
		else if(Mode==INPUT)
		PORTD&=(~(1<<pin));
	}
}

bool digitalRead(uint8_t pin)
{
	if(pin<=7)
	{
		return (PIND&(1<<pin));
	}
	else
	{
		return (PINB&(1<<pin));
	}
}