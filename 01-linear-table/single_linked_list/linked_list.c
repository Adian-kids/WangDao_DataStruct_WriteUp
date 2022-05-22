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

void display(node *head)
{
	// print list->next
	node *pointer = head->next;
	if (!pointer)
	{
		printf("the linked list is empty\n");
	}
	else
	{
		for (int i = 0; i < getlength(head); i++)
		{
			printf("%d \t", pointer->data);
			pointer = pointer->next;
		}
		printf("\n");
	}
}
node *find(node *head, int location)
{
	// find node by location
	node *pointer = head;
	if (location < 0 || location > getlength(head) - 1)
	{
		printf("there's no this location\n");
		return NULL;
	}
	for (int i = 0; i < location; i++)
	{
		pointer = pointer->next;
	}
	return pointer;
}

void insert(node *head, int location, Element value)
{
	// insert a value in the linked_list
	node *pointer = head;
	node *new_node = (node *)malloc(sizeof(node));
	if (location < 0)
	{
		printf("location too low\n");
		for (int i = 0; i < location; i++)
		{
			pointer = pointer->next;
			if (pointer == NULL)
			{
				printf("location too high");
			}
		}
	}

	new_node->data = value;
	new_node->next = pointer->next;
	pointer->next = new_node;
}

void delete (node *head, int location)
{
	node *pre = head;
	node *pointer = head->next;
	int length = getlength(head);
	if (location <= 0 || location > length - 1)
	{
		printf("wrong location!\n");
	}
	else
	{
		for (int i = 0; i < location; i++)
		{
			pointer = pointer->next;
			pre = pre->next;
		}
		pre->next = pointer->next;
	}
}

int main(void)
{
	node *head = initLinkList();
	display(head);
	insert(head, 0, 1);
	insert(head, 1, 3);
	insert(head, 1, 2);
	display(head);
	find(head, 2);
	delete (head, 1);
	display(head);
}
