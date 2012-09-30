#!/usr/bin/env python

tgt = 0
for i in range(100, 1000):
    for j in range(100, 1000):
        temp = i*j
        #[begin:end:step], leave begin and end empty, assign step as -1, the string is reversed.
        if str(temp) == str(temp)[::-1] and temp > tgt:
            tgt = temp
print tgt

