#include<stdio.h>

int main(){
	int incomeamount ;
	float  tax;
	printf("Enter the Income Amount\n");
	scanf("%d",&incomeamount);
	if (incomeamount < 250000){
	tax = 0;
	}
	if (incomeamount >=250000 && incomeamount <=500000){
	tax = 0.05*(incomeamount - 250000 );
	}
    if (incomeamount> 500000 && incomeamount <= 1000000){
    tax = 0.05*(500000 - 250000 ) + 0.2*(incomeamount - 500000 );
	
}
    else if (incomeamount>1000000){
    tax = 0.05*(500000 - 250000 ) + 0.2*(1000000 -500000 ) + 0.3*(incomeamount - 1000000);
}
    printf("The total tax you need to pay is %.2f",tax);
	return 0;
}
