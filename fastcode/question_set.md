## Module 1.2

+ What are the differences between multicore and manycore processors?
    * Multicore: yoke of oxen. Each core optimized for executing a single thread.
    * Manycore: flock of chickens. Cores optimized for aggregate throughput, deemphasizing individual performance.
+ What is instruction level parallelism? What is SIMD?
    * ILP: Instructions in a sequence that can be computed at the same time.
    * ILP(wiki): a measure of how many of the operations in a computer program can be performed simultaneously
    * SIMD(wiki): computers with multiple processing elements that perform the same operation on multiple data points simultaneously. data level parallelism. 
+ What is simultaneous multithreading?
    * a technique for improving the overall efficiency of superscalar CPUs with hardware multithreading. SMT permits multiple independent threads of execution to better utilize the resources provided by modern processor architectures.
+ What are the three metrics for a memory hierarchy?
    * Capacity: Size, e.g. number of bytes of data
    * Latency: From start to finish, in units of time, e.g. CPU clock cycles
    * Throughput: Tasks accomplished per unit time, e.g. GB/s
+ What are the different system granularity?
    * Remote Procedure Call based Implementations
    * MPI-based Implementations
    * Pthread-based Implementations
    * Multicore Task Queue-based Implementations
    * Manycore Throughput Optimized Implementations
+ How is this relevant to writing fast code?

## Module 1.3

+ What is the different between concurrency and parallelism?
    * Concurrency: We expose concurrency in our application
    * Parallelism: We exploit parallelism in our platform
+ What are the four key elements of the human problem solving process?
    * Understand the current state
    * Observe the internal representation
    * Search among alternatives
    * Select from a set of choices
+ What are the characteristics of a current algorithm implementation?
    * Efficiency
    * Simplicity
    * Portablility
    * Scalability
+ What levels of concurrency can be exposed in the kmeans algorithm?
    * ?
+ What levels of parallelism are available to be exploited?
    * ?
+ What mapping between concurrency and parallelism can be explored?
    * SIMD & core-level parallelism across data-points
        - Update membership for each data point sequentially
        - Histogram computation

## Module 2.1

+ What are the exploitable levels of parallelism in a multicore processor?
+ What is SPMD? And how to use OpenMP to do SPMD?
+ What is the difference between critical and atomic?
+ How to reduce synchronization cost and avoid false sharing?
+ What are the scheduling, reduction, data sharing, and synchronization options for OpenMP?
+ How is this relevant to writing fast code?

## Module 2.2

+ Why naive matrix-multiply does not achieve peak performance on the CPU?
+ What are the different data layouts for matrices?
+ What is cache blocking? Why do we need it?
+ Is blocking sufficient? What more can we do?
+ What can be learned from this for other computation?

## Module 2.3

+ What is the roofline model? What are the metrics and axis used?
+ What is the difference between “flop’s per memory instruction” from “flop’s per DRAM byte”?
+ Consider an image `Image[height][width]`. If one were to stride through the columns of values, what would be the effects? How would they be mapped to the roofline?
+ How does one model incomplete SIMDization (e.g. half the flop’s can be SIMDized). insufficient ILP(some dependent flop’s), or an imbalance between FDMUL’s and FPADD’s on the roofline?
+ How would one model {branch mispredicts, TLB misses, or too many streams for the prefetchers} on the roofline.

## Module 3.1

+ What’s the Difference between Multicore and Manycore?
+ When does using a GPU make sense?
+ What is the memory hierarchy inversion? And why is it there?
+ What is the memory wall? How to get around it?
+ Why warps?
+ How do we deal with GPUs of different sizes?
+ What are the implications of the thread block abstraction?
+ How do threads communicate with each other?
+ What is the caveat in synchronizing threads in a thread block?

## Module 3.2

+ What are the three ways to improve execution throughput?
+ When to use SOA vs AOS?
+ What is memory coalescing? When to use it? Why is it important?
+ What is shared memory? How to use it?
+ What is memory bank conflict? How to work around it?
+ What is branch divergence?
+ How to optimize for instruction mix?
+ What is occupancy? How to model/measure it?
+ How to use the code profiler with CUDA?

## Module 3.3

+ What are the important properties of a Map function?
+ What are the important properties of a Reduce function?
+ What are the important properties of s Scan function?
+ How to compact an array in a data-parallel way?
+ How to find unique elements in an array in a data-parallel way?

## Module 3.4

+ What are parallel software patterns?
+ What are the three goals the software patterns aim to achieve?
+ What is a software architecture?
+ How is it important for writing fast code?
+ What the the five categories of patterns in OPL?
+ What are the nine sections in an OPL pattern?
+ What are the areas of consideration for your Term Project?
