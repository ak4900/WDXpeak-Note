/*
经典的面试题目，遍历一遍数组，用变量maxsum保存遍历过程中的最大和， 用变量cursum保存遍历过程中的当前和。在遍历的过程中，我们只需要做3件事， 第一：如果当前和cursum小于等于0，说明前面的连续和不会对后面的连续和产生贡献， 要么使后面的连续和减少，要么不变。因此舍弃cursum，用当前的元素更新它。 第二：如果当前和cursum是大于0的，累加当前元素。第三：如果当前和cursum 大于最大和maxsum，则更新最大和maxsum。
*/

#include <iostream>
using namespace std;

bool g_Invalid = false;

int GetMaxSum(int a[], int n){
    if(a==NULL || n<=0){
        g_Invalid = true;
        return 0;
    }
    g_Invalid = false;
    
    int max_sum = 1<<31; // Min Int
    int cur_sum = 0;
    for(int i=0; i<n; ++i){
        if(cur_sum <= 0)
            cur_sum = a[i];
        else
            cur_sum += a[i];

        if(cur_sum > max_sum)
            max_sum = cur_sum;
    }

    return max_sum;
}
int main(){
    int a[] = {
        2, -8, 3, -2, 4, -10
    };
    int max_sum = GetMaxSum(a, 6);
    if(g_Invalid)
        cout<<"Invalid Input!"<<endl;
    else
        cout<<max_sum<<endl;
    return 0;
}