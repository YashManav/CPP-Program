#include <iostream>
using namespace std;
int const N = 1e3;

void heapify(int arr[],int len,int i){

    while(2*i <= len){
        int lc = 2*i;
        int rc = lc+1;
        int mc = lc;
        
        if(rc<=len and arr[rc]>arr[mc])
        mc = rc;

        if(arr[mc] <= arr[i])
        return;

        swap(arr[mc],arr[i]);
        i = mc;
    }
}

void remove(int arr[],int &len){

    swap(arr[1],arr[len]);
    len--;
    heapify(arr,len,1);
}

void heapsort(int arr[],int len){

    //heapify
    for(int i = len/2;i>0;i--){
        heapify(arr,len,i);
    }

    //deleting element until length become 0
    while(len){
       
       remove(arr,len);
       
    }
}

int main(){
    int arr[N] = {-1,60,10,80,50,5,20,70};
    int len = 7;
    heapsort(arr,len);

    for(int i = 1;i < len;i++)
    cout<<arr[i]<<" ";

    return 0;
}