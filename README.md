# 实验一：分治算法实验报告

## 学号：20201060564

## 实验目的：

  通过排序算法的程序实现和执行时间测试，与理论上的结论进行对比分析，深入理解算法时间复杂度渐进性态和和增长率的概念；理解分治算法设计的基本思想、递归程序实现的基本方法，加深对分治算法设计与分析思想的理解。

## 实验原理

  以冒泡排序、合并排序和快速排序算法为例，以生成的随机数作为实验中使用的测试数据。对每个算法，记录程序执行中随着测试数据增加算法基本操作执行次数，分析并以图形方式展现增长率；对以上三个排序算法，对比随着测试数据增加算法增长率变化趋势；测试、验证、对比算法时间复杂度的理论结论。


## 实验输入数据集

使用线性同余法生成的随机数

## 实验内容
1. [max.py](./max.py) 算法实现的python版本
1. [max.c](max.c) 算法实现的C语言版本
1. [max.java](max.java) 算法实现的java版本

## 实验预期结果与实际结果
+ 实验预期结果：14

实验过程及实验结果（Java版）

```bash
gitpod /workspace/homewrok_template (main) $ javac Max.java
Picked up JAVA_TOOL_OPTIONS:  -Xmx3435m
gitpod /workspace/homewrok_template (main) $ java Max
Picked up JAVA_TOOL_OPTIONS:  -Xmx3435m
14

```

实验过程及实验结果（C版）

```bash
gitpod /workspace/homewrok_template (main) $ gcc -o max.exe max.c
gitpod /workspace/homewrok_template (main) $ ./max.exe 
14

```

实验过程及实验结果（Python版）

```bash
gitpod /workspace/homewrok_template (main) $ python max.py 
14

```
