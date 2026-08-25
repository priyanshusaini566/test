class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        if(len(nums)<2):
            return nums

        else:
            middle=len(nums)//2

        left=self.sortArray(nums[:middle])
        right=self.sortArray(nums[middle:])

        result= []
        i=0
        j=0
        while i<len(left) and j<len(right):
            if left[i]<right[j]:
                result.append(left[i])
                i+=1

            else:
                result.append(right[j])
                j+=1

        result.extend(left[i:])
        result.extend(right[j:])

        return result

obj=Solution()
l1=[1,3,5,4,2]
obj.sortArray(l1)