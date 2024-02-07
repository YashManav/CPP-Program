#include <iostream>
using namespace std;

class Node{
  public:
   int val;
   Node *next;

   Node(int data){
    val = data;
    next = NULL;
   }
};

class LinkedList{
public:
  Node* head;

  LinkedList(){
    head = NULL;
  }

  void addathead(int val){
  Node* new_node = new Node(val);
  new_node->next = head;
  head = new_node;
}

  void addatend(int val){
  
  Node* temp = head;
  Node* new_node = new Node(val);

  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = new_node;
}

  void add(int val,int pos){
  
  if(pos == 0){
    addathead(val);
    return;
  }

  Node* new_node = new Node(val);
  Node* temp = head;
  int cp = 0;
  while(cp < pos-1){
    temp = temp->next;
    cp++;
  }
  new_node->next = temp->next;
  temp->next = new_node;

}

  void update(int val,int pos){

  Node* temp = head;
  int i = 0;
  while(i != pos){
    temp = temp->next;
    i++;
  }
  temp->val = val;

}

  void deleteathead(){

  Node* temp = head;
  head = head->next;
  free(temp);
}

  void deleteatend(){
  
  Node* temp = head;
  while(temp->next->next){
    temp = temp->next;
  }
  Node* delnode = temp->next;
  temp->next = NULL;
  free(delnode);
}

  void Delete(int pos){
  
  if(pos){
    deleteathead();
    return;
  }
  int i = 0;
  Node* temp = head;
  while(i != pos-1){
    temp = temp->next;
    i++;
  }
  Node* deletion = temp->next;
  temp->next = temp->next->next;
  free(deletion);
}

  void print(){
  while(head != NULL){
    cout<<head->val<<"->";
    head = head->next;
  }
  cout<<"NULL"<<"\n";
}

};

int main(){
  
  LinkedList l1,l2;
  l1.addathead(1);
  l1.addatend(2);
  l1.addatend(3);
  l1.print();

  l2.addathead(11);
  l2.addatend(22);
  l2.addatend(33);
  l2.print();
  return 0;

}