#include<stdio.h>
#include<string.h>

int main(){
    char pal[20];
    printf("Enter a text: ");
    scanf("%s",pal);
    int len = strlen(pal);
    int counter = -1;
    int palin = 1;
    while(++counter <= --len){
	if(pal[counter] != pal[len]){
	    palin = 0;
	    break;
	}
    }
    if(palin)
	printf("%s is palindrome.\n",pal);
    else
	printf("%s is not palindrome.\n",pal);

}

