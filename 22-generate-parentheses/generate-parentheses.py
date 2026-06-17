class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        slots = n * 2
        # Recursive
        def generate(sofar = [""]):
            if len(sofar[0]) == slots:
                return sofar

            L = []
            for paren in sofar:
                L.append(paren + "(")
                L.append(paren + ")")
            return generate(L)

        L = generate()

        def is_valid(paren):
            op = 0
            for c in paren:
                if c == "(":
                    op += 1
                else:
                    if op == 0:
                        return False
                    else:
                        op -= 1
            return op == 0
        
        ans = []
        for paren in L:
            if is_valid(paren):
                ans.append(paren)

        return ans


