import math

def fun(x):
    #y=x*((x-1)*x-2)+1                #第一题的公式
    y=2*math.exp(-x)-math.sin(x)     #第二题的公式
    return y
print "Input a,b:"
a = float(input("a = "))
b = float(input("b = "))
fa=fun(a)
fb=fun(b)

for i in range(10):
    x=(a+b)/2
    print "%f   %f   %f"%(a,x,b)
    fx=fun(x)
    if fx*fa<0 :
        fb=fx
        b=x
    else:
        fa=fx
        a=x      
print "The final result is :  %.3f"%x
