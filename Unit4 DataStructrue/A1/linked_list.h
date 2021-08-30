/*
 *  linked_list.h
 *  Created on: Aug 27, 2021
 *  Author: Ezz Eldeen
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "includes.h"

//effective data
struct Sdata
{
	int ID;
	char name[40];
	float height;
};

//linked list node
struct Node
{
	struct Sdata student;
	struct Node* PNextNode;
};

// APIs
void LinkedList_AddNode (struct Node** head ,struct Sdata data);
int LinkedList_InsertNodeAtFirst (struct Node** head, struct Sdata data);
int LinkedList_AddNode_Index (struct Node** head ,struct Sdata data, unsigned int index);

int LinkedList_deleteFirst (struct Node** head);
int LinkedList_delete_lastNode (struct Node** head);
int LinkedList_deleteKey (struct Node** head, int Key);
int LinkedList_DeleteAll (struct Node** head);

unsigned int LinkedList_length (struct Node* head);
unsigned int LinkedList_lengthIterative (struct Node* head);

int LinkedList_Print (struct Node* head);
void LinkedList_PrintKey (struct Node* head, int id);
void LinkedList_PrintIndex (struct Node* head, int id);

struct Sdata LinkedList_getIndex (struct Node* head, unsigned int index);
struct Sdata LinkedList_getKey (struct Node* head, int id);

struct Sdata LinkedList_get_nth_fromEnd (struct Node* head, int nth);
struct Sdata LinkedList_middle_node (struct Node* head);

int LinkedList_detect_loop(struct Node* head);
int LinkedList_make_circular(struct Node* head);
void Sdata_Print(struct Sdata data);

void LinkedList_reverse(struct Node** head);

#endif /* LINKED_LIST_H_ */
