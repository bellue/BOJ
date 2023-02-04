N=int(input())
check=0
if N<10:
    a=int(0)
    b=int(N)
if 10<=N<100:
    a=int(N/10)
    b=int(N%10)
X=int(0)
for i in range(100):
    check+=1
    X=10*b+(a+b)%10
    if X<10:
        a=int(0)
        b=int(X)
    if 10<=X<100:
        a=int(X/10)
        b=int(X%10)
    
    if N==X:
        break    
    
    

print(check)

