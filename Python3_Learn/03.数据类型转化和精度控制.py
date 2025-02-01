# python的数据类型转化和C/C++并没有什么区别

# 隐式转化
num_int = 111
num_float = 0.996
print(num_int,"   数据类型为",type(num_int))
print(num_float,"   数据类型为",type(num_float))
print(num_int+num_float,"   数据类型为",type(num_int+num_float))

print("-----------------------------------------")

# 显式转化
num1 = 10
print(float(num1))
print(str(num1))
print(bool(num1))

num2 = 9.64654
print(int(num2))
print(str(num2))
print(bool(num2))

print("-----------------------------------------")

# 精度控制
name = "Chaichai_柴柴"
age = 16
height = 182.39
message = "我的名字叫%s,我今年%d岁,我的身高是%.2fcm"%(name,age,height)
print(message)