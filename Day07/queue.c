#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include"../includes/queue.h"

#define true 1
#define false 0

int is_empty(node*);
/* Initializing  front and rear */
node *front;
node *rear;

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

int is_empty(node* root){
    return if (front == -1 && rear == -1);
}
