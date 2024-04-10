#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node *top;

void push_at_top(int);
void push_at_tail(int);
int pop_at_top();
int pop_at_tail();


int main(){
    top = NULL;
    int counter, num, i = 0, j = 0;
    printf("Linked list implementation of stack.\n\n");
    printf("How many numbers you want to push to tail? ");
    scanf("%d",&counter);
    printf("Pushing to tail of stack ...\n");
    while (i < counter){
	printf("Number[%d]: ",i);
	scanf("%d", &num);
	push_at_tail(num);
	++i;
    }
    printf("Printing from the tail ...\n");
    while (counter > 0){
	printf("%d ", pop_at_tail());
	--counter;
    }
    printf("\n");

    
    printf("How many numbers you want to push to head? ");
    scanf("%d",&counter);
    printf("Pushing to beginning of stack ...\n");
    while (j < counter){
	printf("Number[%d]: ", j);
	scanf("%d", &num);
	push_at_top(num);
	++j;
    }
    printf("Printing from beginning of stack ...\n");
    while (counter > 0){
	printf("%d ", pop_at_top());
	--counter;
    }
    printf("\n");
}

void push_at_top(int x){
    node *new_node = (node *) malloc(sizeof(node));
    if(new_node == NULL){
	printf("Can't allocate memory.\n");
	return;
    }
    new_node->data = x;
    new_node->next = top;
    top = new_node;
}
void push_at_tail(int x){
    node *temp = top;
    node *new_node = (node*) malloc(sizeof(node));
    if(new_node == NULL){
	printf("Can't allocate memory.\n");
	return;
    }
    new_node->data = x;
    new_node->next = NULL;
    if (top == NULL){
	top = new_node;
	return;
    }
    while (temp->next != NULL){
	temp = temp->next;
    }
    temp->next = new_node;
}
int pop_at_tail(){
    int value;
    node *second_last;
    node *temp = top;
    while (temp->next != NULL){
	second_last = temp;
	temp = temp->next;
	
    }
    value = temp->data;
    free(temp);
    second_last->next = NULL;
    return value;
}
int pop_at_top(){
    int value;
    node *temp;
    if (top == NULL) return 1;
    
    value = top->data;
    temp = top;
    top = top->next;
    free(temp);
    return value;
}

