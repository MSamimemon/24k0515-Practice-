#include<stdio.h>

int main(){
int marks1 , marks2 , marks3;
printf("Enter your Marks 1\n");	
scanf("%d",&marks1);
printf("Enter your Marks 2\n");	
scanf("%d",&marks2);
printf("Enter your Marks 3\n");	
scanf("%d",&marks3);
printf("The marks are %d,%d and %d\n", marks1 , marks2 , marks3 );
if(marks1 < 33 || marks2 < 33 || marks3 < 33 ){
	printf("Your Are Failed Due To The Less Marks In Your Individual Subjects");
}
else if ((marks1 + marks2 + marks3)/3<40){
	printf("You Are Failed Due To Less Percentage");
}
else {
	printf("You Are Passed!");
}

	return 0;
}
