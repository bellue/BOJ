N=int(input())
A=[int(x) for x in input().split()]

#최솟값 구하기
sum1=0
for i in range(0,N): #배열 A를 첫번째 인자부터 마지막 인자까지 점검
    for j in range(0,N): #배열 A의 첫번째 인자와 첫번째 인자~마지막 인자까지 비교
        if sum1==N: #두번째 for문이 N번 반복되면 sum값이 N임 즉, 배열의 첫번째 인자부터 마지막 인자까지 비교했을때, 비교된? 인자가 가장 작다는 뜻
            min=A[i]
            break
        if A[i]<A[j]:
            j+=1 #비교되는 인자가 더 작으면 두번째 for문을 이용해 다음 인자와 비교
            sum1+=1
        elif A[i]>A[j]:
            break
    i+=1

print(min,end=' ')


#최댓값 구하기
sum2=0
for i in range(0,N):
    for j in range(0,N):
        if sum2==N:
            max=A[i]
            break
        if A[i]>A[j]:
            j+=1
            sum2+=1
        elif A[i]<A[j]:
            break
    i+=1

print(max)
