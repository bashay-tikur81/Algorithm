#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *front;
node *rear;

void enqueue(int);
int dequeue();


int main(){
    int i = 0, num, counter;
    printf("Linked list implementation of queue.\n");
    printf("How many you want to queued? ");
    scanf("%d", &counter);
    while (i < counter){
	printf("Number [%d]: ", i);
	scanf("%d", &num);
	enqueue(num);
	++i;
    }
    printf("LIFO...\n");
    for(int j = 0; j < counter; j ++){
	printf("%d%s", dequeue(),(j+1 == counter)?".": ", ");
    }
    printf("\n");
}

void enqueue(int num){
    node *temp = front;
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = num;
    new_node->next = NULL;
    if (front == NULL && rear == NULL){
	front = rear = new_node;
    }
    else {
  	rear->next = new_node;
	rear = new_node;
	
    }
}

int dequeue(){
    int value = 0;
    node *temp = front;
    if (front == NULL){
	printf("No value to dequeue!");
	return 0;
    }
    else if (front == rear){
	value = front->data;
	front = rear = NULL;
    }
    else {
	value = front->data;
	front = front->next;
    }
    free(temp);
    return value;
	
}
