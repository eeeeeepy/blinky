// Assuming default ATTiny13A clock config - 9.6MHz, with clock division enabled
// F_CPU set in Makefile

#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100
#define PATTERN_SIZE 9

int main(void)
{
	DDRB = (1<<DDB4|1<<DDB3|1<<DDB2|1<<DDB1|1<<DDB0); // define direction of pins PB4 to PB0 as output
	char pattern[PATTERN_SIZE] = { PORTB0, PORTB1, PORTB2, PORTB4, PORTB3, PORTB4, PORTB2, PORTB1, PORTB0 };
		
    while (1) {		
		for (int i = 0; i < PATTERN_SIZE - 1; i++) {
			PORTB = 1<<pattern[i];
			_delay_ms(BLINK_DELAY_MS);
		}
	}
	return 0;	
}
