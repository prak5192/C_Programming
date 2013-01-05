				
//**************************************
// Name: Array Heap Sort
// Description:Sorting an array using heap sort

#include <stdio.h>

void fnSortHeap(int[], int);

void main()
{
	int i, arr_num_items;
	int arr[] = {7,10,25,17,23,27,16,19,37,42,4,33,1,5,11};
	
    //if you do not provide the exact number you might get unwanted results
	
    arr_num_items = 15;
	//call fnSortHeap function for (arr_num_items - 2) times.
	for(i=arr_num_items; i>1; i--)
	{
		fnSortHeap(arr, i - 1);
	}
	//print the sorted array
	printf("\nThe Sorted Array\n----------------\n");
	for (i = 0; i < arr_num_items; i++)
		printf("%d\n",arr[i]);
	return;
}

//sort heap
void fnSortHeap(int arr[], int arr_ubound)
{
    int i,o;
    int lChild, rChild, mChild, root, temp;
//find the root element of the current element
    root = (arr_ubound-1)/2;
//creating the heap
    for(o=root;o>=0;o--)
    {
        for(i=root;i>=0;i--)
        {  
            lChild = (2*i)+1;
            rChild = (2*i)+2;
	        if ((lChild <= arr_ubound) && (rChild <= arr_ubound))
            {
                if(arr[rChild] >= arr[lChild])
                    mChild = rChild;
                else
                    mChild = lChild;
            }
            else
            {
                if(rChild > arr_ubound)
                    mChild = lChild;
                else
                    mChild = rChild;
            }
//swap elements
            if (arr[i] < arr[mChild])
            {
                temp = arr[i];
                arr[i] = arr[mChild];
                arr[mChild] = temp;
            }
        }
    }
//move the max element to the end of the array
    temp = arr[0];
    arr[0] = arr[arr_ubound];
    arr[arr_ubound] = temp;
    return;
}
