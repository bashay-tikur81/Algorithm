#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
} node;
node * head;

void print();
void insert(int);
void insertnth(int,int);

int main(){
    head = NULL;
    int holder,position,value;
    printf("Enter 5 numbers for demo:\n");
    for(int i = 1; i <= 5; i++){
	printf("Number %d:",i);
	scanf("%d",&holder);
	insert(holder);
    }
    printf("position to enter:");
    scanf("%d",&position);
    printf("The value is:");
    scanf("%d",&value);
    insertnth(position,value);
    print(head);
}
void insert(int x){
    node * temp = (node*) malloc(sizeof(node));
    if(temp == NULL){
	printf("Can't allocate memory!\n");
	return;
    }
    temp->data = x;
    temp->next = head;
    head = temp;
}

void insertnth(int place, int value){
    node* temp;
    temp = head;
    if(place == 1){
	node * temp1;
	temp1 = (node*) malloc(sizeof(node));
	temp1->data = value;
	temp1->next = head;
	head = temp1;
	return;
    }
    int counter = 1;
    while(temp != NULL){
	if(place == counter+1){
	    node * temp1;
	    temp1 = (node*) malloc(sizeof(node));
	    temp1->data = value;
	    temp1->next = temp->next;
	    temp->next = temp1;
	    break;
	}
	temp = temp->next;
	counter++;
    }
}
void print(node *Node){
    printf("List is:");
    while(Node != NULL){
	printf(" %d",Node->data);
	Node = Node->next;
    }
    printf("\n");
}
