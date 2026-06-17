class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ans = []
        # Recursive
        def generate(sofar = "", op = 0, cl = 0):
            if op > n: return
            if cl > op: return
            if cl == op == n:
                ans.append(sofar)
            generate(sofar + "(", op + 1, cl)
            generate(sofar + ")", op, cl + 1)
        generate()
        return ans
