# Author: KurbyDoo
# Creation Date: Jul 19, 2025
# Problem Link: https://dmoj.ca/problem/ccc04j4
# Problem Name: CCC '04 J4 - Simple Encryption
# Status: Solved
# Notes:
#     Original creation date unknown
#     
#     
#     
import sys, re
regex = re.compile('[^a-zA-Z]')
key = sys.stdin.readline().strip().lower()
text = regex.sub('', sys.stdin.readline().lower())

alphabet = "abcdefghijklmnopqrstuvwxyz"

new_text = ""
for i, item in enumerate(text):
    shift = alphabet.index(key[i%len(key)])
    current = alphabet.index(item)
    new_text += alphabet[(shift + current)%26]

print(new_text.upper())