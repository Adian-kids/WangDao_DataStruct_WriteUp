#include "stdio.h"
#include "stdlib.h"
#include "sequence_list.h"

void InitList(sequence_list *sequenceList,int size){
	// init the sequence_list
	sequenceList->size = size;
	sequenceList->length = 0;
	sequenceList->head = (Element*)malloc(sizeof(Element) * sequenceList->size);
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

int Length(sequence_list *sequenceList){
	// return the length of sequence_list
	return sequenceList->length;
}

int LocateElem(sequence_list *sequenceList,Element element){
	// get location by value
	int location = -1;
	if (CheckEmpty(sequenceList ) != 1){
		for(int i;i < sequenceList->length;i++){
			if (sequenceList->head[i] == element){
				location = i;
				return  location;
			}	
		}
	}
	return location;
}

Element GetElem(sequence_list *sequenceList,int location){
	// return element by location;
	if (CheckEmpty(sequenceList)){
		if (location >= 0 || location < sequenceList->length)
		{
			return sequenceList->head[location];
		}else{
			return -1;
		}
	}else{
		return -1;
	}
}

void ListInsert(sequence_list *sequenceList,int postion,Element element){
	// insert a value to given postion
	if (CheckFull(sequenceList) == 0){
		for (int i = sequenceList->length - 1; i > postion;i--){
			sequenceList->head[i + 1] = sequenceList->head[i];
		}
		sequenceList->head[postion] = element;
		sequenceList->length++;
	}
}

void ListDelete(sequence_list *sequenceList,int postion){
	// delete a value by give postion
	if (CheckEmpty(sequenceList) == 0){
		for (int i = postion; i < sequenceList->length;i++){
			sequenceList->head[i] = sequenceList->head[i + 1];
		}
		sequenceList->length--;
	}
}

int main(){
	sequence_list sequenceList;
	return 0;
}
