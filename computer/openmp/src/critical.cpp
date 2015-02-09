#include <iostream>
#include <omp.h>
using namespace std;

int main(){
    int sum = 0;
    cout << "Before: " << sum << endl;

    #pragma omp parallel for
    for (int i = 0; i < 100; ++i){
        #pragma omp critical(a)
        {
            sum = sum + i;
            sum = sum + i * 2;
        }
    }

    cout << "After: " << sum << endl;

    return 0;
}