#include <stdio.h>
#include <stdlib.h>
#include "sequence_list.h"

// basic operation

void InitStack(sequence_list *stack,int size){
	// init the stack
	stack->size = size;
	stack->length = 0;
	stack->head = (Element*)malloc(sizeof(Element) *stack->size);
}


int CheckFull(sequence_list *stack){
	if (stack->length == stack->size){
		return 1;
	}else{
		return 0;
	}
}

int CheckEmpty(sequence_list *stack){
	if (stack->length == 0){
		return 1;
	}else{
		return 0;
	}
}    


void push(sequence_list *stack, Element element){
	if (CheckFull(stack) == 0){
		for(int i = stack->length - 1; i > 0; i--){
			stack->head[i + 1] = stack->head[i];
		}
		stack->head[0] = element;
		stack->length++;
	}else{
		printf("the stack is full");
	}
}



Element pop(sequence_list *stack){
	Element topElement;
	if(CheckEmpty(stack) == 0){
		topElement = stack->head[0];	
		for(int i = 0;i < stack->length - 1;i++){
			stack->head[i] = stack->head[i + 1];
			stack->length--;
		}
		return topElement;
	}else{
		printf("the stack is empty");
		return  NULL;
	}
}

Element getTop(sequence_list *stack){
	Element topElement;
	if(CheckEmpty(stack) == 0){
		topElement = stack->head[0];	
		return topElement;
	}else{
		printf("the stack is empty");
		return  NULL;
	}
}
