'''
常见的数据类型(六种)有：
Number(数字):int整数、float浮点数、complex复数、bool布尔
String(字符串)
List(列表)
Tuple(元组)
Set(集合)
Dictionary(字典)
'''
# 1.type()可以用来判断数据类型，并返回一个值
a = 100
b = 10.23
c = 5+3j
d = True

print(type(a),type(b),type(c),type(d))

print("-------------------------------")

# 2.数值运算
# 大致与C语言的相同，下面列举一些不同的运算
print(3 ** 2)      #3的2次方
print(6 / 3)       #得到一个浮点数
print(6 // 3)      #得到一个整数

print("-------------------------------")
# 3.Python中字符串不能被改变
Menu = "Python"
print(Menu[5])
# Menu[5] = "e" 

print("-------------------------------")
# 4.Bool类型 
# False 为0   True 为非0数
print(bool(1))
print(bool(0))
print(bool(12341))

print("-------------------------------")

# 5.List列表
# 类比C中的数组，但是又不完全像，可以包含数字，字符串甚至嵌套
list01 = ["你的名字",114,"aaaaaaaa","internet"]
list02 = ["变量",16.946]
print(list01)#输出整个列表
print(list01[3])#输出list01的四个元素

# 不同的是列表的元素可以改变
list02[0] = "temp" 
print(list02)#输出整个列表

# 不同列表之间可以进行拼接
list = list01 + list02
print(list)

# 列表还有很多用法，之后再学习
# 其他的用法和字符串一致，不过多赘述

print("-------------------------------")

# 6.元组（tuple）
# 与列表类似，不同之处在于元组的元素不能修改。元组写在小括号 () 里，元素之间用逗号隔开
tuple01 = ("abcd", 786 , 2.23, "颗粒", 70.2)
tuple02 = (123,"happy")
print(tuple01)
print(tuple01[0])
print(tuple01+tuple02)

# 像表示只含一个元素的元组 
tuple= (946,)# 识别的是一个元组
not_a_turple = (946)# 识别的是一个值
print(tuple) 
print(not_a_turple)

print("-------------------------------")

# 7.集合（set)
# 一种无序、可变的数据类型，用于存储唯一的元素。
# 集合中的元素不会重复，并且可以进行交集、并集、差集等常见的集合操作。

sites = {'Google', 'Taobao', 'Runoob', 'Facebook', 'Zhihu', 'Baidu',"Baidu"}

print(sites)   # 输出集合，重复的元素被自动去掉

# 成员测试
if 'Runoob' in sites :
    print('Runoob 在集合中')
else :
    print('Runoob 不在集合中')

# set可以进行集合运算
a = set('abracadabra')
b = set('alacazam')

print(a)
print(a - b)     # a 和 b 的差集
print(a | b)     # a 和 b 的并集
print(a & b)     # a 和 b 的交集
print(a ^ b)     # a 和 b 中不同时存在的元素

print("-------------------------------")

# 8.字典（dictionary）
# 列表是有序的对象集合，字典是无序的对象集合。
# 两者之间的区别在于：字典当中的元素是通过“键”来存取的，而不是通过偏移存取。
# 字典是一种映射类型，字典用 { } 标识，它是一个无序的 键(key) : 值(value) 的集合。
# 键(key)必须使用不可变类型。
# 在同一个字典中，键(key)必须是唯一的。

dirc = { }
dirc["114514"] = "我想学这个,教练！"
dirc[12] = "日本足球队又双叒叕进球了！"

tiny_dirc = {"text1":"114514","text2":12,"name":"Chaichai_柴柴"}

print (dirc["114514"])       # 输出键为 'one' 的值
print (dirc[12])           # 输出键为 2 的值
print (tiny_dirc)          # 输出完整的字典
print (tiny_dirc.keys())   # 输出所有键
print (tiny_dirc.values()) # 输出所有值