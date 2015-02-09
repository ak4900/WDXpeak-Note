#include <iostream>
#include <omp.h>
using namespace std;

int main(){
    cout << "CPU number: " << omp_get_num_procs() << endl;

    cout << "Parallel area 1: " << endl;

    #pragma omp parallel //下面大括号内部为并行区域
    {
        cout << "Num of threads is: " << omp_get_num_threads();
        cout << "; This thread ID is " << omp_get_thread_num() << endl;
    }

    cout << "Parallel area 2:" << endl;
    omp_set_num_threads(4); // 设置为并行区域创建4个线程
    #pragma omp parallel //下面大括号内部为并行区域
    {
        cout << "Num of threads is: " << omp_get_num_threads();
        cout << "; This thread ID is " << omp_get_thread_num() << endl;
    }

    return 0;
}