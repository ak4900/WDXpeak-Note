#include <stdio.h>
#include <omp.h>

int main(){
    #pragma omp parallel
    {
        for (int i = 0; i < 100; ++i){
        printf("%d+\n", i);
        }

        #pragma omp barrier

        for (int j = 0; j < 10; ++j){
            printf("%d-\n", j);
        }
    }
    
}