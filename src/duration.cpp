/*
 *
 * comments
 */

#include "duration.hpp"
#include "assert.h"

Duration::Duration() /* b */
{
    time = 0;                /* sets time to 0 when class is created */
    alarm = 0;               /*sets default value of alarm to be 0*/
    alarmHasBeenSet = false; /*no alarm set*/
};

int Duration::getDuration() /* a */
{
    return time; /*returns time from class Duration*/
};

Duration::Duration(int t) /* c */
{
    assert(t >= 0);          /* time should not be less than 0*/
    time = t;                /*sets time to input t*/
    alarm = 0;               /* sets alarm to 0*/
    alarmHasBeenSet = false; /*no alarm set*/
};

bool Duration::tick()
{
    time++;

    return checkAndUpdateAlarm();
}

bool Duration::tick(int dt)
{
    assert(dt >= 0);  /*time added should be greater than or equal 0*/
    time = time + dt; /*adds n to time*/

    return checkAndUpdateAlarm();
}

void Duration::setalarm(int t) /*g*/ /*h*/
{
    /*makes sure alarm is not set to the past*/
    if (t > time)
    {
        alarm = t;
        alarmHasBeenSet = true;
    }
    else
        alarmHasBeenSet = false;
}

bool Duration::checkAndUpdateAlarm() /*i*/
{
    if (alarmHasBeenSet == true) /*if alarm has been set*/
    {
        if (time > alarm) /*checks if alarm should go off*/
        {
            /*resets alarm*/
            alarmHasBeenSet = false;
            alarm = 0;
            return true;
        }
        else
            return false;
    }
    else
        return false; /*if no alarm set, no alarm can go off*/
}
