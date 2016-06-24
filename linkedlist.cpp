using namespace std;
#include <iostream>
#include <assert.h>

struct Node
{
	int data;
	struct Node *next;
};

// store the head of the list here for now
// list implementation is not important for practice
Node* L;


//
// print list, each item on new line
//
void printList(Node *head)
{
	cout << "List:" << endl;
	Node* curr = head;
	while (curr != NULL)
	{
		cout << curr->data << "  ";
		curr = curr->next;
	}
	cout << endl;
}

//
// create a new node
//
Node* createNode(int data)
{
	Node* n = (struct Node*) malloc(sizeof(struct Node));
	n->data = data;
	n->next = NULL;
	return n;
}

//
// insert a node at end of list
//
Node* InsertAtEnd(Node *head, int data)
{
	Node *temp = createNode(data);

	if (head == NULL)
	{
		return temp;
	}
	else
	{
		Node *curr = head;

		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}
	return head;
}

//
// creates a new list for testing functions
// list = [1 -> 2 -> 3 -> 4 -> 5]
//
Node* initializeList()
{
	Node *head = createNode(1);
	L = head;
	Node *two = createNode(2);
	Node *three = createNode(3);
	Node *four = createNode(4);
	Node *five = createNode(5);

	head->next = two;
	two->next = three;
	three->next = four;
	four->next = five;

	return head;
}

//
// reverses the list
//
Node* reverseList(Node* head)
{
	if (head->next == NULL)
		return head;

	Node* curr = head;
	Node* prev = NULL;
	Node* temp = NULL;

	while(curr != NULL)
	{
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}

	// new head is now in prev
	return prev;
}

//
// reverses the list
//
Node* reverseListRecursively(Node* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	Node* reverse = reverseListRecursively(head->next);
	head->next->next = head;
	head->next = NULL;

	return reverse;
}

//
// deletes node at given index
//
Node* deleteItemAtIndex(Node* head, int index)
{
	if (head == NULL || head->next == NULL)
		return NULL;

	int count = 0;
	Node* curr = head;
	Node* prev = head;

	while (curr != NULL)
	{
		if (count == index)
		{
			if (count == 0)
			{
				head = curr->next;
			}
			else 
			{
				prev->next = curr->next;
			}
			free(curr);
		}
		count++;
		prev = curr;
		curr = curr->next;
	}
	return head;

}

//
// insert node at front of list
//
void InsertAtFront(int data)
{
	Node* n = createNode(data);
	n->next = L;
	L = n;
}

//
// delete node at end of list
//
Node* DeleteAtEnd(Node* head)
{
	// list of size 1
	if (head->next == NULL)
	{
		free(head);
		return NULL;
	}

	// list of size > 1
	Node* curr = head;
	Node* prev;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}

	prev->next = NULL;
	free(curr);
	return head;
}

//
// delete node at the front of the list
//
Node* DeleteAtFront(Node* head)
{
	if (head->next == NULL)
	{
		free(head);
		return NULL;
	}
	else
	{
		L = head->next;
		free(head);
		return L;
	}
}

//
//
//
int main()
{
	// create a list
	L = initializeList();
	printList(L);

	// test insert at end
	InsertAtEnd(L, 8);
	InsertAtEnd(L, 9);
	printList(L);

	// test reverse
	L = reverseList(L);
	printList(L);

	L = reverseList(L);
	printList(L);

	// test insert at front
	InsertAtFront(0);
	InsertAtFront(-1);
	printList(L);

	// test delete at end
	L = DeleteAtEnd(L);
	L = DeleteAtEnd(L);
	printList(L);

	// test delete item at specific index
	L = deleteItemAtIndex(L, 0);
	L = deleteItemAtIndex(L, 5);
	L = deleteItemAtIndex(L, 2);
	printList(L);

	// test delete at front
	L = DeleteAtFront(L);
	L = DeleteAtFront(L);
	printList(L);

	return EXIT_SUCCESS;
}