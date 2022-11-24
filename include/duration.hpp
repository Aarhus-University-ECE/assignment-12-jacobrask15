/*
* comments 
*
*/

#ifndef _DURATION_H_
#define _DURATION_H_

class Duration
{
    private:
        int time;
        int alarm;
        bool alarmHasBeenSet;

        bool checkAndUpdateAlarm();
    
    public:
        Duration(int t); /*construtor that sets time*/ /*c*/
        Duration(); /*constructor*/ /*b*/
       // ~Duration(); /*Destructor*/

        /*returns time*/ /*a*/
        int getDuration(); 

        /*increments time*/ /*e*/
        bool tick();

        /*increments time with n*/ /*f*/
        bool tick(int dt);

        /*sets an alarm at time n*/ /*g*/
        void setalarm(int n);


        
};

#endif