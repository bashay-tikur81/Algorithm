#include<stdio.h>
#include<stdlib.h>

#define MAX 50

void push(int);
int pop();
void print();

int top = -1;
int stack[MAX];

int main(){
    int num, count;
    printf("How many do you want to enter: ");
    scanf("%d", &count);
    while (count >= 0){
	printf("Enter a number: ");
	scanf("%d", &num);
	push(num);
	--count;
    }
    print();
}

void push(int x){
    if (top == MAX-1){
	printf("Error: Stack overflow.\n");
	return;
    }
    stack[++top] = x;
}

int pop(){
    if(top == -1){
	printf("Error: no value to pop\n");
	return 1;
    }
    int value = stack[top];
    --top;
    return value;
}

void print(){
    printf("Stack: ");
    for (int i = 0; i <= top; i++){
	printf("%d ", stack[i]);
    }
    printf("\n");
}
