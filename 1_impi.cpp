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

int main()
{
    node* root= new node(1);
    root->left= new node(2);
    root->right= new node(3);
    cout<<root->data<<" ";
    cout<<root->left->data<<" ";
    cout<<root->right->data<<" ";
    
    return 0;
}