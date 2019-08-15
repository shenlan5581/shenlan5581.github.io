#encoding:utf-8 
import cmath
print("series ")

series =[1,3,5,6,7,9,11,13,22,66,87]
n = 11  #总数个数
a = 55  #极限
e = 1 #任意数
N = 8   #界限
i=0
#求是否有极限
for I in series:
    if i>N:
        if ((abs(I-a))<e):
         continue
        else:
         print("is not")
         quit()
    else:
     i+=1  
print("yes")







