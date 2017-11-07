import math

x = [0]*21
x[0] = input("input x = :")
for i in range(20):
    x[i]=x[i]
    x[i+1]=x[i]-((x[i]**5)-235.4)/(5*(x[i]**4)) #牛顿法迭代公式
    print "%d :     %.4f"%(i+1,x[i+1])
