## Module 1.2

+ What are the differences between multicore and manycore processors?
+ What is instruction level parallelism? What is SIMD?
+ What is simultaneous multithreading?
+ What are the three metrics for a memory hierarchy?
+ What are the different system granularity?
+ How is this relevant to writing fast code?

## Module 1.3

+ What is the different between concurrency and parallelism?
+ What are the four key elements of the human problem solving process?
+ What are the characteristics of a current algorithm implementation?
+ What levels of concurrency can be exposed in the kmeans algorithm?
+ What levels of parallelism are available to be exploited?
+ What mapping between concurrency and parallelism can be explored?
+ How is this relavent to writing fast code?

## Module 2.1

+ What are the exploitable levels of parallelism in a multicore processor?
+ What is SPMD? And how to use OpenMP to do SPMD?
+ What is the difference between critical and atomic?
+ How to reduce synchronizatio ncost and avoid false sharing?
+ What are the scheduling, reduction, data sharing, and synchronizatio noptions for OpenMP?
+ How is this relevant to writing fast code?

## Module 2.2

+ Why naive matrix-multiply does not achieve peak performance on the CPU?
+ What are the different data layourts for matrices?
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


