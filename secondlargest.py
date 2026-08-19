class Solution():
    def secondHighest(self, s):
        """
        :type s: str
        :rtype: int
        """
        digits=[]

        for item in s:
            if item.isdigit():
                digits.append(int(item))

        digits=list(set(digits))
        digits.sort()

        if(len(digits)<2):
            return -1

        return digits[-2]

obj=Solution()
s=input("Enter the string : ")
print(obj.secondHighest(s))



        