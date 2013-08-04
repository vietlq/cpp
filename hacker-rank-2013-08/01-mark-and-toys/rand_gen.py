#!/usr/bin/env python

import random

RANGE_N = (1, 10**5)
RANGE_K = (1, 10**9)
RANGE_P = (1, 10**9)

N = random.randint(RANGE_N[0], RANGE_N[1])
K = random.randint(RANGE_K[0], RANGE_K[1])
print N, K
for i in xrange(N):
	print random.randint(RANGE_P[0], RANGE_P[1])

