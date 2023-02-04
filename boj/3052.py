#개행으로 입력받기
A=[]
for i in range(10):
    A.append(int(input())%42)
B=[]
for i in range(0,42):
    B.append(int(A.count(i))) #0이아닌게 몇개인지
sum=0
for i in range(0,42):
    if B[i]!=0:
        sum+=1
print(sum)