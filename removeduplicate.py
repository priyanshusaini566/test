class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l1=[]
        for i in range(len(nums)):
            if nums[i] not in l1:
                l1.append(nums[i])
            
        for i in range(len(l1)):
            nums[i]=l1[i]


        return len(l1)


obj=Solution()
print(obj.removeDuplicates([1,1,2]))