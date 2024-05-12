// The following program is used to reverse a linked list
#include<stdio.h>
#include<stdlib.h>
// creating a structure with an alias using typedef
typedef struct node{
    int data;
    struct node * next;
} node;
node* head;

void reverse_linked();
void insert_begin(int );
void print(int);



int main(){
    head = NULL;
    int elements, i, j = 0;
    printf("Inserting data to the beginning of the list.\n");
    printf("Number of elements to enter: ");
    scanf("%d",&i);
    while(j < i){
	printf("Element at [%d]: ",j);
	scanf("%d",&elements);
	insert_begin(elements);
	j++;
    }
    print(i);
    reverse_linked();
}

void insert_begin(int x){
    node *temp = (node*)malloc(sizeof(node));
    if(temp != NULL){
	temp->data = x;
	temp->next = head;
	head = temp;
    }
}
void print(int decider){
    node *temp = head;
    if(decider == -1)
	printf("The reversed form of the linked list is:\n[");
    else
	printf("Inserted data(s) are:\n[");
    while(temp != NULL){
	printf("%d ",temp->data);
	temp = temp->next;
    }
    printf("]\n");
}

void reverse_linked(){
    node *current, *nextn, *prev;
    current = head;
    prev = NULL;
    while(current != NULL){
	nextn = current->next;
	current->next = prev;
	prev = current;
	current = nextn;
    }
    head = prev;
    print(-1);
    
}
