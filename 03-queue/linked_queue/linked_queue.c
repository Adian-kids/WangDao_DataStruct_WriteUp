#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"



node *initLinkList()
{
	// init header pointer
	node *head;
	head = (node *)malloc(sizeof(node));
	head->next = NULL;
	return head;
}

int getlength(node *head)
{
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

int checkEmpty(node *head){
	if(head->next == NULL){
		return 1;
	}else{
		return 0;
	}
}

void inQueue(node *head,Element value){
	node *pointer = head;
	node *new_node = (node *)malloc(sizeof(node));
	while (pointer->next != NULL){
		pointer = pointer->next;
	}
	new_node->data = value;
	pointer->next = new_node;
	new_node->next = NULL;
}

Element outQueue(node *head,Element value){
	node *pointer = head->next;
	head->next = head->next->next;
	return  pointer->data;
}

void clear(node *head){
	head->next = NULL;
}

Element getFront(node *head){
	Element value;
	value = head->next->data;
	return value;
}
