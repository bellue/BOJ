N=int(input())
A=[int(x) for x in input().split()]
B=[]
for i in range(0,N):
    B.append(A[i]/max(A))
sum=0
for i in range(0,N):
    sum+=B[i]
print((sum/N)*100)