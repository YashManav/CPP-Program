#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
  public:
  char data;
  vector<Node*> children;

  Node(char data){
    this->data = data;
  }
};

void preorder(Node* root){
    if(!root)
    return;

    cout<<root->data<<" ";
    for(Node* child: root->children)
    preorder(child);
}

void inorder(Node* root){

    if(!root)
    return;

    int l = root->children.size();
    for(int i = 0;i<l-1;i++){
        inorder(root->children[i]);
    }

    cout<<root->data<<" ";
    if(l-1 > 0)
    inorder(root->children[l-1]);
}

void postorder(Node* root){

    if(!root)
    return;
    
    for(Node* child: root->children)
    postorder(child);

    cout<<root->data<<" ";
}

void levelorder(Node* root){
    if(!root)
    return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int n  = q.size();
        while(n--){
            Node* node = q.front();
            q.pop();
            cout<<node->data<<" ";
            for(Node* child: node->children) 
            q.push(child);
        }
        cout<<endl;
    }
}

int main(){

    //generic tree
    //            A
    //    B      C      D     E
    // X  T  H  N K             Z
    Node* root = new Node('A');
    root->children.push_back(new Node('B'));
    root->children.push_back(new Node('C'));
    root->children.push_back(new Node('D'));
    root->children.push_back(new Node('E'));
    root->children[0]->children.push_back(new Node('X'));
    root->children[0]->children.push_back(new Node('T'));
    root->children[0]->children.push_back(new Node('H'));
    root->children[1]->children.push_back(new Node('N'));
    root->children[1]->children.push_back(new Node('K'));
    root->children[3]->children.push_back(new Node('Z'));

    //to print generic tree
    // cout<<root->data<<" ";
    // for(Node* child : root->children)
    // cout<<child->data<<" ";

    //preorder traversal
    preorder(root);
    cout<<endl;

    //inorder traversal
    inorder(root);
    cout<<endl;

    //postorder traversal
    postorder(root);
    cout<<endl;

    //level order traversal or breadth first search
    levelorder(root);
}