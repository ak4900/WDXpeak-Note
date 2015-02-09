#include <iostream>
#include <omp.h>

int main(){
    int a[10] = {1};
    int b[10] = {2};
    int c[10] = {0};

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < 10; ++i){
            // c[i] 只跟 a[i] 和 b[i] 有关
            c[i] = a[i] + b[i];
        }
    }

    return 0;
}