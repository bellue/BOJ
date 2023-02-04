#미완
#N=int(input())
x=[str(i) for i in input().split()]
#for i in range(N):
#x.append(str(input()))

#���� ����
sum=0
point=0
final=0
for i in range(0,len(x)):
    if x[i]=='O':
        sum+=1
        point+=1
    if x[i]=='X':
        sum=0
final=sum+point    
print(final)
