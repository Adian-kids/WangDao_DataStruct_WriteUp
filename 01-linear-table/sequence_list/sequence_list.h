// define the element type to int,and it can be any type
typedef int Element;
// struct of sequence_list
typedef struct{
	Element *head;
	int length; // have used length now
	int size; 	// init size(maxsize)
}sequence_list;
