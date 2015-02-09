#include <iostream>
#include <omp.h>
using namespace std;

int main(){
    int sum = 0;
    cout << "Before: " << sum << endl;

    #pragma omp parallel for
    for (int i = 0; i < 20000; ++i){
        #pragma omp atomic
        sum++;
    }
    cout << "Atomic-After: " << sum << endl;

    sum = 0;
    #pragma omp parallel for
    for (int i = 0; i < 20000; ++i){
        sum++;
    }
    cout << "None-atomic-After: " << sum << endl;
    return 0;
}