#include<stdio.h>
#include<math.h>
#include<string.h>


int BinaryToDecimal(int number); 
int DecimalToBinary(int number); 
void DecimalToHexadecimal(int number); 
void HexadecimalToDecimal(char number2[100]); 
void BinaryToHexadecimal(int number); 
void HexadecimalToBinary(char number2[100]);


int main(){

int choice,number;
char number2[100];

printf("1. To Convert from Binary To Decimal\n");
printf("2. To Convert from Decimal To Binary\n");
printf("3. To Convert from Decimal To HexaDecimal\n");
printf("4. To Convert from HexaDecimal To Decimal\n");
printf("5. To Convert from Binary To HexaDecimal\n");
printf("6. To Convert from HexaDecimal To Binary\n");

scanf("%d",&choice);
getchar();
if(choice == 4 || choice == 6){
    printf("Enter number to be converted\n");
    fgets(number2, sizeof(number2), stdin);
    number2[strcspn(number2, "\n")] = '\0';
}



switch (choice)
{
case 1 :
    printf("Enter number to be converted\n");
    scanf("%d",&number);
     printf("Your Decimal Number is %d\n",BinaryToDecimal(number)); 
    break;

case 2 : 

printf("Enter number to be converted\n");
scanf("%d",&number);
    printf("Your Binary Number is %d",DecimalToBinary(number));
    break;

case 3 :
printf("Enter number to be converted\n");
scanf("%d",&number);
DecimalToHexadecimal(number);
    break;

case 4 :


HexadecimalToDecimal(number2); 
    break;

case 5 :
printf("Enter number to be converted\n");
scanf("%d",&number);
BinaryToHexadecimal(number); 
    break;  

case 6 :HexadecimalToBinary(number2);
    break;    

default: 

    printf("Enter Valid Choice\n");

    break;
}
    return 0;
}


int BinaryToDecimal(int number){
int sum=0 , digit;
int n=0;
for(;number!=0;){
    digit=number%10;
    sum=sum + digit*pow(2,n);
    n++;
    number = number/10;
}
return sum;
}


int DecimalToBinary(int number){

int remainder;
int count2=0;
int binary=0;
int binary2=0;
int count=0;

for(;number>=0;){

    if(number==0){
        count++;
        if(count>1){
            break;
        }
    }
    remainder=number%2;
    binary=binary*10 + remainder ;
    number = number/2;
}

for(;binary>=0;){

    if(binary==0){
        count2++;
        if(count2>1){
            break;
        }
    }

    remainder=binary%10;
    binary2=binary2*10 + remainder ;
    binary = binary/10;
}

return binary2;

} 


void DecimalToHexadecimal(int number){

int remainder;
char remainder2;
char hex[200];
int hex2=0;
int count=0;

for(int i=0;i<200;i++){
    
    remainder=number%16;
    number = number/16;
    if(remainder==10){
           remainder2='A';
           hex[i]=remainder2 ;
           
        }
        else if(remainder==11){
            remainder2='B';
            hex[i]=remainder2 ;
            
        }
        else if(remainder==12){
            remainder2='C';
            hex[i]=remainder2 ;
            
        }
        else if(remainder==13){
            remainder2='D';
            hex[i]=remainder2 ;
             
        }
        else if(remainder==14){
            remainder2='E';
            hex[i]=remainder2 ;
         
        }
        else if(remainder==15){
           remainder2='F';
           hex[i]=remainder2 ;
         
        }
        else if(remainder<10){
             hex[i]=remainder + '0';
            
        }
        if (number==0)
        {
            count=i+1;
            break;
        }  
}
hex[count]='\0';

printf("Your Hexadecimal number is \n");

for(int i=count-1;i>=0;i--){
    printf("%c",hex[i]);
}

}
void HexadecimalToDecimal(char number2[100]){
    
// char number[100];
int sum=0,k=0;
int count = strlen(number2);

for(int i=count;i>=0;i--){
    if(number2[i]<='9' && number2[i]>='0'){
    sum=sum +(number2[i] - '0')*pow(16,k);
    k++;
    }
    else if(number2[i]<='F' && number2[i]>='A'){
    sum=sum+(number2[i] - '7')*pow(16,k);
    k++;
    }
}

printf("Your decimal is %d",sum);

}

void BinaryToHexadecimal(int number){

//Binary to decimal
    int sum=0 , digit;
int n=0;
for(;number!=0;){
    digit=number%10;
    sum=sum + digit*pow(2,n);
    n++;
    number = number/10;
}
number=sum;
//decimal to hexadecimal
int remainder;
char remainder2;
char hex[200];
int hex2=0;
int count=0;

for(int i=0;i<200;i++){

    remainder=number%16;
    number = number/16;
    if(remainder==10){
           remainder2='A';
           hex[i]=remainder2 ;
           
        }
        else if(remainder==11){
            remainder2='B';
            hex[i]=remainder2 ;
            
        }
        else if(remainder==12){
            remainder2='C';
            hex[i]=remainder2 ;
            
        }
        else if(remainder==13){
            remainder2='D';
            hex[i]=remainder2 ;
             
        }
        else if(remainder==14){
            remainder2='E';
            hex[i]=remainder2 ;
         
        }
        else if(remainder==15){
           remainder2='F';
           hex[i]=remainder2 ;
         
        }
        else if(remainder<10){
             hex[i]=remainder + '0';
            
        }
        if (number==0)
        {
            count=i+1;
            break;
        }  
}
hex[count]='\0';

printf("Your Hexadecimal number is \n");

for(int i=count-1;i>=0;i--){
    printf("%c",hex[i]);
}
}

void HexadecimalToBinary(char number2[100]){
//Hexa to decimal
int sum=0,k=0;
int count = strlen(number2);

for(int i=count-1;i>=0;i--){
    if(number2[i]<='9' && number2[i]>='0'){
    sum=sum +(number2[i] - '0')*pow(16,k);
    k++;
    }
    else if(number2[i]<='F' && number2[i]>='A'){
    sum=sum+(number2[i] - '7')*pow(16,k);
    k++;
    }
}
int number;
number=sum;

//Deciaml to Binary
int remainder;
int count2=0;
int binary=0;
int binary2=0;
int count3=0;
for(;number>=0;){

    if(number==0){
        count3++;
        if(count3>1){
            break;
        }
    }
    remainder=number%2;
    binary=binary*10 + remainder ;
    number = number/2;
}

for(;binary>=0;){

    if(binary==0){
        count2++;
        if(count2>1){
            break;
        }
    }

    remainder=binary%10;
    binary2=binary2*10 + remainder ;
    binary = binary/10;
}

printf("%d",binary2) ;
}