#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../includes/node_queue.h"

#define true 1
#define false 0

/*
  node and queue_node are structures defined in ../includes/node_queue.h
*/
node* root;
// Traversal Functions
void level_order(node *); // this breadth first traversal
node* insert(node *, int);
node* give_me_node(int);
int is_empty(queue_node *);

int main(){
    int num, i = 1, counter;
    root = NULL;
    printf("How many data to enter: ");
    scanf("%d", &counter);
    while (i <= counter){
	printf("Number %d: ", i);
	scanf("%d", &num);
	root = insert(root, num);
	++i;
    }
    level_order(root);
}

node* insert(node *root, int data){
    if (root == NULL){
	root = give_me_node(data);
    }
    else if (data <= root->data){
	root->left = insert(root->left, data);
    }
    else {
	root->right = insert(root->right, data);
    }
    return root;
}

node* give_me_node(int value){
    node* new_node = (node*) malloc(sizeof(node));
    if (new_node == NULL){
	printf("Can't allocate memory.\n");
	exit(1);
    }
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void level_order(node * root){
    int value;
    node *current;
    if (root == NULL) return;
    enqueue(root);
    while(!is_empty(front)){
	//node *current = front;
	current = front->nodeq;
	printf("%d, ", current->data);
	if (current->left != NULL)
	    enqueue(current->left);
	if (current->right != NULL)
	    enqueue(current->right);
	dequeue(); /* This returns node*, but we don't need it. so we don't use it */
    }

}

/* Checking if the queue is empty or not */

int is_empty(queue_node *nodea){
    if(nodea == NULL)
	return 1;
    else
	return 0;
    
}
