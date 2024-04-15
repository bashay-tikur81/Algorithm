#include<stdio.h>
#include<stdlib.h>

#define MAX 50

void push(char);
char pop();
char string[MAX];
int top = -1;

int main(){
    int i = 0;
    char string[MAX] = "I love C programming";
    while(string[i] != '\0'){
	push(string[i]);
	++i;
    }
    printf("Reverse character of %s is: ", string);
    while (i-- > 0){
	printf("%c",pop());
    }
    printf("\n");
}

void push(char ch){
    string[++top] = ch;
}

char pop(){
    char value;
    if(top == -1) return 1;
    value = string[top--];
    return value;
}
