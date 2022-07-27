#define uart_ucsrA UCSR0A					//UART control and status register A
#define uart_ucsrB UCSR0B					//UART control and status register B
#define uart_ucsrC UCSR0C					//UART control and status register C
#define uart_UDR   UDR0					    //UART data register
#define uart_baudrate UBRR0				    //UART BAUDRATE register

void UART_Begin(void);
void UART_TXchar(uint8_t);
uint8_t UART_RXchar(void);
void display_string(const char mystring[]);
