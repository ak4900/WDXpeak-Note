
/*
整数部分通过不断地对2取余然后除以2来得到其二进制表示， 或是不断地和1按位与然后除以2得到其二进制表示。 小数部分则通过不断地乘以2然后与1比较来得到其二进制表示。 小数部分转化为二进制，通过乘以2然后与1比较，大于等于1则该位为1，并且该值减去1； 否则该位为0。不断地通过这种操作最终能使该小数部分的值变为0的，即可精确表示。 否则将无法用有限的位数来表示这个小数部分。我们可以设定一个长度，比如说32， 在32位之内还无法精确地表示这个小数部分的，我们就认为它无法精确表示了。

*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string print_binary(string val){
    int pos = val.find('.', 0);
    int intpart = atoi(val.substr(0, pos).c_str());
    double decpart = atof(val.substr(pos, val.length()-pos).c_str());
    string intstr = "", decstr = "";
    while(intpart > 0){
        if(intpart&1) intstr = "1" + intstr;
        else intstr = "0" + intstr;
        intpart >>= 1;
    }
    while(decpart > 0){
        if(decstr.length() > 32) return "ERROR";
        decpart *= 2;
        if(decpart >= 1){
            decstr += "1";
            decpart -= 1;
        }
        else
            decstr += "0";
    }
    return intstr + "." + decstr;
}
int main(){
    string val = "19.25";
    cout<<print_binary(val)<<endl;
    return 0;
}