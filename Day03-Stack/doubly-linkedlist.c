#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node* get_new_node(int);
void insert_at_head(int);
void insert_at_tail(int);
void print_forward(node *);
void print_reverse(node *);

node *head; // making head for global scope, to be accessed by all functions

int main(){
    int num, counter;
    printf("How many you want to add?: ");
    scanf("%d",&counter);
    while (counter > 0) {
	printf("Number: ");
	scanf("%d",&num);
	insert_at_tail(num);
	--counter;
    }
    print_forward(head);
    print_reverse(head);
}

void insert_at_head(int data){
    node *new_node = get_new_node(data);
    if (head == NULL){
	head = new_node;
	return ;
    }
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}
void insert_at_tail(int data){
    node *new_node = get_new_node(data);
    node *temp = head;
    if (head == NULL){
	head = new_node;
	return ;
    }
    while (temp->next != NULL){
	temp = temp->next;
    }
    new_node->prev = temp;
    temp->next = new_node;
}

node* get_new_node(int x){
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void print_forward(node * headp){
    printf("Forward printing: \n");
    while (headp != NULL){
	printf("%d ", headp->data);
	headp = headp->next;
    }
    printf("\n");
}

void print_reverse(node *headr){
    if (headr == NULL) return;
    printf("Reverse printing:\n");
    /* Going to the last node */
    while (headr->next != NULL){
	headr = headr->next;
    }
    /* Traversing back ward for printing */
    while(headr != NULL){
	printf("%d ", headr->data);
	headr = headr->prev;
    }
    printf("\n");
}
