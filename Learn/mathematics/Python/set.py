#数据

ca ={4:0.05,5:0.1,6:0.15,7:0.4,8:0.15,9:0.1,10:0.05}
  
cb ={5.5:0.25,6.5:0.25,7.5:0.25,8.5:0.25}
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