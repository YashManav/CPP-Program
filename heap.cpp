#include <iostream>
using namespace std;
int const N = 1e3;

void addatminheap(int minheap[], int &len,int value)
{
    len++;
    minheap[len] = value;
    
    int i = len;
    while(i/2 > 0 and minheap[i]<minheap[i/2])
    {
        swap(minheap[i],minheap[i/2]);
        i = i/2;
    }
}

void addatmaxheap(int maxheap[], int &len,int value)
{
    len++;
    maxheap[len] = value;
    
    int i = len;
    while(i != 1 and maxheap[i] > maxheap[i/2])
    {
        swap(maxheap[i],maxheap[i/2]);
        i = i/2;
    }
}

void deleteminheap(int minheap[],int &len){

    minheap[1] = minheap[len];
    len--;
    int i = 1;
    while(2*i <= len){
        int lc = 2*i;
        int rc = 2*i+1;

        if(minheap[min(minheap[lc],minheap[rc])==minheap[lc]?lc:rc] >= minheap[i])
        return;

        swap(minheap[i],minheap[min(minheap[lc],minheap[rc])==minheap[lc]?lc:rc]);
        i = min(minheap[lc],minheap[rc])==minheap[lc]?lc:rc;
    }
}

void deletemaxheap(int maxheap[],int &len){

    maxheap[1] = maxheap[len];
    len--;
    int i = 1;
    while(2*i <= len){
        int lc = 2*i;
        int rc = 2*i+1;

        if(maxheap[max(maxheap[lc],maxheap[rc])==maxheap[lc]?lc:rc] <= maxheap[i])
        return;

        swap(maxheap[i],maxheap[max(maxheap[lc],maxheap[rc])==maxheap[lc]?lc:rc]);
        i = max(maxheap[lc],maxheap[rc])==maxheap[lc]?lc:rc;
    }
}

int main(){
    //min heap -> when value of child node is greater than value of parent node
    int minheap[N] = {-1,10,20,30,40,50};
    int minlen = 5;
    addatminheap(minheap,minlen,5);
    deleteminheap(minheap,minlen);
    
    for(int i = 1;i <= minlen;i++){
        cout<<minheap[i]<<" ";
    }
    cout<<endl;
    
    //max heap -> when value of parent node is greater than value of child node
    int maxheap[N] = {-1,70,50,40,30,20,10,5};
    int maxlen = 7;
    addatmaxheap(maxheap,maxlen,100);
    deletemaxheap(maxheap,maxlen);
    for(int i = 1;i<=maxlen;i++){
        cout<<maxheap[i]<<" ";
    }
    
}