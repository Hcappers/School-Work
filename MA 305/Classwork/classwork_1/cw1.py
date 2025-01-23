#!/usr/bin/env python3 
"""
========================================================================
MA305 - Classwork 1: your name - date
Purpose: Evaluate F(x) = a-b*(x**3)  at N equidistant points in [0,1],
         and output the pairs (x , F(x))  on the screen and in the file 
         "out.txt" for plotting.
========================================================================
"""
# Get input from user: 
print(' Please enter the values of a, b and N:') 
a=input(' a=') 
b=input(' b=') 
N=input(' N=') 

# Print on screen: 
print('\n Thanks, will run with:  a=',a,', b=',b,', N=',N) 
print() 
print(' #   x        F(x)') 

# Change string input into number types: 
a = float(a)
b = float(b)
N = int(N)



# Open a file (out.txt) for output: 
out = open('out.txt', 'w')


# Compute F(x) = a-b*(x**3)  and print  x   F(x) 
dx = 1/(N-1)
for i in range (N):
    xi = i * dx
    Fi = a - b * (xi ** 3)
    print('{0: 0.7f} {!: 07f}'.format(xi,Fi))
    print('{0: 0.7f} {!: 07f}'.format(xi,Fi), file = out)
out.close()






# Exit: 
print('\n All Done, BYE !\n') 

