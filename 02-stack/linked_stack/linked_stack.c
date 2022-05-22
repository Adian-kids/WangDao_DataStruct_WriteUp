#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

node *initLinkStack(){
	// have head pointer
	node *head;
	head = (node *)malloc(sizeof(node));
	head->next = NULL;
	return head;
}

  
int getlength(node *head){
	// get the length of the linked list
	int num = 0;
	node *pointer = head;
	while (pointer->next != NULL)
	{
		num++;
		pointer = pointer->next;
	}
	return num;
}

void  push(node *head,Element value){
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = value;
	new_node->next = head->next;
	head->next = new_node;
}

Element pop(node *head){
	Element top = head->next->data;
	head->next = head->next->next;
	return top;
}


int checkEmpty(node *head){
	if (getlength(head) == 0){
		return 1;
	}else{
		return 0;
	}
}
