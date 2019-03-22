
// one-to-one mapping of outputs,time delays and next states form graphical representation to data structure form.
sTyp FSM[6] = {
               {
							  {0x0C, 0x02}, 10, {goWest, goWest, waitWest, waitWest, waitWest, waitWest, waitWest, waitWest} // goWest
							 },
							 
               {
							  {0x14, 0x02}, 10, {goWalk, goWalk, goSouth, goSouth, goWalk, goWalk, goSouth, goSouth} // waitWest
							 },
							 
               {
							  {0x21, 0x02}, 10, {goSouth, waitSouth, goSouth, waitSouth, waitSouth, waitSouth, waitSouth, waitSouth} // goSouth
							 },
							 
               {
							  {0x22,0x02}, 10, {goWalk, goWest, goWalk, goWest, goWalk, goWest, goWalk, goWalk} // waitSouth
							 },
							 
               {
							  {0x24, 0x08}, 10, {goWalk, waitWalk, waitWalk, waitWalk, goWalk, waitWalk, waitWalk, waitWalk} // goWalk
							 },
							 
               {
							  {0x24, 0x02}, 10,{goWest, goWest, goSouth, goWest, goWest, goWest, goSouth, goWest} // waitWalk
							 }
							 
              };

							 

	
  while(1) // the condition for which loop can run for infinite time
		{
			
		  int WaitWalk = ((Input == 0x01 || Input == 0x02 || Input == 0x03 || 
			                 Input == 0x05 || Input == 0x06 || Input == 0x07) 
		                  && PEDSTRIAN_SIGNAL == 0x08); //for detecting the WaitWalk state.
		
		  // If WaitWalk state detected then toggle the Red signal of the PEDESTRIAN SIGNAL 2 times.
		  if(WaitWalk)
		  {
				
			  int i=0;
			  while(i< 2) // condition for looping through it 2 times only
			  {
					
			    PEDSTRIAN_SIGNAL = 0x02; // the red signal is on
			    SysTick_Wait10ms(10); // delay
			    PEDSTRIAN_SIGNAL = 0x00; // the red signal is off
				  SysTick_Wait10ms(10); // delay
				  i++; // i = i + 1
					+++++++++++++++++
			  }
			  PEDSTRIAN_SIGNAL = 0x02; // the red signal is off
				
		  }
		
		  CAR_SIGNAL = FSM[Current_State].Output[0]; // Set Traffic light for West/South
		
		  PEDSTRIAN_SIGNAL = FSM[Current_State].Output[1]; // Set Traffic light for West/South
		
		  SysTick_Wait10ms(FSM[Current_State].Time); // Waitig time in a valid state/Time delay.
		
		  Input = SENSOR; //SENSORS values means the states of PE2-PE0,possible 
		                 //states are - 000,001,010,011,100,101,110,111 or 0,1,2,3,4,5,6,7
		
		  Current_State = FSM[Current_State].NextState[Input]; // What is the state after receiving 
		                                                      // the Input (depends on the Input and Currnt state)
    }
		
  }
