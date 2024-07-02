#include <stdio.h>

#include "MyList.h"

int main(int argc, char** argv)
{
	int i = 1;
	int sz;
	sscanf(argv[i++], "%d", &sz);
	int arr[sz];
	for (int j = 0; j < sz; j++) sscanf(argv[i++], "%d", &arr[j]);
	MyListNode* head = InitListFromArr(arr, sz);
	ListPrint(head);
	ListQuickSort(head, NULL);
	ListPrint(head);
	return 0;
}