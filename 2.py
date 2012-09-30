#!/usr/bin/env python

LIMIT = 4000000

def fib(limit):
    counter = 0
    cache = [1, 2]
    while True:
        if counter == len(cache):
            cache.append(cache[counter - 1] + cache[counter - 2])
        if cache[counter] > limit:
            return
        yield cache[counter]
        counter += 1

if __name__ == '__main__':
    print sum([ x for x in fib(LIMIT) if x % 2 == 0])
