#!/usr/bin/env python
import sys 
from math import log

# Machine epsilon calculation
eps = 1 
while (1+eps) != 1:
        eps = eps/2
        print(eps)
eps = 2*eps

temp=log(eps)/log(2)

print ()
print (" Machine Epsilon using Python code:")
print (" eps = ",eps, "= 2^",int(temp))
print ()





