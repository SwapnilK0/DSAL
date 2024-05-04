// C++ program for expression tree
#include <bits/stdc++.h>
#include<stack>
using namespace std;
class node {
public:
	char value;
	node* left;
	node* right;
	
	node(char c)
	{
		this->value = c;
		left = NULL;
		right = NULL;
	}
	node()
	{
		left = NULL;
		right = NULL;
	}
	
	
};

class expression_tree {
public:
	void inorder(node* x)
	{
		// cout<<"Tree in InOrder Traversal is: "<<endl;
		if (x == NULL)
			return;
		else {
			inorder(x->left);
			cout << x->value << " ";
			inorder(x->right);
		}
	}
};

int main()
{
	string s = "ABC*+D/";
	// If you wish take input from user:
	//cout << "Insert Postorder Expression: " << endl;
	//cin >> s;

	stack<node*> e;
	expression_tree a;
	node *op1, *op2, *newnode;
    
	int l = s.length();
	for (int i = 0; i < l; i++) {
		
		if (s[i] == '+' || s[i] == '-' || s[i] == '*'
			|| s[i] == '/' || s[i] == '^') {
			newnode = new node(s[i]);
			op1 = e.top();
            e.pop();
			op2 = e.top();
            e.pop();
			newnode->left = op2;
			newnode->right = op1;
			e.push(newnode);
		}
		else {
			newnode = new node(s[i]);
			e.push(newnode);
		}
	}
	cout << " The Inorder Traversal of Expression Tree: ";
	a.inorder(newnode);
	return 0;
}
