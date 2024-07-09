from typing import List

def solve(a: str, b: str, i: int, j: int) -> int:
    if i == len(a):
        return 0
    if j == len(b):
        return 0
    ans = 0
    if a[i] == b[j]:
        ans = solve(a, b, i + 1, j + 1) + 1
    else:
        ans = max(solve(a, b, i + 1, j), solve(a, b, i, j + 1))
    return ans

def longestCommonSubsequence(text1: str, text2: str) -> int:
    return solve(text1, text2, 0, 0)

if __name__ == "__main__":
    S1 = "ayush"
    S2 = "ayushi"
    m = len(S1)
    n = len(S2)
    print(f"Length of LCS is {longestCommonSubsequence(S1, S2)}")

