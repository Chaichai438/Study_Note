# 1、while 判断条件(condition)：
#   执行语句(statements)……

#小示例:while 来计算 1 到 100 的总和
sum = 0
n = 1
while n<=100:
    sum += n
    n+=1
print("1到100的总和为:%d"%(sum))

# 2、while循环使用else语句
# while 判断条件(condition)：
#   执行语句(statements)……
# else:
#   执行语句(statements)……

vars = int(input("请输入一个数:"))

while (vars<=5):
    print("%d 小于 5" %(vars))
    vars+=1
else:
    print(vars,"大于 5")
    vars-=1
    