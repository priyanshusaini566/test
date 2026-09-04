class Solution(object):
    def moveZeroes(self, nums):
        l=[]
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)):
            if (nums[i])!=0:
                l.append(nums[i])

        for j in range(nums.count(0)):
            l.append(0)

        nums[:] = l

obj=Solution()
print(obj.moveZeroes([0,3,6,4,0,2,7]))