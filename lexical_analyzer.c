lexical analyzer

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int iskeyword(char buffer[]){
char keywords[32][10] = {
	"auto","break","case","if","while","do"
};
int i;
for(i=0;i<32;i++){
if(strcmp(keywords[i], buffer) == 0){
return 1;
}
}
return 0;
}
int main(){
char ch, buffer[15];
char operators[] ="+-*/%=";
FILE *fp;
int i,j = 0;
fp = fopen("input.txt", "r");
if(fp == NULL){
printf("error opening the file\n");
exit(0);
}
printf("token found:\n");
while((ch=fgetc(fp)) != EOF){
	for(i=0;i<strlen(operators);++i){
		if(ch == operators[i]){
			printf("operator: %c \n", ch);
			break;
		}
	}
	if(isalnum(ch)){
		buffer[j++] = ch;
	}
	else if((ch == ' ' ||ch == '\n'||ch == '\t') && (j!=0)){
		buffer[j] = '\0';
		j = 0;
		if(iskeyword(buffer)==1){
			printf("keyword:%s\n",buffer);
		}
		else{
			printf("identifier: %s\n", buffer);
		}
	}
	else if(isdigit(ch)){
		printf("number: %c\n", ch);
	}
}
fclose(fp);
return 0;
}
