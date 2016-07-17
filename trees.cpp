// bradley hyde
// bradleyhydecs@gmail.com
// z5063156@zmail.unsw.edu.au

#include <iostream>

struct node
{
    int data;
    node* left;
    node* right;
};

void preOrder(node *root) 
{
    if (root == NULL)
        return;
    
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int height(node * root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    
    return (1 + max(height(root->left), height(root->right)));
}


#include <stack>
void top_view(node * root)
{
    if (root == NULL)
    {
        return;   
    }
    else if (root->left == NULL)
    {
        cout << root->data << " ";    
    }
    else
    {
        node* curr = root;
        std::stack<int> s;

        while (curr)
        {
            s.push(curr->data);
            curr = curr->left;
        }

        while (!s.empty())
        {
            std::cout << s.top() << " ";
            s.pop();
        }
    }
    
    if (root->right != NULL)
    {
        node* curr = root->right;
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

#include <queue>
void LevelOrder(node * root)
{
    node* curr = root;
    queue<node*> q;
      
    q.push(curr);
    
    while (!q.empty() )
    {
        curr = q.front();
        cout << curr->data << " ";
        
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL) 
            q.push(curr->right);
        
        q.pop();
    }
}


int main()
{
	// stuff

    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while (!s.empty())
    {
    	std::cout << s.top() << " ";
    	s.pop();
    }

	return 0;
}
