#define SYSCTRL_RCGC2_R (*((volatile unsigned long*)0x400FE108))
#define GPIO_PORTF_DIR_R (*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN_R (*((volatile unsigned long*)0x4002551C))
#define GPIO_PORTF_DATA_R (*((volatile unsigned long*)0x400253FC))

int main()
{
	volatile unsigned long delay_count ;
	SYSCTRL_RCGC2_R =0x20 ; // Enable GPIO PORT
	// delay to make sure GPIO is up and running
	for (delay_count =0; delay_count <200; delay_count++) ;
	GPIO_PORTF_DIR_R |= (1<<3);  //Dir is output for pin 3 port F
	GPIO_PORTF_DEN_R |= (1<<3);  // Enable GPIO pin

	while (1)
	{
		GPIO_PORTF_DATA_R |= (1<<3);
		for (delay_count =0; delay_count <200000; delay_count++) ;

		GPIO_PORTF_DATA_R &= ~(1<<3);
		for (delay_count =0; delay_count <200000; delay_count++) ;

	}

	return 0;
}

// C:/Users/Ezz\ Eldeen/Desktop/xpack-openocd-0.10.0-15/bin/openocd.exe -f C:/Users/Ezz\ Eldeen/Desktop/xpack-openocd-0.10.0-15/scripts/board/ek-lm4f120xl.cfg -c "tcl_port 10240"
// ~/Desktop/xpack-openocd-0.10.0-15/bin/openocd.exe -f ~/Desktop/xpack-openocd-0.10.0-15/scripts/board/ek-lm4f120xl.cfg -c "tcl_port 10240" 