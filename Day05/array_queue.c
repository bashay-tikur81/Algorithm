#include<stdio.h>
#include<stdlib.h>

#define MAX 50
#define true 1
#define false 0

int queue [MAX];
int front = -1;
int rear = -1;
int is_empty();
int is_full();
void enqueue(int);
int dequeue();

int main(){
    int i, j, count, num;
    printf("How many to queue: ");
    scanf("%d", &count);
    for (i = 0; i < count; i++){
	printf("Number [%d]: ", i);
	scanf("%d", &num);
	enqueue(num);
    }

    printf("FIFO...\n");
    while (queue[j] != 0){
	printf("%d%c", dequeue(), (queue[j + 1] == 0)?'.':' ');
	++j;
    }
    printf("\n");
}

void enqueue(int num){
    if (is_full())
	printf("Not available space\n");
    else if (is_empty()){
	++rear;
	++front;
    }
    else {
	
	rear = (rear + 1) % MAX;
    }
    queue[rear] = num;

}

int dequeue(){
    int value = 0;
    if (is_empty()){
	printf("Error: no value to dequeue.\n");
	return false;
    }
    else if (front == rear){
	value = queue[front];
	front = -1;
	rear = -1;
    }
    else {
	value = queue[front];
	front = ((front + 1) % MAX);
    }
    return value;
    
}
int is_full(){
    // if rear's and front's value, in rear -> front order,are consecutive the array is full
    if ((rear + 1) % MAX == front)
	return true;
    else return false;
}

int is_empty(){
    if ((front == -1) && (rear == -1))
	return true;
    else
	return false;
}
