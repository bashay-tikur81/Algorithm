#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

long stack[MAX];
int top = -1;

void perform(char, int, int);
int is_numeric_digit(char);
void push(int);
int pop();


int main(){
    int i = 0;
    int first, second;
    char expre[20];
    printf("Enter valid expression: ");
    scanf("%[^\n]", expre);
    while (expre[i] != '\0'){
	if (expre[i] == ' ' || expre[i] == ','){
	    ++i;
	    continue;
	}
	
	else if (expre[i] == '+' || expre[i] == '-' || expre[i] == '*' || expre[i] == '/'){
	    second = pop();
	    first = pop();
	    perform(expre[i], second, first);
	    i++;

	}
	else if (is_numeric_digit(expre[i])){
	    // Extract numeric operand from the string
	    int operand = 0;
	    while(i < strlen(expre) && is_numeric_digit(expre[i])){
		// For numbers for more than one digits, as we are scanning from left right
		operand = (operand * 10) + (expre[i] - '0');
		++i;
	    }
	    push(operand);
	}
    }
    printf("Result: %ld\n", stack[top]);
}

int is_numeric_digit(char ch){
    if (ch >= '0' && ch <= '9') return 1;
    return 0;
}

void perform(char oper, int second, int first){
    int result;
    if (oper == '+') push(first + second);
    else if (oper == '-') push(first - second);
    else if (oper == '*') push(first * second);
    else if (oper == '/') push(first / second);
    else printf("Unexpected operator!\n");
}

int pop(){
    int value;
    if (top == -1){
	printf("No data at the stack\n");
	return 1;
    }
    value = stack[top--];
    return value;
}

void push(int num){
    stack[++top] = num;
}
