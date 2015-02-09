/*
字符串数组已经是有序的了，所以，还是可以利用二分查找来找到指定的字符串。 当然了，由于数组中有空字符串，因此还要加些额外的处理，否则无法对比大小。 我们可以这样来处理，如果要对比的那个元素为空字符串，就一直向右移动， 直到字符串不为空或是位置已经超出了high下标。如果位置已经超出high下标， 就在[low, mid-1]这一段查找；如果没有超出high下标，那就和要查找的x进行对比。 相等时返回下标，不等时再根据比较出的大小决定到哪一半去查找。
*/

#include <iostream>
using namespace std;

int search(string s[], int low, int high, string x){
    if(x == "") return -1; 
    while(low <= high){
        int mid = (low+high)>>1;
        int t = mid;
        while(s[t] == "" && t <= high) ++t;
        if(t > high) high = mid - 1;
        else{
            if(s[t] == x) return t;
            else if(s[t] < x) low = t + 1;
            else high = mid - 1; //or t-1
        }
    }
    return -1;
}
int main(){
    string s[13] = {
        "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""
    };
    cout<<search(s, 0, 12, "ball")<<endl;
    return 0;
}