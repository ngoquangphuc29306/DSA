class Solution:
    def floodFill(self, image: list[list[int]], sr: int, sc: int, color: int) -> list[list[int]]:
        org_color = image[sr][sc]

        if org_color == color:
            return image

        m, n = len(image), len(image[0])

        def dfs(r: int, c: int):
            if r >= m or r < 0 or c < 0 or c >= n or image[r][c] != org_color:
                return

            image[r][c] = color

            dfs(r - 1, c)
            dfs(r + 1, c)
            dfs(r, c - 1)
            dfs(r, c + 1)

        dfs(sr, sc)
        return image

            