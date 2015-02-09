#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string alphabet = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
        stack<char> result;
        string rtn = "";

        int num, rest = n;

        if (rest <= 26){
            num = rest % 26;
            result.push(alphabet[num]);
        }

        while(rest > 26){
            num = rest % 26;
            rest = (rest-num) / 26;
            result.push(alphabet[num]);

            if (num == 0)
                rest--;

            if (rest <= 26){
                num = rest % 26;
                result.push(alphabet[num]);
            }
        }
        
        while(!result.empty()){
            rtn += result.top();
            result.pop();
        }

        return rtn;
    }
};

int main(){
    Solution s;
    cout << s.convertToTitle(26) << endl;
}