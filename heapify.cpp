#include <iostream>
using namespace std;
int const N = 1e3;

void heapify(int arr[],int &len,int i){

    while(2*i <= len){
        int lc = 2*i;
        int rc = lc+1;
        int mc = lc;
        
        if(rc<=len and arr[rc]<arr[mc])
        mc = rc;

        if(arr[mc] >= arr[i])
        return;

        swap(arr[mc],arr[i]);
        i = mc;
    }
}

int main(){
    //heapify -> to arrange node in either max heap or min heap 
    int minheap[N] = {-1,60,10,80,50,5,20,70};
    int len = 7;
    for(int i = len/2; i > 0; i--){
        heapify(minheap,len,i);
    }

    for(int i = 1;i <= len;i++)
    cout<<minheap[i]<<" ";
}