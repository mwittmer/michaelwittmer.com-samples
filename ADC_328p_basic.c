/*
 * ADC_328p_basic.c
 *
 * Created: 4/12/2014 3:53:53 PM
 *  Author: mwittmer
 */ 


#include <avr/io.h>

int main(void)
{
	/*----Instantiate Variables----*/
	int adc_value;
	
	// setup digital outputs (for LEDs)
	DDRB |= (0xff);									//Set PORTB (PB0 through PB7) as digital output
	
	/*----Configure ADC----*/
	ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));   //Set Prescaler to 128 to establish a 125Khz clock source
	ADMUX |= (1<<REFS0);
	ADMUX &= ~(1<<REFS1);							//Set AVCC(+5v) as voltage reference
	ADCSRB &= ~((1<<ADTS2)|(1<<ADTS1)|(1<<ADTS0));  //Config ADC in free-running mode
	ADCSRA |= (1<<ADATE);							//Signal source, in this case is the free-running
	ADCSRA |= (1<<ADEN);							//Power up the ADC
	
	/*----Perpetual Loop----*/
    while(1)
    {
		ADCSRA |= (1<<ADSC);						//Start ADC Conversion

        adc_value = ADCW;							//Read ADC value
        
		
		/*---Circuit specific conditionals follow - modify for your specific requirements----*/
		if(adc_value > 660){
			PORTB |= (1<<PB0);						//If ADC value is above 660 turn led 0 on
		}
		else {
			PORTB &= ~(1<<PB0);						// Else turn led 0 off
		}

		if(adc_value > 680){						// If ADC value is above 680, turn led 1 on
				PORTB |= (1<<PB1);
		}
		else {
			PORTB &= ~(1<<PB1);						//Else turn led 1 off
		}

		if(adc_value > 700){						// If ADC value is above 700, turn led 2 on
			PORTB |= (1<<PB2);
		}
		else {
			PORTB &= ~(1<<PB2);						//Else turn led 2 off
		}

		if(adc_value > 720){						// If ADC value is above 720, turn led 3 on
			PORTB |= (1<<PB3);
		}
		else {
			PORTB &= ~(1<<PB3);						//Else turn led 3 off
		}

		if(adc_value > 740){						// If ADC value is above 740, turn led 4 on
			PORTB |= (1<<PB4);
		}
		else {
			PORTB &= ~(1<<PB4);						//Else turn led 4 off
		}

		if(adc_value > 760){						// If ADC value is above 760, turn led 5 on
			PORTB |= (1<<PB5);
		}
		else {
			PORTB &= ~(1<<PB5);						//Else turn led 5 off
		}
		if(adc_value > 780){						// If ADC value is above 780, turn led 6 on
			PORTB |= (1<<PB6);
		}
		else {
			PORTB &= ~(1<<PB6);						//Else turn led 6 off
		}

		if(adc_value > 800){						// If ADC value is above 800, turn led 7 on
			PORTB |= (1<<PB7);
		}
		else {
			PORTB &= ~(1<<PB7);						//Else turn led 7 off
		}

		ADCSRA = ~(1<<ADSC);						//Stop converting
		
		/*----End of Loop----*/
    }
}
