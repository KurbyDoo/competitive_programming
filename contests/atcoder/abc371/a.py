a, b, c = input().split()

if a == '<' and b == '>':
  print("A")

elif a == '>' and b == '<':
  print("A")

elif b == '<' and c == '>':
  print("C")

elif b == '>' and c == '<':
  print("C")

if a == '<' and c == '<':
  print("B")

elif a == '>' and c == '>':
  print("B")
