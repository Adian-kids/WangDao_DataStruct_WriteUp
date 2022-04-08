#include "stdio.h"
#include "stdlib.h"
#include "sequence_list.h"

// basic operation

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
		// here has a issue,if just i>postion,because use [i+1= i]
		// so should use i>=postion
		// for example 
		// if postion = 1
		// > postion mean that min is 2
		// so just can move to head[3]
		// so the head[2] will be not move to new value
		for (int i = sequenceList->length - 1; i >= postion;i--){
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

void PrintList(sequence_list *sequenceList){
	// print all element
	for (int i = 0;i < sequenceList->length;i++){
		printf("%d \t",sequenceList->head[i]);
	}
	printf("\n");
}

void DestoryList(sequence_list *sequenceList){
	free(sequenceList);
}

void Append(sequence_list *sequenceList,Element element){
	if(CheckFull(sequenceList) != 1){
		sequenceList->head[sequenceList->length] = element;
	}
	sequenceList->length++;
}


// wangdao 


// 01
Element del_min(sequence_list *sequenceList){
	Element min = 0;
	for (int i = 1;i < sequenceList->length;i++){
		if (sequenceList->head[i] < sequenceList->head[min]){
			min = i;  
		}
	}
	Element min_element = sequenceList->head[min];
	sequenceList->head[min] = sequenceList->head[sequenceList->length-1];
	sequenceList->length--;
	return min_element;
}
// 02
void Reverse(sequence_list *sequenceList){
	Element temp;
	for (int i = 0; i < sequenceList->length/2;i++){
		temp = sequenceList->head[i];	
		sequenceList->head[i] = sequenceList->head[sequenceList->length - 1 - i];
		sequenceList->head[sequenceList->length - 1 - i] = temp;
	}
}

// 03
void del_value_x(sequence_list *sequenceList,Element x){
	int k = 0;
	for(int i = 0;i < sequenceList->length;i++){
		if (sequenceList->head[i] != x){
			sequenceList->head[k] = sequenceList->head[i];
			k++;
		}
	}
	sequenceList->length = k;
}

// 04

void del_x_to_y(sequence_list *sequenceList,int s,int t){
	if (CheckEmpty(sequenceList) == 1){
		printf("it's a empty sequenceList");
	}else{
		if (s >= t || sequenceList->head[0] < s || sequenceList->head[sequenceList->length - 1] > t){
			printf("wrong value");
		}else{
			for(int i = 0;i < sequenceList->length;i++){
				if (sequenceList->head[i] > s || sequenceList->head[i] < t){
					for(int j = i;j < sequenceList->length;j++){
						sequenceList[j] = sequenceList[j+1];
					}
					sequenceList->length--;
				}		
			}
		}
	}
}







int main(){
	//base function test
	sequence_list sequenceList;
	InitList(&sequenceList,5);

	Append(&sequenceList,1);
	Append(&sequenceList,2);
	Append(&sequenceList,3);
	Append(&sequenceList,4);
	PrintList(&sequenceList);

	ListInsert(&sequenceList,1,100);
	PrintList(&sequenceList);

	ListDelete(&sequenceList,2);
	PrintList(&sequenceList);


	// wangdao 01
	printf("wangdao 01\n");
	int min = del_min(&sequenceList);
	printf("the min value:%d\n ",min);
	PrintList(&sequenceList);
	
	// append some value
	Append(&sequenceList,21);
	Append(&sequenceList,21);

	// wangdao 02
	printf("wangdao 02\n");
	Reverse(&sequenceList);
	PrintList(&sequenceList);
	// wangdao 03
	printf("wangdao 03\n");
	del_value_x(&sequenceList,21);
	PrintList(&sequenceList);
	// wangdao 04 no test
	printf("wangdao 04\n");


	
	return 0;
}
