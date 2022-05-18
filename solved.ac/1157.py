import sys
import string

bucket = [0] * 26
code = sys.stdin.readline().rstrip().lower()
ascii_lowercase = string.ascii_lowercase
ascii_uppercase = string.ascii_uppercase

for s in code:
    bucket[ascii_lowercase.index(s)] += 1

max_ascii = max(bucket)
if len([i for i, v in enumerate(bucket) if v == max_ascii]) > 1:
    print('?')
else:
    print(ascii_uppercase[bucket.index(max_ascii)])
