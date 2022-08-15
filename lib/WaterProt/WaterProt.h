#ifndef WATERPROT_H
#define WATERPROT_H

class WaterProt
{
    private: 
    #define MORNING 0 //6:00am
    #define NOON 1 //12:00pm  
    #define EVENING 2 //6:00pm
    #define MIDNIGHT 3 //12:00am
       
    public:

    int waterHour;
    int waterMin = 0;

    //This function will trigger the relay and water the plant
    void waterPlant(int motorPin, int waterDuration);
    //This function recieves a water "state" from 0-3 and associates it with an hour on the clock
    int getWateringHour(int waterState);

};

#endif