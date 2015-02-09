/*
如果a[mid]不等于x，就要分情况讨论了。我们把旋转后的数组分为前半段和后半段， 两段分别都是有序的，且前半段的数都大于后半段的数。假如a[mid]落在前半段 (即a[mid]>=a[low])，这时如果x的值是位于a[low]和a[mid]之间， 则更新high = mid - 1；否则更新low = mid + 1。假如a[mid]落在后半段 (即a[mid]<a[low])，这时如果x的值是位于a[mid]和a[low]之间， 则更新low = mid + 1；否则更新high = mid - 1。
*/

#include <iostream>
using namespace std;

int search(int a[], int low, int high, int x){
    while(low <= high){
        int mid = low + (high - low)/2;
        if(a[mid] == x) return mid;
        if(a[mid] >= a[low]) {
            if(x<a[mid] && x>=a[low])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else {
            if(x>a[mid] && x<a[low])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int a[12] = {
        15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14
    };
    int b[19] = {
        2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2
    };
    cout<<search(a, 0, 11, 3)<<endl;
    return 0;
}