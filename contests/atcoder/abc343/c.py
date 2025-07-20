
def check_palindrome(s: str) -> bool:
  for i in range(len(s) // 2):
    if s[i] != s[-i - 1]: return False

  return True

n = int(input())
for i in range(int(1000010), 0, -1):
  if i ** 3 <= n and check_palindrome(str(i ** 3)):
    print(i ** 3)
    break