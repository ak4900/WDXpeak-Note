#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
         int nTimes = 0;
         int candidate = 0;
         for(int i = 0; i < num.size(); i ++){
            if(nTimes == 0){
                candidate = num[i];
                nTimes = 1;
            } else {
                if(candidate == num[i])
                    nTimes ++;
                else
                    nTimes --;
            }
         }
         return candidate;
    }
};

int main(){
    Solution s;
    int n1[] = {1, 2, 3, 2, 4, 2, 5, 2};
    int n2[] = {2, 2, 2, 2, 4, 5, 6};
    vector<int> v(n1, n1+8);

    cout << s.majorityElement(v) << endl;
}