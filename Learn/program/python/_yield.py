
def y():
    i,n=0,10
    while i<n:
        i+=1
        yield i

a = y()
for s in a:
    print(s)