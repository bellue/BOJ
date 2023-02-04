#띄어쓰기로 한줄로 입력받기
N=int(input())
A=[int(x) for x in input().split()]
A.sort()
print(A[0],end=' ')
print(A[N-1])
