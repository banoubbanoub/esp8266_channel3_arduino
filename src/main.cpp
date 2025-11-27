#include <Arduino.h>
#include <video_broadcast.h>
#include <user_main.h>
#include <custom_commands.h>

uint8_t lastframe = 2;
void setup() {
 
testi2s_init();

}
	 
void loop() {


	
    
      switch (lastframe)
      {
	 case 1:
	   showstate =10;
	   break;
	   case 2:
	   showstate =9;
	   break;
      
	  }
	
	 
	   static uint8_t lastframe = 0;
	uint8_t tbuffer = !(gframe&1);
	if( lastframe != tbuffer )
	{
		frontframe = (uint8_t*)&framebuffer[((FBW2/4)*FBH)*tbuffer ];
		DrawFrame( );
		lastframe = tbuffer;
	}

	system_os_post(procTaskPrio, 0, 0 );
	   
	
  

}      