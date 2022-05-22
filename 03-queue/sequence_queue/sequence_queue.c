#include <stdio.h>
#include <stdlib.h>
#include "sequence_list.h"


void InitList(sequence_list *queue,int size){
	// init the sequence_list
	queue->size = size;
	queue->length = 0;
	queue->head = (Element*)malloc(sizeof(Element) *queue->size);
}

int CheckFull(sequence_list *queue){
	if (queue->length == queue->size){
		return 1;
	}else{
		return 0;
	}
}


int CheckEmpty(sequence_list *queue){
	if (queue->length == 0){
		return 1;
	}else{
		return 0;
	}
}

void inQueue(sequence_list *queue,Element value){
	if(CheckFull(queue) == 0){
		queue->head[queue->length] = value;
		queue->length++;
	}else{
		printf("the queue is full");
	}
} 

Element outQueue(sequence_list *queue){
	Element value;
	if(CheckEmpty(queue) == 0){
		value = queue->head[0];
		for(int i = 0;i < queue->length;i++){
			queue->head[i] = queue->head[i+1];
		}
		queue->length--;
		return value;
	}else{
		printf("the queue is empty");
		return NULL;
	}
}

int getLength(sequence_list *queue){
	return queue->length;
}

Element getFront(sequence_list *queue){
	return queue->head[0];
}

void clear(sequence_list *queue){
	queue->length= 0 ;
}
