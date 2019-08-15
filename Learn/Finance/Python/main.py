import set
import cmath
#求期待值
def analyis(data):
    print("=======begin=========")
    expected_a=0
    for k,v in data.items():
         expected_a+=(k*v)
    print("expected")
    print(expected_a)
    #方差
    variance_a=0
    for k,v in data.items():
        item = (expected_a-k)*(expected_a-k)*v
        variance_a+=item
    print("variance")
    print(variance_a)
    #标准差
    std_deviation=cmath.sqrt(variance_a)
    print("std_deviation")
    print(std_deviation)
    print("coefficient")
    print(std_deviation/expected_a)
analyis(set.ca)
analyis(set.cb)





