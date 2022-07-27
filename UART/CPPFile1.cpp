void UART_Begin()
{
	uart_baudrate =103;						//for setting BAUDRATE of 9600 bps
	uart_ucsrB = (1<<TXEN0)|(1<<RXEN0);		//Enables RX and TX
	uart_ucsrC = (1<<UCSZ00)|(1<<UCSZ01);	//communication in 8 bit mode
}

void UART_TXchar(uint8_t data)
{
	while ((uart_ucsrA & (1<<UDRE0))==0);      // checks uart data register flag
	uart_UDR = data;                           // store data into UDR register
	
	
}

uint8_t UART_RXchar()
{
	while ((uart_ucsrA & (1<<RXEN0))==0);        // checks for RXEN flag in UCSR register
	return uart_UDR;							 // returns value stored in UART Data register
}

void display_string(const char *mystring)
{
	while(*mystring)
	{
		UART_TXchar(*mystring++);              // sends characters of the string
	}
}
void rx_string(char *buff)									//takes string as input
{
	int i=0;
	char myvalue;
	do
	{
		myvalue = UART_RXchar();
		if(myvalue!='\n')
		{
			buff[i]=myvalue;
			UART_TXchar(buff[i]);
			i++;
		}
		else
		{
			buff[i]='\0';
			break;
		}
	} while (!(uart_ucsrA & (1<<RXC0)));		//waits until unread data gets cleared
	
	display_string(buff);
}