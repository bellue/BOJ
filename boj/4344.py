N=int(input())

for i in range(N):
    sum=0
    num=0
    x=[int(x) for x in input().split()]
    for i in range(1,len(x)):
            sum+=x[i]
    av=sum/x[0]
    for i in range(1,len(x)):
        if av<x[i]:
            num+=1
    final=num/x[0]*100
    print(f'{final:.3f}%')

