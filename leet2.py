class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        min=prices[0]
        max_pf=0
        for i in range(len(prices)):
            if prices[i]<min:
                min=prices[i]

            else:
                profit=prices[i]-min
                if profit>max_pf:
                    max_pf=profit

        return max_pf

obj=Solution()
print(obj.maxProfit([7,1,2,5,6,3]))