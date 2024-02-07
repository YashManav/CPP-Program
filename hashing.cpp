#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class Hashing
{
    vector<list<int>> hashtable;
    int buckets;

public:

    Hashing(int size){
        buckets = size;
        hashtable.resize(size);
    }

    int hashvalue(int key){
        return key%buckets;
    }

    void addelement(int key){
        int index = hashvalue(key);
        hashtable[index].push_back(key);
        return;
    }

    list<int> :: iterator search(int key){
        int idx = hashvalue(key);
        return find(hashtable[idx].begin(),hashtable[key].end(),key);
    }

    void deletekey(int key){
        int idx = hashvalue(key);
        if(search(key) != hashtable[idx].end()){
            hashtable[idx].erase(search(key));
            cout<<key<<" is deleted \n";
        }
        else {
            cout<<key<<" is not present \n";
        }
    }

};

int main(){
    Hashing ht1(5);
    ht1.addelement(45);
    ht1.addelement(34);
    ht1.addelement(98);
    ht1.deletekey(340);
    return 0;
}