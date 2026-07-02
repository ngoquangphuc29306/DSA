import bisect as bs
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)

        if n < 1:
            return 0
        
        v = []

        for x in nums:
            pos = bs.bisect_left(v, x)

            if pos == len(v):
                v.append(x)
            else:
                v[pos] = x

        return len(v)