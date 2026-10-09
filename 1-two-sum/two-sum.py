class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        count = {}

        for i, num in enumerate(nums):
            need = target - num

            if need in count:
                return [count[need], i]
            count[num] = i

        return []