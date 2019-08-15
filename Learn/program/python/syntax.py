#loop
a=0;
while  a<5:
    print(a)
    a+=1
#遍历
array=["a","b","c","d"]
for x in array:
    print(x)
    if x=='c':   #条件
       break

#可变对象 和 不可变对象
#不可变对象
def fun(a):
     a = 1
     print("inside fun",a)
val = 0
fun(val)
print(val)
def fun2(a):
    a.append([1,2])
    print(a)
val2 = [4,5]
fun2(val2)