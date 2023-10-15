// build tree from preorder and inorder
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};
int Search(int inOrder[],int start,int end,int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inOrder[i]==curr)
        {
            return i;
        }
        
    }
    return -1;
}
Node* buildTree(int inOrder[],int postOrder[],int start,int end)
{
    static int idx=4;
    if (start>end)
    {
        return NULL;
    }
    
    int curr=postOrder[idx];
    idx--;
    
    Node* node = new Node(curr);
    if (start==end)
    {
        return node;
    }
    int pos=Search(inOrder,start,end,curr);
    node->right=buildTree(inOrder,postOrder,pos+1,end);
    node->left=buildTree(inOrder,postOrder,start,pos-1);
    
    return node;



}
void inorderPrint(Node* root)
{
    if (root==NULL)
    {
        return;
    }
    if (root->left!=NULL)
    {
    inorderPrint(root->left);
    }
    cout<<root->data<<" ";

    if (root->right!=NULL)
    {
    inorderPrint(root->right);  
    }
    
}
int main()
{
    int postOrder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};
    Node* root=buildTree(inorder,postOrder,0,4);
    inorderPrint(root);

    return 0;
}