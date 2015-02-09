#include <iostream>
#include <stdio.h>
#include <omp.h>
using namespace std;

int main(){
    int sum = 0;
    cout << "Before: " << sum << endl;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < 10; ++i){
        sum = sum + i;
        printf("%d\n", sum);
    }

    cout << "After: " << sum << endl;

    return 0;
}