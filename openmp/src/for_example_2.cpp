#include <omp.h>

int main(){
    int a[10][5] = {1};
    int b[10][5] = {2};
    int c[10][5] = {3};

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < 10; ++i){
            for (int j = 0; j < 5; ++j){
                // c[i][j] 只跟 a[i][j] 和 b[i][j] 有关
                c[i][j] = a[i][j] + b[i][j];
            }
        }
    }

    return 0;
}