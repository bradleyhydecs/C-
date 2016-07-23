// bradley hyde
// bradleyhydecs@gmail.com
// z5063156@zmail.unsw.edu.au

// we can simply navigate the tree until we find the 
// first point in which our node value is not greater 
// than or less than both targets

node * lca(node * root, int v1,int v2)
{
    if (v1 < root->data && v2 < root->data)
        return lca(root->left, v1, v2);
    if (v1 > root->data && v2 > root->data)
        return lca(root->right, v1, v2);
    
    return root;   
}
