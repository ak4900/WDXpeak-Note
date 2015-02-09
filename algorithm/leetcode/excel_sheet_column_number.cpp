#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int length = s.length();
        int i, j, result = 0;
        for (j=0, i=length-1; i >= 0; i--, j++){
            result += (s[i]-'A' + 1)*pow(26,j);
        }

        return result;
    }
};

int main()
{
    Solution s;
    string test = "AAA";
    cout << s.titleToNumber(test) << endl;
}