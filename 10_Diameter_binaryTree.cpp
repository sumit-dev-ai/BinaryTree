#include<iostream>
#include<bits/stdc++.h>
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
int calcHeight(node* root)
{
    if (root==NULL)
    {
        return 0;
    }
    int lHeight=calcHeight(root->left);
    int rHeight=calcHeight(root->right);
    return max(lHeight,rHeight)+1;
    
}
int calcDiameterr(node* root)
{
    if (root==NULL)
    {
        return 0;
    }
    int lHeight=calcHeight(root->left);
    int rHeight=calcHeight(root->right);
    int currDiameter=lHeight+rHeight+1;

    int ldiameter=calcDiameterr(root->left);
    int rdiameter=calcDiameterr(root->right);
    return max(currDiameter,max(ldiameter,rdiameter));
    
}


int main()
{
    node* root= new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right= new node(5);
    root->right->left= new node(6);
    root->right->right= new node(7);
    cout<<calcDiameterr(root);
    
    
    return 0;
}