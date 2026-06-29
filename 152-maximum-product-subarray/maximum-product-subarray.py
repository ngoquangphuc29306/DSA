class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        n = len(nums)
        maxPro = [1] * (n + 1)
        minPro = [1] * (n + 1)

        maxPro[0] = nums[0]
        minPro[0] = nums[0]

        ans = 0

        for i in range(n):
            maxPro[i] = max(nums[i], maxPro[i - 1] * nums[i], minPro[i - 1] * nums[i])
            minPro[i] = min(nums[i], minPro[i - 1] * nums[i], maxPro[i - 1] * nums[i])

            ans = max(ans, maxPro[i])

        return ans