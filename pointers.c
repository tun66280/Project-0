#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20



int main(){

char string1[SIZE];

printf("%s", "Enter a string (no longer than 19 characters):");
scanf("%19s",string1);


for(size_t i = 0; i<SIZE && string1[i]!='\0';i++){
if(string1[i]=='\0'){printf("I told you anim");}

}






    return 0;
}