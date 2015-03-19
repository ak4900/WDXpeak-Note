# 机器学习基石 学习笔记

Hsuan-Tien Lin htlin@csie.ntu.edu.tw

## Roadmap

+ Lecture 1: The Learning Problem 
    * _A_ takes _D_ and _H_ to get _g_
+ Lecture 2: Learning to Answer Yes/No
    * Perceptron Hypothesis Set
    * Perceptron Learning Algorithm, PLA
    * Guarantee of PLA
    * Non-Separable Data
    * 

## Lecture 1 The Learning Problem

从基础学习 what every machine learning user should know

+ When Can Machines Learn? illustrative + technical
+ Why Can Machines Learn? theoretical + illustrative
+ How Can Machines Learn? technical + practical
+ How Can Machines Learn Better? practical + theorietical

知其然也知其所以然

### 从学习到机器学习

+ 学习的过程：observations -> **learning** -> skill
+ 机器学习的过程：data -> **ML** -> skill(improved performance measure)
+ skill: improve some **performance measure**
+ machine learning
    * improving some perormance mearsure with experience computed from data
    * an alternative route to build complicated systems
+ 三个关键
    * exists some 'underlying pattern' to be learned, so performance measure can be improved. 要有东西可学
    * but no programmable definition, so 'ML' is needed
    * somehow there is data about the pattern. 要有大量数据
+ 大数据
+ 学习问题
    * 输入 x
    * 输出 y
    * 目标函数 target function f: X->Y
    * data D={(x1,y1),(x2,y2),...,(xn,yn)}
    * 机器学习可能得到的假设 g:X->Y
    * {(xn, yn)} from f -> ML -> g
 
 ![learning flow](./_resources/mlf1.jpg)

+ f 我们不知道
+ g 越接近 f 越好 
+ A takes D and H to get g
+ related to DM, AI and Stats

## Lecture 2 Learn to Answer Yes/No

+ 每一个样本的数据可以看成一个向量，可以给每一个向量计算出一个加权得分，每一个维度有一个权重。
+ 把 threshold 收进公式中，可以得到一个统一的表达，最后的得分等于两个向量相乘
+ ![mlf2](./_resources/mlf2.jpg)
+ perceptrons <-> linear(binary) classifiers 线性分类器
+ select g from H
    * H = all possible perceptrons, g = ? 从这么多可能的线之中，选出一条最好的，最能区分数据的
    * 先要求 g 和 f 在已有数据上结果最接近, g(xn) = f(xn) = yn
    * 难点在于，H 很大，有无数种可能的线(分类器)
    * 从第一条线 g0 开始，不断进行修正，可以认为是一开始的权重向量 w0
+ Perceptron Learning Algorithm
    * For t = 0, 1, ... 这里 t 是轮数，因为会迭代很多次
    * 找到 wt 的一个分类错误的点(xn(t), yn(t)), 即 sign(wt^T xn(t)) 不等于 yn(t)
    * 试着去改正这个错误 wt+1 <- wt + yn(t)xn(t) until no more mistakes
    * 返回最后得到的 w 为 g, 这个 w 称为 w(pla)
+ Cyclic PLA
    * For t = 0,1,...
    * find the next mistake of wt called (xn(t), yn(t)), aka sign(wt^T xn(t)) 不等于 yn(t)
    * correct the mistake by wt+1 <- wt + yn(t)xn(t)
    * until a full cycle of not encountering mistakes
    * 可以采用标准的遍历，或者也可以是预先计算好的随机顺序
+ Linear Separability 线性可分
    * if PLA halts, (necessary condition) D allows some w to make no mistake
    * 有一条线可以区分数据，即有解，有解的时候 PLA 算法才会停
+ TODO 2-3
