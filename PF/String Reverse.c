#include<stdio.h>
#include<string.h>
void reverseword(char sentence[]){
	char reversed[100]="";
	char word[20];
	int length=0;
	length=strlen(sentence);
	for (int i=length-1;i>=0;i--){
		if (sentence[i]==' '|| i==0){
			int start;
			if (i==0){
				start=i;
			}
			else{
				start=i+1;
			}
			int k=0;
			do {
				word[k++]=sentence[start++];
			}
			while (sentence[start]!=' '&& sentence[start]!='\0'&& sentence[start]!='\n');
			word[k]='\0';
			strcat(reversed,word);
			strcat(reversed," ");
		}
	}
	reversed[strlen(reversed)-1]='\0';
	strcpy(sentence,reversed);
}
int main(){
char sentence[100];
printf("Enter the sentence: ");
fgets (sentence,sizeof(sentence),stdin);
	sentence[strcspn(sentence,"\n")]='\0';
	reverseword(sentence);
	printf("The reversed sentence is %s",sentence);
	return 0;}	
