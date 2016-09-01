#!/usr/bin/env python

# Problem Link: https://www.codechef.com/problems/MARCHAX

n = int( raw_input() )
m = int( raw_input() )

edge = 2 ** n
mines = [ 0 ] * edge
for i in range( m ):
    line = raw_input()
    x = int( line.strip().split()[ 0 ] )
    mines[ x ] = 1

print mines.count( 0 )
for i in range( edge ):
    if not mines[ i ]:
        print i, 0

