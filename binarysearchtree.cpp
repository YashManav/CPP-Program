#include <iostream>
using namespace std;

class Node
{
    public:
    int val;
    Node* right;
    Node* left;

    Node(int v){
        val = v;
        right = NULL;
        left = NULL;
    }
};

class BST
{
    public:
    Node* root;
    
    BST()
    {
        root = NULL;
    }
};

void addbst(Node* &root,int val){
    Node* newnode = new Node(val);
    if(!root)
    {
        root = newnode;
        return;
    }
    Node* cnode = root;
    while(true){
        if(cnode->val > val){
            if(cnode->left == NULL){
                cnode->left = newnode;
                return;
            }
            cnode = cnode->left;
        }
        else
        {
            if(cnode->right == NULL)
            {
                cnode->right = newnode;
                return;
            }
            cnode = cnode->right;
        }
    }
}

Node* addrec(Node* root, int val){
    if(!root){
        Node* newnode  = new Node(val);
        return newnode;
    }

    if(root->val > val){
        root->left = addrec(root->left,val);
    }
    else
    {
        if(root->val < val)
        root->right  = addrec(root->right,val);
    }

    return root;
    
}

Node* largestnode(Node* root){
    Node* cnode = root;
    while(cnode and cnode->right){
        cnode = cnode->right;
    }
    return cnode;
}

Node* deletenode(Node* root,int val){
    if(!root)
    return NULL;

    if(root->val > val)
    root->left = deletenode(root->left,val);

    else if(root->val < val)
    root->right = deletenode(root->right,val);

    else
    {
        if(!root->left and !root->right){
            free(root);
            return NULL;
        }
        else if (!root->left)
        {
            Node* tmp = root->right;
            free(root);
            return tmp;
        }
        else if (!root->right)
        {
            Node* tmp = root->left;
            free(root);
            return tmp;
        }
        else{
            Node* justsmallernode = largestnode(root->left);
            root->val = justsmallernode->val;
            root->left = deletenode(root->left,justsmallernode->val);
        }
        
    }
    return root;
}

void inorder(Node* rootNode){
    if(rootNode == NULL) 
    {
      return;
    }
    
    inorder(rootNode->left);
    cout<<rootNode->val<<" ";
    inorder(rootNode->right);
}

int main(){
    BST b1;
    b1.root = addrec(b1.root,3);
    b1.root = addrec(b1.root,1);
    b1.root = addrec(b1.root,4);
    b1.root = addrec(b1.root,6);
    b1.root = addrec(b1.root,2);
    inorder(b1.root);
    cout<<endl;
    b1.root = deletenode(b1.root,4);
    inorder(b1.root);
    return 0;
}