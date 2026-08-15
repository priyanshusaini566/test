s="yamadamya"
s2=""

for i in range(len(s)-1):
    for j in range(i+1,len(s)):
        sub=s[i:j]
        if(sub==sub[::-1]):
            if(len(sub)>len(s2)):
                s2=sub

print(s2)