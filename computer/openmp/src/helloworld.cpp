#include <omp.h>
#include <iostream>
using namespace std;

int main(){
    #pragma omp parallel for 
    for (int i = 0; i < 10; ++i)
    {
        cout << i;
    }
    cout << endl;
    return 0;
}