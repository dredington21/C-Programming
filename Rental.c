#include <stdio.h>
/*
Code By: Daniel Redington
This program calculates the amount an individual owes based off of what equipment they rented as well as how long they rented the equipment for.
It provides the user with the lowest possible cost using increments of 4 hours,1 day, and 1 week. 
*/


int main (){
int equip, days, hours, cost1, cost2, cost3, totcost;
int cost[4];
totcost =0;
printf("Please select from four equipment: 1,2,3, and 4\n");
printf("Enter equipment selection:\n");
scanf("%d", &equip);
printf("Enter days:\n");
scanf("%d", &days);
printf("Enter hours:\n");
scanf("%d" ,&hours);

/* this section of the code assigns the values of cost depending on what equipment was used
cost1 is for the 4h period, cost2 is for the 1 day period, and cost3 is for the 1 week period
*/

if (equip ==1){
	cost[1] = 7;
	cost[2] = 10;
	cost[3] = 40;
}
else if (equip ==2){
	cost[1] = 27;
	cost[2] = 39;
	cost[3] = 156;
}
else if ( equip ==3){
	cost[1] = 61;
	cost[2] = 87;
	cost[3] = 348;
}
else if (equip ==4){
	cost[1] = 59;
	cost[2] = 84;
	cost[3] = 336;

}
else {
	printf("Invalid Selection. Select from 1 to 4 \n");
}

/* This section converts days in quantities greater than or equal to 7 into weeks for the code
*/ 

if (days>=7){
	while (days>=7){
		days -=7;
		totcost+= cost[3];
}
}

/* This section optimizes the cost for quantities of days under a week
*/
if (days <=3){
	while(days !=0){
	days-=1;
	totcost += cost[2];
}
}
else if (days >=4) {
	totcost +=cost[3];
}

if (hours >=24){ 
	printf("Invalid hours. \n");
}
else if (hours <=4 && days <=3) {
	totcost += cost[1];
}
else if (hours >4 && days <=3){
	totcost += cost[2];
}
if (hours <24 && equip<=5){
printf("Charge($):$%d ", totcost);
}
return 0;
}
