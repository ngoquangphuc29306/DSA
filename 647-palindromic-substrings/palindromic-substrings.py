class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [False] * n
        cnt = 0

        for j in range(len(s)):
            for i in range(j + 1):
                dp[i] = s[i] == s[j] and (j - i <= 2 or dp[i + 1])

                if dp[i]:
                    cnt += 1
        return cnt

        