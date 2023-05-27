a=input() 
b=input()
c=input()
X=int(a)*int(b)*int(c)
Y=list(str(X))
B=[0,0,0,0,0,0,0,0,0,0,0,0,0]
for i in Y:
    for j in range(0,10):
        if Y[i]==j:
            B[j]+=1

for i in range(13):
    print(B[i])