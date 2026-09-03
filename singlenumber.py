class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(len(nums)):
            if nums.count(nums[i])==1:
                return nums[i]
        

obj=Solution()
print(obj.singleNumber([1,2,1,2,4]))