class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        sorted_nums = sorted(nums)

        return sorted_nums[-k]