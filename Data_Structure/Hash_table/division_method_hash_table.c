/*
	File: division_method_hash_table.c 
	Brief: Performs basic hash table based on division method.
	Date: 6th Jan 2013
	Author: Prakash Ranjan


Typical operation performed on Has table.
=============================================
1. int is_empty()
	Returns true if the hash table is empty. Otherwise, returns false

2. int is_full()
	Returns true if the hash table is full. Otherwise, returns false

3 void insert (const DT &newDataItem)
	Inserts newDataItem into the appropriate list in the hash table. 
	The location (index) in the hash table is determined by 
	the key and the hash function.

4. int remove (KF searchkey)
	Searches the hash table for the data item with the key searchKey. 
	If the data item is found, then removes the data item and returns 
	true. Otherwise, returns false.

5. int retrieve (KF searchkey, DT &dataItem)
	Searches the hash table for the data item with the key searchKey. 
	If the data item is found, then copies the data item to dataItem 
	and returns true. Otherwise, returns false.

6. void clear()
	Removes all data items in the hash table.

7. void showStructure()
	Outputs the data items in a hash table. If the hash table is empty, 
	outputs, "Empty hash table". This is meant for testing/debugging purposes.

*/

#include<stdio.h>

int main(void){
	
	return 0;
}
