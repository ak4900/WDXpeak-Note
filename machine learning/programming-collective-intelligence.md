# 集体智慧编程 笔记

### 列表推导式 list comprehension

一种方便简洁的语法形式

    [表达式 for 变量 in 列表]
    or
    [表达式 for 变量 in 列表 if 条件]

    l=[1,2,3,4,5,6,7,8,9]
    print [v*10 for v in l if v>4]
    timesten=dict([(v,v*10) for v in l])

## 导言

+ 利用开放的 API 搜集数据 + 机器学习算法和统计方法 = 借助集体智慧的相关方法
+ 所有机器算法都有过度归纳的可能性

## 提供推荐 Making Recommendations

如何根据群体偏好来为人们提供推荐
