#!/usr/bin/env python3

def Converter(c):
    return (9/5) * c + 32

celsius = [-40, 0, 30, 100]

for c in celsius:
    F = Converter(c)
    print(f'The converted Celsius: {c} to Fahrenheit is: {F}')
