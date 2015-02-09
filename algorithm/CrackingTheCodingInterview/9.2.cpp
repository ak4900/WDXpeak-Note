/*
其中二维数组g表示的是M*N的矩阵，元素为1表示该位置可以走，为0表示该位置不可走。 这个只能得到其中一条可行路径，但题目是要求我们找到所有可行路径，并输出。 这样的话，又该怎么办呢？我们从(1, 1)开始，如果某个格子可以走， 我们就将它保存到路径数组中；如果不能走，则回溯到上一个格子， 继续选择向右或者向下走。当机器人走到右下角的格子(M, N)时，即可输出一条路径。 然后程序会退出递归，回到上一个格子，找寻下一条可行路径。

*/

void print_paths(int m, int n, int M, int N, int len){
    if(g[m][n] == 0) return;
    point p; p.x=n; p.y=m;
    vp[len++] = p;
    if(m == M && n == N){
        for(int i=0; i<len; ++i)
            cout<<"("<<vp[i].y<<", "<<vp[i].x<<")"<<" ";
        cout<<endl;
    }
    else{
        print_paths(m, n+1, M, N, len);
        print_paths(m+1, n, M, N, len);
    }
}