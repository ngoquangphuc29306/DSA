class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        cnt = 0

        for j in range(len(s)):
            for i in range(j + 1):
                dp[i][j] = (s[i] == s[j]) and (j - i <= 2 or dp[i + 1][j - 1])

                if dp[i][j]:
                    cnt += 1
        return cnt

        