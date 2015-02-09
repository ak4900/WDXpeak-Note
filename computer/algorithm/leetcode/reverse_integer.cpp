#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool isPositive = true;
        if(x == INT_MIN) return 0;
        if(x < 0){isPositive = false; x *= -1;}

        long long res = 0;//为了防止溢出，用long long
        while(x)
        {
            res = res*10 + x%10;
            x /= 10;
        }
        if(res > INT_MAX)return 0;
        if(!isPositive)return res*-1;
        else return res;
    }
};

int main(){
    Solution s;
    int a = 1;
    //cout << INT_MAX << endl;
    cout << s.reverse(a) << endl;
    return 0;
}