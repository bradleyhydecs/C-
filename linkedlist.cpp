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
Node* L = NULL;

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
Node* insertAtEnd(Node *head, int data)
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
Node* initializeList(int num1, int num2, int num3, int num4, int num5)
{
	Node *head = createNode(num1);
	Node *two = createNode(num2);
	Node *three = createNode(num3);
	Node *four = createNode(num4);
	Node *five = createNode(num5);

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
void insertAtFront(Node* head, int data)
{
	Node* n = createNode(data);
	n->next = head;
	L = n;
}

//
// delete node at end of list
//
Node* deleteAtEnd(Node* head)
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
Node* deleteAtFront(Node* head)
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
// removes duplicates from list
// @precondition: the list is sorted
//
Node* deleteDuplicates(Node* head)
{
	if (head->next == NULL)
	{
		return head;
	}

	Node* curr = head;
	Node* temp;

	while(curr->next != NULL)
	{
		if (curr->data == curr->next->data)
		{
			temp = curr->next;
			curr->next = curr->next->next;
			free(temp);
		}
		else
		{
			curr = curr->next;
		}
	}
	return head;
}

//
// insert item at specific index
//
void insertItemAtIndex(Node* head, int data, int index)
{
	Node* n = createNode(data);
	// insert at front
	if (index == 0)
	{
		n->next = head;
		L = n;
	}
	else
	{
		int currIndex = 0;
		Node* curr = head;
		Node* prev = NULL;

		while (curr != NULL)
		{
			if (currIndex == index)
			{
				prev->next = n;
				n->next = curr;
			}

			currIndex++;
			prev = curr;
			curr = curr->next;
		}
	}
}

//
// merge two sorted lists
//
Node* mergeLists(Node* a, Node* b) {
    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    }

    if (a->data < b->data) {
        a->next = mergeLists(a->next, b);
        return a;
    } else {
        b->next = mergeLists(a, b->next);
        return b;
    }
}

//
//
//
int main()
{
	// create a list
	L = initializeList(1,2,3,4,5);
	printList(L);

	// test insert at end
	insertAtEnd(L, 8);
	insertAtEnd(L, 9);
	printList(L);

	// test reverse
	L = reverseList(L);
	printList(L);

	L = reverseList(L);
	printList(L);

	// test insert at front
	insertAtFront(L, 0);
	insertAtFront(L, -1);
	printList(L);

	// test delete at end
	L = deleteAtEnd(L);
	L = deleteAtEnd(L);
	printList(L);

	// test delete item at specific index
	L = deleteItemAtIndex(L, 0);
	L = deleteItemAtIndex(L, 5);
	L = deleteItemAtIndex(L, 2);
	printList(L);

	// test delete at front
	L = deleteAtFront(L);
	L = deleteAtFront(L);
	printList(L);

	// test insert at specific index
	insertItemAtIndex(L,-1,0);
	cout << "inserting at index 0 ";printList(L);

	insertItemAtIndex(L,-1,0);
	cout << "inserting at index 0 ";printList(L);

	insertItemAtIndex(L,-2,2);
	cout << "inserting at index 2 ";printList(L);

	insertItemAtIndex(L,-2,4);
	cout << "inserting at index 4 ";printList(L);
	
	L = initializeList(1,2,3,4,5);
	insertAtFront(L, 1);
	L = deleteAtEnd(L);
	L = deleteAtEnd(L);
	insertAtEnd(L, 3);
	insertAtEnd(L, 4);
	insertAtEnd(L, 5);
	insertAtEnd(L, 5);
	printList(L);

	// test delete duplicates from sorted list
	L = deleteDuplicates(L);
	printList(L);

	L = initializeList(5,20,30,40,50);
	printList(L);	
	Node* L2 = initializeList(10,42,43,55,88);
	insertAtEnd(L2, 96);
	insertAtEnd(L2, 99);
	printList(L2);	

	L = mergeLists(L, L2);
	printList(L);	

	return EXIT_SUCCESS;
}