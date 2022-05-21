#include <stdio.h>
#include <stdlib.h>
#include "sequence_list.h"

// basic operation
void InitList(sequence_list *sequenceList,int size){
	// init the sequence_list
	sequenceList->size = size;
	sequenceList->length = 0;
	sequenceList->head = (Element*)malloc(sizeof(Element) *sequenceList->size);
}


int CheckFull(sequence_list *sequenceList){
	if (sequenceList->length == sequenceList->size){
		return 1;
	}else{
		return 0;
	}
}


int CheckEmpty(sequence_list *sequenceList){
	if (sequenceList->length == 0){
		return 1;
	}else{
		return 0;
	}
}


// push
void push(Element value){

}
