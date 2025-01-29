#include<stdio.h>

int main(){
int choice ,days ,total_cars=0,total_days=0,coast_per_day=0;	
float total_amount=0;
do {
	printf("__Welcom to Car Rental Service__\n");
	printf("1.sedan_     80$ per day\n");
	printf("2.suv_       50$ per day\n");
	printf("3.v8_        200$ per day\n");
	printf("4.Mira_      100$ per day\n");
	printf("5.Renatl summary.\n");
	printf("6.Exit the Program!\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	if (choice==5){
		printf("Total cars rented: %d\n",total_cars);
		printf("Total rented days: %d\n",total_days);
		printf("Total Amount to be paied: %.2f\n",total_amount);
		continue;
	}
	if (choice==6){
		printf("Thank you for visiting our car rental service.");
		break;}
		if (choice>=1&&choice<=4){
			printf("Enter the number of days:  ");
			scanf("%d",&days);
			
		if (choice==1){
			coast_per_day=80;}
		else if (choice==2){
			coast_per_day=50;
		}
		else if (choice==3){
			coast_per_day=200;
		}
		else if (choice==4){
			coast_per_day=100;}
		total_cars++;
		total_days+=days;
		total_amount+=coast_per_day*days;
		
		printf("car rented sucessfully for %d days at %d$ amount\n",days ,coast_per_day);
	}
		else {
			printf("Invalid choice!,Enetr the correct car type.");
		}
}
while (choice!=6);
	return 0;
}