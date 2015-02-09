#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>

#define DATA_SIZE 1048576
#define THREAD_NUM 256
#define BLOCK_NUM 32

int data[DATA_SIZE];

void GenerateNumbers(int *number, int size){
    for (int i = 0; i < size; i++){
        number[i] = rand() % 10;
    }
}

bool InitCUDA(){
    int count;

    cudaGetDeviceCount(&count);
    if (count == 0){
        fprintf(stderr, "There is no device.\n");
        return false;
    }

    int i;
    for (i = 0; i < count; i++){
        cudaDeviceProp prop;
        if (cudaGetDeviceProperties(&prop, i) == cudaSuccess){
            if (prop.major >= 1){
                break;
            }
        }
    }

    if (i == count){
        fprintf(stderr, "There is no device supporting CUDA 1.x.\n");
        return false;
    }

    cudaSetDevice(i);

    return true;
}

__global__ static void sumOfSquares(int *num, int *result, clock_t *time){

    extern __shared__ int shared[];

    const int tid = threadIdx.x;
    const int bid = blockIdx.x;

    int i;
    int offset = 1, mask = 1;
    if (tid == 0)
        time[bid] = clock();

    shared[tid] = 0;
    for (i = bid * THREAD_NUM + tid; i < DATA_SIZE; i += BLOCK_NUM * THREAD_NUM){
        shared[tid] += num[i] * num[i];
    }

    __syncthreads();
    while(offset < THREAD_NUM){
        if ((tid & mask) == 0){
            shared[tid] += shared[tid + offset];
        }
        offset += offset;
        mask = offset + mask;
        __syncthreads();
    }

    if (tid == 0){
        result[bid] = shared[0];
        time[bid + BLOCK_NUM] = clock();
    }


}

int main(){
    if (!InitCUDA()){
        return 0;
    }

    printf("CUDA initialized.\n");

    GenerateNumbers(data, DATA_SIZE);

    int *gpudata, *result;
    clock_t *time;

    cudaMalloc((void**) &gpudata, sizeof(int) * DATA_SIZE);
    cudaMalloc((void**) &result, sizeof(int) * THREAD_NUM * BLOCK_NUM);
    cudaMalloc((void**) &time, sizeof(clock_t) * BLOCK_NUM * 2);
    cudaMemcpy(gpudata, data, sizeof(int) * DATA_SIZE, cudaMemcpyHostToDevice);

    sumOfSquares<<<BLOCK_NUM, THREAD_NUM, 0>>>(gpudata, result, time);

    int sum[BLOCK_NUM];
    clock_t time_used[BLOCK_NUM * 2];
    cudaMemcpy(&sum, result, sizeof(int) * BLOCK_NUM, cudaMemcpyDeviceToHost);
    cudaMemcpy(&time_used, time, sizeof(clock_t) * BLOCK_NUM * 2, cudaMemcpyDeviceToHost);
    cudaFree(gpudata);
    cudaFree(result);
    cudaFree(time);

    int final_sum = 0;
    for(int i = 0; i < BLOCK_NUM; i++){
        final_sum += sum[i];
    }

    clock_t min_start, max_end;
    min_start = time_used[0];
    max_end = time_used[BLOCK_NUM];
    for (int i = 1; i < BLOCK_NUM; i++){
        if (min_start > time_used[i])
            min_start = time_used[i];
        if (max_end < time_used[i + BLOCK_NUM])
            max_end = time_used[i + BLOCK_NUM];
    }

    printf("sum: %d time: %d\n", final_sum, max_end - min_start);

    final_sum = 0;
    for(int i = 0; i < BLOCK_NUM; i++){
        final_sum += sum[i];
    }
    printf("sum (CPU): %d\n", final_sum);

    return 0;
}
