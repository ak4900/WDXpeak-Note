#include <stdio.h>
#include <omp.h>

int main(){
    #pragma omp parallel
    {
        #pragma omp for nowait
        for (int i = 0; i < 1000; ++i){
            printf("%d+\n", i);
        }

        #pragma omp for
        for (int j = 0; j < 10; ++j){
            printf("%d-\n", j);
        }

        #pragma omp for
        for (int k = 0; k < 10; ++k){
            printf("%d#\n", k);
        }
    }
    return 0;
}