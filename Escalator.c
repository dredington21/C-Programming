#include <stdio.h>
/*
Code By: Daniel Redington
This program determines how long an escalator will be running if it runs when people are on it and for 10 seconds 
after the last person gets on
*/
int main(){
    int n;
    int i;
    int tottime=0;
    printf("Enter number of people:\n");
    scanf("%d", &n);
    int time[n];
    printf("Enter arrival times:\n");
    /*
This section reads the arrival times into an array
*/
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &time[i]);
    }
/*
This section calculates how long between each person getting on the escalator and how much time each person contributes to the overall time
*/
    for (int i =0; i< n; i++)
    {
        if (n==1){
            tottime+=10;
        }
        else if (time[i]+10<=time[i+1] && time[i+1]!=0){
            tottime += 10;
    
        }
        else if (time[i]+10>time[i+1] && time[i+1]!=0){
            tottime += time[i+1]-time[i];
    
        }
    }
printf("Active seconds: %d", tottime);


    return 0;



}