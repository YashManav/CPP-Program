#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main() {
    vector<int> nums =  {1,1,0,1,1,1,0,1};
	 int m = 0,c = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                m = max(m,c);
                c = 0;
            }
            else
            c = c+1;

            m = max(m,c);
        }
        cout<<c;
}