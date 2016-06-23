using namespace std;
#include <iostream>
#include <assert.h>

struct Node
{
	int data;
	struct Node *next;
};
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
// insert a node at end of list
//
Node* Insert(Node *head, int data)
{
	Node *temp = new Node();
	temp->data = data;

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
void initializeList()
{
	Node *head = new Node();
	head->data = 1;
	L = head;

	Node *two = new Node();
	two->data = 2;

	Node *three = new Node();
	three->data = 3;

	Node *four = new Node();
	four->data = 4;

	Node *five = new Node();
	five->data = 5;

	head->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
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

int main()
{
	initializeList();
	printList(L);

	//L = reverseList(L);
	L = reverseListRecursively(L);
	printList(L);

	L = deleteItemAtIndex(L, 0);
	assert(L->data == 4);
	assert(L->next->data == 3);
	assert(L->next->next->data == 2);
	assert(L->next->next->next->data == 1);
	assert(L->next->next->next->next == NULL);
	// printList(L);

	L = deleteItemAtIndex(L, 2);
	assert(L->data == 4);
	assert(L->next->data == 3);
	assert(L->next->next->data == 1);
	assert(L->next->next->next == NULL);
	// printList(L);

	L = deleteItemAtIndex(L, 2);
	assert(L->data == 4);
	assert(L->next->data == 3);
	assert(L->next->next == NULL);
	// printList(L);

	L = deleteItemAtIndex(L, 0);
	assert(L->data == 3);
	assert(L->next == NULL);
	// printList(L);

	L = deleteItemAtIndex(L, 0);
	assert(L == NULL);
	// printList(L);

	return EXIT_SUCCESS;
}