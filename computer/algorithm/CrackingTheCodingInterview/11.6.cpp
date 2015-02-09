/*
这个矩阵是有序的，因此我们要利用这一点，当矩阵中元素和要查找的元素对比后， 如果相等，我们返回下标；如果不等，我们就排除掉一些元素，而不仅仅是对比的元素。 我们从矩阵的四个角的元素入手看看，有什么特点。左上角是最小的， 因为矩阵向右是递增的，向下也是递增的。同理，右下角是最大的。让我们来看看右上角， 设要查找的元素为x，比如x比右上角元素5大，那么它也会比第一行的其它元素都大。 因此可以去掉第一行；如果它比右上角元素小，那么它也会比最后一列的元素都小， 因此可以去掉最后一列；然后这样不断地比下去，只需要O(m+n)的时间就查找完。 对于左下角的元素，也有一样的特点。就不再分析了。
*/

#include <iostream>
#include <cstdio>
using namespace std;

int d[20][20];
int search(int m, int n, int x){
    int r = 0, c = n-1;
    while(r<m && c>=0){
        if(d[r][c] == x) return (r * n + c);
        else if(d[r][c] < x) ++r;
        else --c;
    }
    return -1;
}
int main(){
    freopen("9.6.in", "r", stdin);
    int m, n;
    cin>>m>>n;
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            cin>>d[i][j];

    int k = search(m, n, 13);
    if(k == -1) cout<<"not found"<<endl;
    else cout<<"position: "<<k/n<<" "<<k%n<<endl;
    fclose(stdin);
    return 0;
}