# 实验一：分治算法实验报告

## 学号：20201060564

## 实验目的：

  通过排序算法的程序实现和执行时间测试，与理论上的结论进行对比分析，深入理解算法时间复杂度渐进性态和和增长率的概念；理解分治算法设计的基本思想、递归程序实现的基本方法，加深对分治算法设计与分析思想的理解。

## 实验原理

  以冒泡排序、合并排序和快速排序算法为例，以生成的随机数作为实验中使用的测试数据。对每个算法，记录程序执行中随着测试数据增加算法基本操作执行次数，分析并以图形方式展现增长率；对以上三个排序算法，对比随着测试数据增加算法增长率变化趋势；测试、验证、对比算法时间复杂度的理论结论。


## 实验输入数据集

使用线性同余法生成的随机数

## 实验内容
(1) “比较”是以上排序算法的基本操作（即决定算法执行效率的主要操作），在算法中设置比较操作的计数器，编程实现算法（输出最终的计数值）并进行测试，保证程序正确无误。
(2) 使用随机数生成方法生成包含 100 个随机数的测试数据，记录这些数据，并分别记录以上三个排序算法比较操作的执行次数；再重新生成包含 100 个随机数的测试数据，记录这些数据三个排序算法比较操作的执行次数。
![image](https://github.com/wtiantianw/homewrok_template/blob/main/%E6%B5%8B%E9%AA%8C100.png)


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
