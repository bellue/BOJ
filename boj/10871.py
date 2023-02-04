N,X=map(int,input().split())
A=[int(x) for x in input().split() if int(x)<X]
sum=0
for x in A:
   sum+=x
print(sum)

