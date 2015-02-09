#include <stdio.h>
#include <omp.h>

int main(){
    #pragma omp parallel sections // 声明该区域分为若干个 section, section 之间的运行顺序为并行的关系
    {
        #pragma omp section // 第一个 section, 由某个线程单独完成
        for (int i = 0; i < 5; ++i){
            printf("%d+\n", i);
        }

        #pragma omp section // 另一个 section, 由某个线程单独完成
        for (int j = 0; j < 5; ++j){
            printf("%d-\n", j);
        }
    }
    return 0;
}