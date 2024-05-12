#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
} node;

void insert(int);
void print();

node* head;
int main(){
    // Inserting a node at beginning

    head = NULL;
    int n,holder;
    printf("How many integer to enter: ");
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
	printf("Number %d:",i);
	scanf("%d",&holder);
	insert(holder);
	print();
    }
}
void insert(int x){
    node * temp = (node*) malloc(sizeof(node));
    if(temp != NULL){
	temp->data = x;
	temp->next = head;
	head = temp;
    }
}
void print(){
    node * temp = head;
    printf("List is:");
    while(temp != NULL){
	printf(" %d",temp->data);
	temp = temp->next;
    }
    printf("\n");
}
