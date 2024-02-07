#include <iostream>
#include <queue>
using namespace std;

class Node
{
 public:
 int data;
 Node* left;
 Node* right;

 Node(int val)
 {
    data = val;
    left = NULL;
    right = NULL;
 }
};

void preorder(Node* rootNode){

    if(rootNode == NULL) 
    {
      return;
    }
    cout<<rootNode->data<<" ";
    preorder(rootNode->left);
    preorder(rootNode->right);
}

void inorder(Node* rootNode){
    if(rootNode == NULL) 
    {
      return;
    }
    
    inorder(rootNode->left);
    cout<<rootNode->data<<" ";
    inorder(rootNode->right);
}

void postorder(Node* rootNode){
    if(rootNode == NULL) 
    {
      return;
    }
    
    postorder(rootNode->left);
    postorder(rootNode->right);
    cout<<rootNode->data<<" ";
}

void levelorder(Node* rootNode){
    if(rootNode == NULL)
    return;

    queue<Node*> q;
    q.push(rootNode);
    while(!q.empty())
    {
        int n = q.size();
        while(n--){
            Node* cn = q.front();
            q.pop();
            if(cn->left)
            q.push(cn->left);
            if(cn->right)
            q.push(cn->right);
            cout<<cn->data<<"   ";
        }
        cout<<endl;
    }
}

int main(){

    //s=%)
    Node* root = new Node(34);
    root->left = new Node(92);
    root->right = new Node(2);
    root->left->left = new Node(70);
    root->left->right = new Node(20);
    root->right->right = new Node(10);
    levelorder(root);
}