#include "contiki.h"
#include "stdio.h"
PROCESS(hello_contiki,"hello-contiki");
AUTOSTART_PROCESSES(&hello_contiki);
void trans_time(unsigned long sec)
{
    int hour,min,secd;
    hour = sec/3600;
    min  = (sec%3600)/60;
    secd  = (sec%3600)%60;
    printf("\r [ %d : %d : %d ]  ",hour,min,secd);
}
PROCESS_THREAD(hello_contiki,ev,data)
{
    static struct etimer timer;
    static unsigned long count=0;
    PROCESS_BEGIN();
    etimer_set(&timer,CLOCK_CONF_SECOND);
    while(1)
    {
        PROCESS_YIELD();
    
   	if(PROCESS_EVENT_TIMER==ev)
	{
            trans_time(count++);
	    printf(" Hello adamsxiaomi!");
            etimer_reset(&timer);
	}
    }
    PROCESS_END();
}
