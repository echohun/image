import math
x = [0]*21
x[0] = input("input x = :")
for i in range(20):
    x[i]=x[i]
#    x[i+1] = math.atan(4-x[i])     #������ʽ
#    x[i+1] = (math.exp(x[i])/3)**0.5       #������ʽ
    print "%d :     %f"%(i+1,x[i+1])
