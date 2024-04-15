#include<stdio.h>
#include<stdlib.h>

#define MAX 50
#define true 1
#define false 0

char stack[MAX];
int top = -1;
int are_pair(char, char);
int are_balanced(char *);
void push(char);
void pop();

int main(){
    char expression[30];
    printf("Write an expression: ");
    /* the expression %[^\n] helps to read scanf until new line feed is encountered */
    /* if you want to discards the new line character add %*c after %[^\n] */
    scanf("%[^\n]",expression);
    if(are_balanced(expression))
	printf("The expression are balanced!\n");
    else
	printf("Unbalanced Expression!\n");
}

int are_balanced(char expre[]){
     for (int i = 0;expre[i] != '\0'; i++){
	if (expre[i] == '(' || expre[i] == '[' || expre[i] == '{' || expre[i] == '<')
	    push(expre[i]);
	else if (expre[i] == ')' || expre[i] == ']' || expre[i] == '}' || expre[i] == '>'){
	    if(top == -1 || !are_pair(stack[top], expre[i]))
		return false;
	    else
		pop();
	}
     }
     return (top == -1)?true:false;
}

int are_pair(char opening, char closing){
    if (opening == '(' && closing == ')') return true;
    else if (opening == '[' && closing == ']') return true;
    else if (opening == '{' && closing == '}') return true;
    else if (opening == '<' && closing == '>') return true;
    else return false;
    
    
}
void push(char ch){
    stack[++top] = ch;
    
}
void pop(){
    if (top == -1) printf("No data on stack.\n");
    --top;
}
