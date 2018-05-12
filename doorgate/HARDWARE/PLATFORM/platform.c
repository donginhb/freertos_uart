#include "platform.h"	
#include "delay.h"

//#include "beep.h"
//#include "voice.h" 	
#include "calendar.h"		
//#include "led.h"		
//#include "card.h"


int platformInit(void)   	   
{ 		
	//Low level init: Clock and Interrupt controller
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);	

	//DWT��ʼ��
	//DWT_INIT(SystemCoreClock);		
		
	//Systick Init
	delay_init();
	
#if BEEP_OPEN 
	//Beep_Init();
#endif


#if EEPROM_OPEN 
	
#endif


#if SST_OPEN 
	
#endif


#if DATA_OPEN 	
	Calendar_Init();
#endif


#if VOICE_OPEN 	
	//Voice_Init();
#endif


#if OUTSWITCH_OPEN 
	
#endif
	 
	 
#if DateManager_OPEN 
	 
#endif	


#if	ReadCard_Open
	//Card_Init();		
	//CardLibrary_Init();
#endif		


#if	LED_Open
	//Led_Init();			
#endif	
	
  return 1;	
}

