

#list   
a=['xingke','yuxinji']
print(a)
a.insert(1,'yaoyao')        #插入
print('index1',a[1])                    #输出下标1
a.sort() 
print('sort',a)
a.remove('yaoyao')
print('remove',a)
#遍历 list
for item in a:
    print('list:',item)

#use like stack
a.append('mama')  #push
print('append',a)
a.append('yaoyao')
print('append',a)
a.pop()                 #pop
print('pop',a)

#use like queue
from collections import deque #队列(速度慢）
a =deque(['a','b','c','d'])
a.append('kk')
print('push',a)   #enter
a.popleft()        #out
print('pop',a)

#元组
t = 123,456,'kk'
print(t)

#set
a=set('abcddadada') #会消除重复值
print(a)

#map
map ={'key':'value'} #empty
map['name']='xingke' #new key and value
map['sex']='nan' #new key and value
print('map',map)
del map['sex']
print('map del',map)

#遍历 map
for k,v in map.items():
    print('key',k)
    print('value',v)
