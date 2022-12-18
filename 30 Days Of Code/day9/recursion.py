#!/bin/python3

#Day 9 of 30 days of code, Dec 17, 2022. 

import math
import os
import random
import re
import sys

def factorial(n):
    if(n == 1): #
        return 1
    else:
        n = n * factorial(n-1)
    return n
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    result = factorial(n)

    fptr.write(str(result) + '\n')

    fptr.close()
