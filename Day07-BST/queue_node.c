#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include"../includes/node_queue.h"

/*
  queue_node and node are structures defined in ../includes/node_queue.h
  The following snippets just enqueue and dequeue a node.
*/

queue_node *front;
queue_node *rear;
extern queue_node *front;
extern queue_node *rear;

void enqueue(node *);
//queue_node* dequeue();
node* dequeue();

void enqueue(node *child){
    queue_node *new_node = (queue_node*) malloc(sizeof(queue_node));
    new_node->nodeq = child;
    new_node->next = NULL;
    if (front == NULL && rear == NULL){
	front = rear = new_node;
    }
    else {
	rear->next = new_node;
	rear = new_node;
    }
}
node* dequeue(void){
    node* nodea;
    if (front == NULL && rear == NULL){
	printf("No value to dequeue.");
	exit(1);
    }
    else if (front == rear){
	nodea = front->nodeq;
	front = rear = NULL;
    }
    else {
	nodea = front->nodeq;
	front = front->next;
    }

    return nodea;
}
