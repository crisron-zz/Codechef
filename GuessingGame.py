#!/usr/bin/env python

from collections import Counter

minRange = 1
maxRange = 10 ** 9 + 1

t = int( raw_input() )

for i in range( t ):
    k = int( raw_input() )
    magicArray = Counter() 
    for j in range( k ):
        op, num, ans = raw_input().split()
        ans = ans.upper()
        num = int( num )
        if op == '<':
            if ans == 'YES':
                magicArray[ minRange ] += 1
                magicArray[ num ] -= 1
            else:
                magicArray[ num ] += 1
                magicArray[ maxRange ] -= 1
        elif op == '>':
            if ans == 'YES':
                magicArray[ num + 1 ] += 1
                magicArray[ maxRange ] -= 1
            if ans == 'NO':
                magicArray[ minRange ] += 1
                magicArray[ num + 1 ] -= 1
        else:
            if ans == 'YES':
                magicArray[ num ] += 1
                magicArray[ num + 1 ] -= 1
            else:
                magicArray[ minRange ] += 1
                magicArray[ num ] -= 1
                magicArray[ num + 1 ] += 1
                magicArray[ maxRange ] -= 1

    maxTruth = 0
    count = 0
    sortedArr = sorted( magicArray )
    for j in range( len( sortedArr ) ):
        count += magicArray[ sortedArr[ j ] ]
        if maxTruth < count:
            maxTruth = count
    print k - maxTruth 

