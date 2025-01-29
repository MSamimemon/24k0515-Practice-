#include<stdio.h>

int main(){
int seed=1,roll_no,sum=0,roll,i;
do{
	printf("Enter the number of times you want to roll the dice\n");
	scanf("%d",&roll_no);
	if (roll_no<=0){
		printf("Enter the positive value ");
	}
}
while (roll_no<=0);
int result[roll_no];
for (int i=0;i<roll_no;i++){
	roll = (seed * (i + 1) + 1) % 6 + 1; 
       int results[roll_no];
        seed += 4; 

 printf("Roll %d: %d ", i + 1, roll);
	if (roll_no==1){
		printf("you rolled a 1 !\n");}
		else if (roll_no==6){
			printf("you rolled a 6 !\n");
		}
		else if (roll_no>=4){
			printf("higher roll!\n");
		}
		else {
			printf("Lower roll\n");
		}
		sum+=roll;}
		printf("the total sum of the rolls is %d\n",sum);
	

	return 0;
}
