//linked lists
//ms
//15-07-2019

#include <stdio.h>
#include <stdlib.h>

//creating the structure to make nodes
typedef struct node {
	int data;
	struct node *next; //pointer to the address of the next node
} *node;

//logic that checks the nodes and updates the info
//if the first element is empty, the new node is inserted as head
//if the element is bigger than the last, it's the tail
//if it's greater than head and less than tail, verifies where it's the pos
//at the body 
void insert_node(node **head, node **tail, node *newNode)
{
	node *temp; //temporary node pointer

	// --------- first element insertion -------
	if(head == NULL)
	{
		head = newNode;
		tail = newNode;
	} else {
		// ----------- HEAD INSERTION ----------
		if(newNode->data <= (*head)->data)
		{
			newNode->next = *head;
			*head = newNode;
		}
		else {
			// ------- TAIL INSERTION ----------
			if(newNode->data >= (*tail)->data)
			{
				(*tail)->next = newNode;
				(*tail) = (*tail)->next;
			} 
			else {
			// ------ BODY INSERTION ----------
				for(temp = *head; temp->next->data < newNode->data; temp = temp->next)
				{
					newNode->next = temp->next;
					temp->next = newNode;
				}
			}
		}
	}
}

// ----------- create a node -------------------
// allocates memmory
//if the memory was allocated, creates the node, else doesn't
node *create_node (int value) {

	node *new = (node*)malloc(sizeof(node));
	if(new != NULL) 
	{
		new->data = value;
		new->next = NULL;
	}
	return new;
}

// ----------- counter of nodes ----------------
int nodeCounter(node *list)
{
	node *temp = NULL;
	int total = 0;

	for(temp = list, total = 0; temp != NULL; temp = temp->next)
	{
		total++;
	}
}

//------------ node remover --------------------
int remove_node (node **head, node **tail, int pos)
{
	node *temp = NULL;
	int temp_pos = 0;

	//-------- if the list is empty ------------
	if(*head == NULL) { return -1; } 
	else 
	{
		// ----- the position is invalid ------
		if (pos < 1 || pos > count(*head)) { return - 2;}
		else
		{
			// --- removing if the element is alone -----
			if(count(*head) == 1) 
			{
				*head = NULL;
				*tail = NULL;
			} 
			else 
			{
				//------ the head is being removed --------
				if(pos == 1)
				{
					*head = (*head)->next;
				}
				else
				{
					if(pos == count(*head))
					{
						//------ tail removal -------------
						temp = *head;
						for(temp_pos = 1; temp_pos < pos - 1; temp_pos++)
						{
							temp = temp->next;
						}
						temp->next;
					}
					//------------ body removal--------------
					else
					{
						temp = *head;
						for(temp_pos = 1; temp_pos < pos - 1; temp_pos++)
						{
							temp = temp->next;
						}
						temp->next = temp->next->next;
					}
				}
			}
		}
		return 1;
	}
}

//show list 
void show_list(node *list)
{
	node *temp = NULL;
	for(temp = list; list != NULL; list = list->next)
	{
		printf("\n%d", temp->data);
	}
}

