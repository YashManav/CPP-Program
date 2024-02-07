#include <iostream>
#include <list>
using namespace std;

struct Stack{
    private:
    int size;
    int top;
    int* arr;

    public:
    Stack(int s){
        top = -1;
        arr = new int[s];
        size = s;
    }

    void push(int val){
        if(top+1 == size){
            cout<<"Overflow";
            return;
        }
        else{
            top++;
            arr[top] = val;
        }
    }

    int pop(){
        if(top == -1){
            cout<<"underFlow";
            return -1;
        }
        else{
            return arr[top];
            top--;
        }
    }

    int isempty(){
        if(top == -1)
        return 1;

        return 0;
    }

    void display(){
        if(isempty())
        cout<<"Stack is empty";

        else{
            int tmptop = top;
            while(tmptop>=0){
                cout<<arr[tmptop];
                tmptop--;
            }
        }
    }
};

int main(){
   Stack s(5);
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   s.push(5);
   s.push(6);
   s.display();
   Stack s2(5);
   s2.push(234);
   s2.push(23);
   s2.display();
   s2.pop();
   s2.display();
}