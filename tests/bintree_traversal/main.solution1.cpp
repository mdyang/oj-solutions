#include<iostream>
#include<vector>

using namespace std;

const int LEFT = 1;
const int CENTER = 2;
const int RIGHT = 4;

typedef struct _node
{
	int data;
	struct _node* left;
	struct _node* right;
} node;

typedef struct _record
{
	node* node;
	int status;
} record;

node* create_node(int data)
{
	node* n = new node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

record create_record(node* node)
{
	record r;
	r.node = node;
	r.status = 0;
	return r;
}

/*
        _______7______
       /              \
    __10__          ___2
   /      \        /
   4       3      _8
            \    /
             1  11
*/

void preorder_recursive(node* root)
{
	if (root == NULL) return;
	cout<<root->data<<' ';
	preorder_recursive(root->left);
	preorder_recursive(root->right);
}

void inorder_recursive(node* root)
{
	if (root == NULL) return;
	inorder_recursive(root->left);
	cout<<root->data<<' ';
	inorder_recursive(root->right);
}

void postorder_recursive(node* root)
{
	if (root == NULL) return;
	postorder_recursive(root->left);
	postorder_recursive(root->right);
	cout<<root->data<<' ';
}

void preorder_nonrecursive(node* root)
{
	vector<record> stack;
	stack.push_back(create_record(root));
	while (stack.size() > 0)
	{
		record r = stack.back();
		stack.pop_back();
		if (r.node == NULL) continue;
		if (!(r.status & CENTER))
		{
			cout<<r.node->data<<' ';
			r.status |= CENTER;
			stack.push_back(r);
		}
		else if (!(r.status & LEFT))
		{
			r.status |= LEFT;
			stack.push_back(r);
			stack.push_back(create_record(r.node->left));
		}
		else if (!(r.status & RIGHT))
		{
			r.status |= RIGHT;
			stack.push_back(r);
			stack.push_back(create_record(r.node->right));
		}
	}
}

void inorder_nonrecursive(node* root)
{
	vector<record> stack;
	stack.push_back(create_record(root));
	while (stack.size() > 0)
	{
		record r = stack.back();
		stack.pop_back();
		if (r.node == NULL) continue;
		if (!(r.status & LEFT))
		{
			r.status |= LEFT;
			stack.push_back(r);
			stack.push_back(create_record(r.node->left));
		}
		else if (!(r.status & CENTER))
		{
			cout<<r.node->data<<' ';
			r.status |= CENTER;
			stack.push_back(r);
		}
		else if (!(r.status & RIGHT))
		{
			r.status |= RIGHT;
			stack.push_back(r);
			stack.push_back(create_record(r.node->right));
		}
	}
}

void postorder_nonrecursive(node* root)
{
	vector<record> stack;
	stack.push_back(create_record(root));
	while (stack.size() > 0)
	{
		record r = stack.back();
		stack.pop_back();
		if (r.node == NULL) continue;
		if (!(r.status & LEFT))
		{
			r.status |= LEFT;
			stack.push_back(r);
			stack.push_back(create_record(r.node->left));			
		}
		else if (!(r.status & RIGHT))
		{
			r.status |= RIGHT;
			stack.push_back(r);
			stack.push_back(create_record(r.node->right));
		}
		else if (!(r.status & CENTER))
		{
			cout<<r.node->data<<' ';
			r.status |= CENTER;
			stack.push_back(r);
		}
	}
}

int main()
{
	node* root = create_node(7);
	root->left = create_node(10);
	root->left->left = create_node(4);
	root->left->right = create_node(3);
	root->left->right->right = create_node(1);
	root->right = create_node(2);
	root->right->left = create_node(8);
	root->right->left->left = create_node(11);
	
	preorder_recursive(root); cout<<endl;
	preorder_nonrecursive(root); cout<<endl;
	
	inorder_recursive(root); cout<<endl;
	inorder_nonrecursive(root); cout<<endl;
	
	postorder_recursive(root); cout<<endl;
	postorder_nonrecursive(root); cout<<endl;
	
	return 0;
}
