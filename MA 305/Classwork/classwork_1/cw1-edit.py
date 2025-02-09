#!/usr/bin/env python3
"""
========================================================================
MA305 − Classwork 1 : your name − dat e
Purpose : To e v a l u a t e F( x ) = a−b ∗ ( x ∗∗ 3) a t N e q u i d i s t a n t p o i n t s i n [ 0 , 1 ] ,
and output th e p a i r s ( x , F( x ) ) on th e s c r e e n and i n th e f i l e
" out . t x t " f o r p l o t t i n g .
========================================================================
"""
# Get i n p u t from u s e r :
print('Please enter the values of a , b and N:')
a = input('a = ')
b = input('b = ')
N = input('N = ')

# Print on screen:
print()
print('\n Thanks , will run with : a = ' , a , ' , b = ' , b , ' , N = ' , N)
print()
print('# x F(x)')

# Change string input into number types:
a = float(a)
b = float(b)
N = int(N)

# Open a file (out.txt) for output :
out = open('out.t x t','w')
print('# x F( x )' , file = out)

# Compute F( x ) = a − b ∗ ( x ∗∗ 3) and print x F(x)
dx = (1 / (N - 1))
for i in range (N):
    xi = i * dx    
    Fi = a - b * xi ** 3
    print('{0:0.7f} {1:0.7f}'.format(xi, Fi))
    print('{0:0.7f} {1:0.7f}'.format(xi, Fi), file = out)
out.close()

# Exit:
print('\n All Done , BYE ! \n ' )
