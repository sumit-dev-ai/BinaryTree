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
Node* buildTree(int inOrder[],int preOrder[],int start,int end)
{
    static int idx=0;
    if (start>end)
    {
        return NULL;
    }
    
    int curr=preOrder[idx];
    idx++;
    
    Node* node = new Node(curr);
    if (start==end)
    {
        return node;
    }
    int pos=Search(inOrder,start,end,curr);
    node->left=buildTree(inOrder,preOrder,start,pos-1);
    node->right=buildTree(inOrder,preOrder,pos+1,end);
    
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
    int preOrder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    Node* root=buildTree(inorder,preOrder,0,4);
    inorderPrint(root);

    return 0;
}