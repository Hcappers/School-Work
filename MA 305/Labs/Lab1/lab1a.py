#!/usr/bin/env python3
import math

r1 = 100
r2 = 200
r3 = 300

R = (1 / ((1/r1) + (1/r2) + (1/r3)))
print('The total resistance of the three resistors  R1:', r1, ' R2:', r2, ' R3:', r3, 'is R:', R)
print()

p = 10000
r = 0.08
k = 4
t = 20

A = p * (1 + (r / k)) ** (k * t)
print('The future amount with a Principal starting with: ', p, ' is A: ', A)
print()

a = 6
b = 8
c = 10
s = ((1/2) * (a + b + c))

Area = math.sqrt(s * (s - a) * (s - b) * (s - c))
print('The area of the triangle with sides a:', a, ' b:', b, ' c:', c, 'is A:', Area)
print()

radius = -0.3
theta = ((3 * math.pi) / 4)
y = ((math.e ** radius) * math.cos(theta) + (math.e ** (2 * radius)) * math.sin(2 * theta))
print('The value for y for the function is: ', y)
print()
