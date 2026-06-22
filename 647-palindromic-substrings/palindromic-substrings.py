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
            for i in range(len(s)):
                if i <= j:
                    if s[i] == s[j]:
                        if (j - i <= 2):
                            dp[i][j] = True
                        else:
                            dp[i][j] = dp[i + 1][j - 1]

                    if dp[i][j]:
                        cnt += 1
        return cnt

        