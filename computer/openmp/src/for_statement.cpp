#include <iostream>
#include <omp.h>
#include <stdio.h>
using namespace std;

int main(){
    // for 循环并行化声明形式1
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < 10; ++i){
            printf("%d\n", i);
        }
    }

    // for 循环并行化声明形式2
    #pragma omp parallel for
    for (int j = 0; j < 10; ++j){
        printf("%d\n", j);
    }
    return 0;
}