#include <iostream>
#include <omp.h>
#include <stdio.h>
using namespace std;

int main(){
    int share_a = 0; // 共享变量
    int share_to_private_b = 1; // 通过 private 子句修饰该变量之后在并行区域内变为私有变量

    #pragma omp parallel
    {
        int private_c = 2;
        
        #pragma omp for private(share_to_private_b)
        for (int i = 0; i < 10; ++i) //该循环变量是私有的，若为两个线程，则一个线程执行0~4，另一个执行5~9
            printf("%d\n", i);

    }

    return 0;
}