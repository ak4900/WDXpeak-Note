#include <stdio.h>
#include <omp.h>

int main(){
    #pragma omp parallel
    {
        #pragma omp master
        {
            for (int j = 0; j < 10; ++j){
                printf("%d-\n", j);
            }
        }

        printf("This will be shown two or more times\n");
    }
    return 0;
}