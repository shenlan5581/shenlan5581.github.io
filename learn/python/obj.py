
#class
#self 为类的实例
#self.__class__ 为类
# 类的方法必须带有额为的第一个参数名称为self 为类的实例
class obj:
    name = 'xingke'      #成员变量

    __pri_attrs ="私有变量"           #私有变量
    def  __pri_function(self):         #私有函数
       print("this is a private function") 

    def f1(self):            #成员函数
        print(self.name)   #成员访问
    def __init__(self,name):  #构造
        self.name = name       #赋值

class obj2:
    name = 'xingke'      #成员变量
    def f2(self):            #成员函数
        print('threed class')   #成员访问

    def __init__(self,name):  #构造
        self.name = name       #赋值

# 单继承 
class child(obj):   #括号中为基类
   def f1(self):      #子类的函数
      print("child class")
   def f2(sef):
      print("threed class")
   pass

#多继承
class threed(obj,obj2):
    pass

x = threed('yuxinji')
x.f2()