#!/usr/bin/env python3
import math

N = input('Enter a positve integers N: ')
N = int(N)

print('\nGeometric series: ')
sum_gs = 0
print('n \t S_n')
for n in range(N):
    sum_gs = sum_gs + 1/2 ** n
    print(n+1, '\t', sum_gs)
print()

print('\nHarmonic Series: ')
sum_hs = 0
for n in range (1,N+1):
    sum_hs = sum_hs + 1/n
    print(n, '\t' , sum_hs)
print()

print('\nAlernating series: ')
sum_as = 0
print ('n \t s_n')
for n in range(1, N+1):
    sum_as = sum_as + (-1) ** (n+1) * (1/n)
    print(n, '\t', sum_as)

print()
print('==================================')
print(' Sum of the first', n, 'terms')
print(' 1a. GS = ', sum_gs)
print(' 1b. HS = ', sum_hs)
print(' 1c. AS = ', sum_as)
print('==================================')
print()

print('     n              GS                     HS                     AS')
print('======================================================================')
sum_gs = sum_hs = sum_as = 0
for n in range(N):
    sum_gs += 1/2 ** n
    sum_hs += 1/(n +1)
    sum_as += (-1) ** (n + 2) * (1 / (n + 1))
    print('{0:6d} \t {1:20.15f} \t {2:20.15f} \t {3:20.15f}'.format(n+1, sum_gs, sum_hs, sum_as))
    print()
