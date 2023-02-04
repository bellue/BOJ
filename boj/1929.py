M,N=map(int,input().split())
i=M

for x in range(M,N+1):
    for y in range(2,i):
        if i%y==0:
            break
        if y==i-1:
            print(i)    
    i+=1    
