#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};
void preorder(node* root)
{
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    if (root->left!=NULL)
    {
    preorder(root->left);
    }
    if (root->right!=NULL)
    {
    preorder(root->right);  
    }
}
void postorder(node* root)
{
    if (root==NULL)
    {
        return;
    }
    if (root->left!=NULL)
    {
    preorder(root->left);
    }
    if (root->right!=NULL)
    {
    preorder(root->right);  
    }
    cout<<root->data<<" ";
}
void inorder(node* root)
{
    if (root==NULL)
    {
        return;
    }
    if (root->left!=NULL)
    {
    inorder(root->left);
    }
    cout<<root->data<<" ";

    if (root->right!=NULL)
    {
    inorder(root->right);  
    }
    
}

int main()
{
    node* root= new node(1);
    root->left= new node(2);
    root->right= new node(3);
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    
    return 0;
}