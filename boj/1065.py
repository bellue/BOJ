#x[i]-x[i-1] 이 일정
x=input()
sum=0
for i in range(1,int(x)+1):
    h=str(i)
    if 0<i<10:
        sum+=1
    elif i<100:
        sum+=1
    elif 99<i<1000:
        for j in range(0,1):
            if int(h[j])-int(h[j+1])==int(h[j+1])-int(h[j+2]):
                sum+=1
    elif i==1000:
        sum+=0

print(sum)