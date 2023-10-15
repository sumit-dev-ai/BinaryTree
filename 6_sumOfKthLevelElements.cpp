        //   1
        // /   \                Sum of k node 
    //    2     3
    //  /  \   /  \
    // 4    5 6    7                sumOfKthElement(root,2)   ==    4+5+6+7=22    

#include<iostream>
#include<queue>
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
int SumOFKthLevel(Node* root,int k)
{
    int sum=0;
    int lvl=0;
    if (root==NULL)
    {
        return -1;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node * node=q.front();
        q.pop();
        if(node!=NULL)
        {
            if (lvl==k)
            {
                sum+=node->data;
            }
            
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
            
        }
        else if (!q.empty())
        {
            q.push(NULL);
            lvl++;
        }
        
    }
    return sum;
    
    
}
int main()
{
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    cout<<SumOFKthLevel(root,2);
    
    
    return 0;
}

