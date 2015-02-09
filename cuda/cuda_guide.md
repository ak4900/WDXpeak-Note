## CUDA架构

在 CUDA 的架构下,一个程序分为两个部份:host 端和 device 端。Host 端是指在 CPU 上执行 的部份,而 device 端则是在显示芯片上执行的部份。Device 端的程序又称为 "kernel(核心)"。 通常 host 端程序会将数据准备好后,复制到显卡的内存中,再由显示芯片执行 device 端程序,完 成后再由 host 端程序将结果从显卡的内存中取回。

在 CUDA 架构下,显示芯片执行时的最小单位是 thread(线程)。数个 thread 可以组成一个 block(块)。一个 block 中的 thread 能存取同一块共享的内存,而且可以快速进行同步的动作。

每一个 block 所能包含的 thread 数目是有限的。不过,执行相同程序的 block,可以组成 grid(格子)。不同 block 中的 thread 无法存取同一个共享的内存,因此无法直接互通或进行同步。因此, 不同 block 中的 thread 能合作的程度是比较低的。不过,利用这个模式,可以让程序不用担心显示芯片实际上能同时执行的 thread 数目限制。例如,一个具有很少量执行单元的显示芯片,可能会 把各个 block 中的 thread 顺序执行,而非同时执行。不同的 grid 则可以执行不同的程序(即 kernel)。

每个 thread 都有自己的一份 register 和 local memory 的空间。同一个 block 中的每个 thread 则有共享的一份 share memory。此外,所有的 thread(包括不同 block 的 thread)都共享一份 global memory、constant memory、和 texture memory。不同的 grid 则有各自的 global memory、 constant memory 和 texture memory。

## 执行模式

由于显示芯片大量并行计算的特性,它处理一些问题的方式,和一般 CPU 是不同的。主要的特点包括:

1. 内存存取 latency 的问题:CPU 通常使用 cache 来减少存取主内存的次数,以避免内存 latency 影响到执行效率。显示芯片则多半没有 cache(或很小),而利用并行化执行的方式来隐藏内存的 latency(即,当第一个 thread 需要等待内存读取结果时,则开始执行第二 个 thread,依此类推)。
2. 分支指令的问题:CPU 通常利用分支预测等方式来减少分支指令造成的 pipeline bubble。显示芯片则多半使用类似处理内存 latency 的方式。不过,通常显示芯片处理分支的效率会比较差

最适合利用 CUDA 处理的问题,是可以大量并行化的问题,才能有效隐藏内存的 latency, 并有效利用显示芯片上的大量执行单元。使用 CUDA 时,同时有上千个 thread 在执行是很正常的。 因此,如果不能大量并行化的问题,使用 CUDA 就没办法达到最好的效率了。

## 基本概念

+ streaming processor, sp: 最基本的处理单元，最后具体的指令和任务都是在 sp 上处理的。GPU 进行并行计算，也就是很多个 sp 同时做处理
+ streaming multiprocessor, sm: 多个 sp 加上存储资源组成一个 sm
+ warp: GPU 执行程序时的调度单位，目前 CUDA 的 warp 大小为32，同在一个 warp 的线程，以不同数据资源执行相同的指令。
+ thread, block, grid: 利用 CUDA 进行编程时，一个 grid 分为多个 block，一个 block 分为多个 thread (From a programmer’s perspective)

### Some Restrictions First

+ All threads in a grid execute the same kernel function
+ A grid is organized as a 2D array of blocks(gridDim.X and gridDim.y)
+ Each block is organized as 3D array of threads(blockDim.x, blockDim.y, and blockDim.z)
+ Once a kernel is launched, its dimensions cannot change.
+ All blocks in a grid have the same dimension
+ The total size of a block is limited to 512 threads(? I’m not sure?)
+ Once assigned to an SM, the block must execute in its entirey by the SM.
+ Thread ID is unique within a block
+ Using block ID and thread ID we can make unique ID for each thread per kernel
+ Threads assigned to execution resources on a block-by-block basis
+ CUDA runtime automatically reduces number of blocks assigned to each SM
+ until resource usage is under limit.

### SM -Streaming multi-processors with multiple processing cores

+ Each SM contains 32 processing cores
+ Execute in a Single Instruction Multiple Thread (SIMT) fashion
+ Up to 16 SMs on a card cor a maximum of 512 compute cores

### Warps

+ Once a block is assigned to an SM, it is divided into units called warps.
+ Thread IDs within a warp are consecutive and increasing
+ Warp 0 starts with Thread ID 0
+ Warp is unit of thread scheduling in SMs
+ Partitioning is always the same
+ DO NOT rely on any ordering between warps
+ Each warp is executed in a SIMD fashion (all threads within a warp must execute the same instruction at any given time)
+ Problem: branch divergence

### Latency Tolerance

+ When an instruction executed by the threads in a warp must wait for the result of a previously initiated long-latency operation, the warp is not selected for execution -> lantency hiding
+ Priority mechanism used to schedule ready warps
+ Scheduling does not introduce idle time -> zero-overhead thread scheduling
+ Scheduling is used for telerating long-latency operations, such as:
+ piplined floating-point arithmetic
+ branch instructions

The only safe way to synchronize threads in different blocks is to terminate the kernel and start a new kernel for the acitivities after the synchronization point.

## 代码相关

+ 通过 cudaGetDeviceProperties 函数可以取得许多数据，除了装置支持的 CUDA 版本之外, 还有装置的名称、内存的大小、最大的 thread 数目、执行单元的频率等等
