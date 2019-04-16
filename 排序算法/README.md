# 排序算法

# 介绍

		实现了插入(InsertSort)、 归并(MergeSort)、递归快排(QuickSort_Recursion)、迭代快排(QuickSort)、
	计数(CountSort)和基数计数排序(RadixCountSort)；以上排序的时间测试、文件测试及应用


# 测试结果

##### 一、大数据时间测试

​	随机生成1w、5w、20w的数据，测试每个排序的时间

###### 	(1) 插入排序：

​	![img](https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/1_1.png)

###### 	(2) 归并排序：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/1_2.png>)

###### 	(3) 计数排序：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/1_3.png>)

###### 	(4) 递归快排：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/1_4.png>)

###### 	(5) 迭代快排：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/1_5.png>)

###### 	(6) 基数排序：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/1_6.png>)

##### 二、大量小数据时间测试

​	随机生成100个数字，100k次(总共100*100k数据)

###### 	(1) 插入排序：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/2_1.png>)

###### 	(2) 归并排序：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/2_2.png>)

###### 	(3) 计数排序：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/2_3.png>)

###### 	(4) 递归快排：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/2_4.png>)

###### 	(5) 迭代快排：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/2_5.png>)

###### 	(6) 基数排序：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/2_6.png>)

##### 三、文件测试

​	随机生成数字保存到文件1.txt中，并用该串数字进行排序，将结果保存到文件2.txt中，以下n(数组长度)都为为7

###### 		(1) 插入排序：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/3_1_1.png>)
​	此时文件内容为：

​	![img](https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/3_1_2.png)

###### 	(2) 归并排序：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/3_2_1.png>)
​	此时文件内容为：
​	![img](https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/3_2_2.png)

###### 	(3) 计数排序：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/3_3_1.png>)

​	此时文件内容为：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/3_3_2.png>)

###### 	(4) 递归快排：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/3_4_1.png>)

​	此时文件内容：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/3_4_2.png>)

###### 	(5) 迭代快排：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/3_5_1.png>)

​	此时文件内容：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/3_5_2.png>)

###### 	(6) 基数排序：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/3_6_1.png>)

​	此时文件内容：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/3_6_2.png>)

##### 四、手动测试

​	这里仅测试两个应用排序

###### 	(1)颜色排序：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/4_1.png>)

###### 	(2)寻找数字：

​	![img](<https://raw.githubusercontent.com/k8kiw/homework/master/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/test_img/4_2.png>)

​	排序完的结果应为：-692   -579   -498   0   2   56   156   1564   74891

​	第五小的数字为2