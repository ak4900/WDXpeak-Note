#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        for(int i1 = 0, i2 = 0; i1 < version1.size() || i2 < version2.size(); i1++, i2++){
            int num1 = 0;
            while(version1[i1] != '.' && i1 < version1.size())
                num1 = num1 * 10 + (version1[i1++] - '0');

            int num2 = 0;
            while(version2[i2] != '.' && i2 < version2.size())
                num2 = num2 * 10 + (version2[i2++] - '0');
            if(num1 > num2) return 1;
            if(num1 < num2) return -1;

            
        }
        return 0;
    }
};

int main(){
    Solution s;
    string s1 = "1.0.2";
    string s2 = "1.0.3";
    cout << s.compareVersion(s1, s2) << endl;
    return 0;
}
