s, o = list(input()), "YES"
a = True if s[0] in "aeiou" else False
for c in s:
    if (c in list("aeiou")) == a: a = False if a else True
    else: o = "NO"
print(o)
    
