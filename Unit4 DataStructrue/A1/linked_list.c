/*
 *  linked_list.c
 *  Created on: Aug 27, 2021
 *  Author: Ezz Eldeen
 */


#include "linked_list.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
struct SStudent* gpFirstStudent = NULL;


// Add node to an existing linked list.
void LinkedList_AddNode (struct Node** head ,struct Sdata data)
{
	struct Node* new;
	struct Node* lastNode;

	new = (struct Node*)malloc (sizeof(struct Node));
	new->student = data;
	new->PNextNode = NULL;

	//check list is empty
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		lastNode = *head;
		while(lastNode->PNextNode)
		{
			lastNode = lastNode->PNextNode ;
		}
		lastNode->PNextNode = new ;
	}
}

// Add node at first.
int LinkedList_InsertNodeAtFirst (struct Node** head, struct Sdata data)
{
	struct Node* new;
	new = (struct Node*)malloc (sizeof(struct Node));
	new->student = data;
	new->PNextNode = *head;
	*head = new;
	return 1;
}

// Add Node at index.
int LinkedList_AddNode_Index (struct Node** head ,struct Sdata data, unsigned int index)
{
	int len=0;
	len = LinkedList_length(*head);

	// wrong index longer than nodes.
	if( index > (len) )
	{
		return 0;
	}

	// Add node at first.
	else if (index == 0 )
	{
		LinkedList_InsertNodeAtFirst(head, data);
		return 1;
	}

	// Add node at last.
	else if(index == len)
	{
		LinkedList_AddNode(head, data);
		return 1;
	}

	// In between nodes.
	else
	{
		struct Node* current = (struct Node*)(*head);
		struct Node* last = NULL;
		int i = 0;

		struct Node* new;
		new = (struct Node*)malloc (sizeof(struct Node));
		new->student = data;
		//new->PNextNode = *head;
		while(current)
		{
			if (index == i)
			{
				last->PNextNode = new ;
				new->PNextNode = current;
				return 1;
			}
			last = current;
			current = current->PNextNode;
			i++;
		}
		return 0;
	}
}

// Delete the first node of the list.
int LinkedList_deleteFirst (struct Node** head)
{
	// empty list
	if (*head == NULL)
	{
		printf("No nodes to delete\n");
		return 10;
	}
	struct Node* current = (struct Node*)(*head)->PNextNode;
	free(head);
	(*head) = current;
	return 1;
}

// Delete Last Node of list.
int LinkedList_delete_lastNode (struct Node** head)
{
	struct Node* current = (struct Node*)*head;
	struct Node* last = NULL;

	// empty list
	if (*head == NULL)
	{
		printf("No nodes to delete\n");
		return 0;
	}

	// only one node
	if ((*head)->PNextNode == NULL)
	{
		*head = current->PNextNode;
		free(current);
		return 1;
	}

	// more than 1 node
	while(current->PNextNode)
	{
		last = current ;
		current = (struct Node*)current->PNextNode ;
	}
	last->PNextNode = NULL;
	free(current);
	last = last->PNextNode;
	free(last);

	return 1;
}

// Delete node with its key
int LinkedList_deleteKey (struct Node** head, int id)
{
	struct Node* current = (struct Node*)*head;
	struct Node* last = NULL;

	while(current)
	{
		// compare each node with selected id
		if(current->student.ID == id)
		{
			if (last)// the first is not the selected
			{
				last->PNextNode = current->PNextNode;
			}
			else// 1st node  == id
			{
				*head = current->PNextNode;
			}
			free(current);
			return 1;
		}
		last = current ;
		current = (struct Node*)current->PNextNode ;
	}
	printf("student ID doesn't exist\n");
	return 1;
}

// Delete all nodes.
int LinkedList_DeleteAll (struct Node** head)
{
	struct Node* current = (struct Node*)*head;
	int count=0;
	if (*head == NULL)
	{
		printf("empty list\n");
		return 1;
	}
	else
	{
		while(current)
		{
			count++;
			struct Node* temp = current;
			current = current->PNextNode ;
			temp = NULL;
			free(temp);
		}
		current = NULL;
		free(current);
		*head = NULL;
		free(head);
	}
	printf("%d nodes deleted\n",count);
	return 1;
}

// The length of the linked list.
unsigned int LinkedList_length (struct Node* head)
{
	int i =0;
	if (head == NULL)
		return 0;

	struct Node* current_node = head;
	while(current_node)
	{
		i++;
		current_node = current_node->PNextNode;
	}
	return i;
}

// Another way to get the length of linked list recursive.
unsigned int LinkedList_lengthIterative (struct Node* head)
{
	if (head == NULL)
		return 0;
	return 1 + LinkedList_lengthIterative(head->PNextNode);
}

// Get data of node with key.
struct Sdata LinkedList_getKey (struct Node* head, int id)
{
	int i=0;
	struct Node* current = head;
	while(current)
	{
		// compare each node with selected id
		if(current->student.ID == id)
		{
			i++;
			return current->student;
		}
		current = (struct Node*)current->PNextNode ;
	}
	struct Sdata s;
	s.ID=-1;
	s.height=-1;
	s.name[0]='\0';
	return s;
}

// Get data of node with index.
struct Sdata LinkedList_getIndex (struct Node* head, unsigned int index)
{
	struct Sdata t;
	t.ID=-1;
	t.height=-1;
	t.name[0]='\0';
	if (head == NULL)
		return t;

	int i = 0;
	struct Node* current = head;

	while(current)
	{
		if ((index) == i)
		{
			return 	current->student;
		}
		current = current->PNextNode;
		i++;
	}
	return t;
}

// Print linked list data.
int LinkedList_Print (struct Node* head)
{
	struct Node* current = head;
	int count=0;
	if (head == NULL)
	{
		printf("empty list\n");
		return 0;
	}
	else
	{
		while(current)
		{
			printf("\nIndex number %d \n", count);
			printf("\t ID: %d \n", current->student.ID);
			printf("\t Name: %s \n", current->student.name);
			printf("\t height: %f \n", current->student.height);
			current = current->PNextNode;
			count++;
		}
	}
	return 1;
}

// Print data of node with key.
void LinkedList_PrintKey (struct Node* head, int id)
{
	struct Sdata s;
	s = LinkedList_getKey(head, id);
	if(s.ID == -1)
		printf("student ID doesn't exist\n");
	else
	{
		printf("====== The data of Key %d======\n",id);
		printf("ID: %d\n", s.ID);
		printf("Name: %s \n", s.name);
		printf("height: %f \n", s.height);
	}
}

// Print data at index.
void LinkedList_PrintIndex (struct Node* head, int index)
{
	struct Sdata s;
	s = LinkedList_getIndex(head, index);
	if(s.ID == -1)
		printf("student Index doesn't exist\n");
	else
	{
		printf("====== The data of Index %d======\n",index);
		printf("ID: %d\n", s.ID);
		printf("Name: %s \n", s.name);
		printf("height: %f \n", s.height);
	}
}

// Get nth node from end.
struct Sdata LinkedList_get_nth_fromEnd (struct Node* head, int nth)
{
	struct Sdata t;
	t.ID=-1;
	t.height=-1;
	t.name[0]='\0';
	if ((head == NULL) || (nth == 0))
		return t;

	struct Node* first = head;
	struct Node* second = head;
	int count;

	for(count=0; count != nth; count++)
	{
		second = second->PNextNode;
	}

	while(second)
	{
		second = second->PNextNode;
		first = first->PNextNode;
	}
	return first->student;
}

// Get middle node of list.
struct Sdata LinkedList_middle_node (struct Node* head)
{
	struct Sdata t;
	t.ID=-1;
	t.height=-1;
	t.name[0]='\0';
	if ((head == NULL) || (head->PNextNode == NULL))
		return t;

	struct Node* slow = head;
	struct Node* fast = head;

	if (head!=NULL)
	{
		while (fast != NULL && fast->PNextNode != NULL)
		{
			fast = fast->PNextNode->PNextNode;
			slow = slow->PNextNode;
		}
	}
	return slow->student;
}

// Detect loops in lists.
int LinkedList_detect_loop (struct Node* head)
{
	struct Node* slow = head;
	struct Node* fast = head;
	while (fast && slow && fast->PNextNode)
	{
		fast = fast->PNextNode->PNextNode;
		slow = slow->PNextNode;

		if (fast == slow)
		{
			return 1;
		}
	}
	return 0;
}

// Make list circular.
int LinkedList_make_circular(struct Node* head)
{
	struct Node* current = head;
	// only one node
	if (head->PNextNode == NULL || head == NULL)
	{
		return 0;
	}
	// more than 1 node
	while(current->PNextNode)
	{
		current = current->PNextNode ;
	}
	current->PNextNode = head;
	return 1;
}

// Print Struct Sdata.
void Sdata_Print(struct Sdata data)
{
	if(data.ID == -1)
		printf("student Index doesn't exist\n");
	else
	{
		printf("====== The data ======\n");
		printf("ID: %d\n", data.ID);
		printf("Name: %s \n", data.name);
		printf("height: %f \n", data.height);
	}
}

// Reverse list.
// 1. (0.prev, 1.current, 2.next )
// 2. (current-points-to-prev, prev=current, current=next, next-points-to-nexter )
// 3. (if current = null) (head-points-to-prev)
void reverse(struct Node** head)
{
	struct Node* prev = NULL;
	struct Node* current = *head;
	struct Node* next = NULL;
	while (current != NULL)
	{
		// Store next
		next = current->PNextNode;
		// Reverse current node's pointer
		current->PNextNode = prev;
		// Move pointers one position ahead.
		prev = current;
		current = next;
	}
	*head = prev;
}
