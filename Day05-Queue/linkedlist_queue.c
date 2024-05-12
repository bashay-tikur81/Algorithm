#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../includes/queue.h"

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
