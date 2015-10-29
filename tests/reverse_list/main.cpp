#include<iostream>

using namespace std;

typedef struct _node
{
	int data;
	struct _node* next;
} node;

node* reverse(node* head);
void print(node* head);

int main()
{
	int c;
	cin>>c;
	while (c--)
	{
		int n;
		cin>>n;
		node* previous = NULL;
		node* head = NULL;
		while (n--)
		{
			node* current = new node;
			if (head == NULL)
				head = current;
			if (previous != NULL)
				previous->next = current;
			cin>>(current->data);
			current->next = NULL;
			previous = current;
		}
		print(reverse(head));
	}

	return 0;
}

node* reverse(node* head)
{
	if (head == NULL) return NULL;
	
	// this sequence is important!
	node* previous = head;
	node* next = previous->next;
	head->next = NULL;
	node* temp;
	while (next != NULL)
	{
		// this sequence is important!
		temp = next->next;
		next->next = previous;
		previous = next;
		next = temp;
	}
	
	return previous;
}

void print(node* head)
{
	if (head == NULL) return;
	while (head != NULL) 
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	
	cout<<endl;
}