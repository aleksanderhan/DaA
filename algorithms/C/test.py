from time import time
import math_tools as mt


a = 1234567890123
b = 9876543210123
t1 = time()
c = a*b
t2 = time()
print c
t3 = time()
d = mt.KaratsubaMult(a, b)
t34 = time()
print d

print c == d
print t2-t1
print t4-t3