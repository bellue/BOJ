N=int(input())
A = [int(x) for x in input().split()]
M=int(input())
B = [int(x) for x in input().split()]
for i in A:
    for j in B:
        if i==j:
            print(1)
            break
    break