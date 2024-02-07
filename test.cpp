#include<iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    vector<vector<int>> m = {{0,2},{0,1},{2,1}};
     vector<vector<char>> v(3,vector<char>(3,'.'));
        char c = 'X'; 
        for(vector<int> e : m)
        {
            v[e[0]][e[1]] = c;
            c = '0';
        }
    for(vector<char> ch : v)
    {
    for(char t : ch)
    cout<<t<< " ";
    cout<<endl;
}
        
}