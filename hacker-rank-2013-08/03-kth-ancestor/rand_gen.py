#!/usr/bin/env python

import random

MAX_VAL = 10**5

RANGE_T = (1, 3)
RANGE_P = (1, MAX_VAL)
RANGE_Q = (1, MAX_VAL)
RANGE_X = (1, MAX_VAL)
RANGE_Y = (1, MAX_VAL)
RANGE_K = (1, MAX_VAL)
RANGE_ACT = (0, 2)

def get_rand(rangeTuple):
	return random.randint(rangeTuple[0], rangeTuple[1])

T = get_rand(RANGE_T)
print T

for t in xrange(T):
	P = get_rand(RANGE_P)
	print P
	NODE_RANGE = [1, P]
	rootValue = get_rand(NODE_RANGE)
	nodes = {}
	paths = {}
	parentOf = {}
	numChildren = {}
	print rootValue, 0
	nodes[rootValue] = 1
	while len(nodes) < P:
		v1, v2 = get_rand(NODE_RANGE), get_rand(NODE_RANGE)
		if v1 == v2: continue
		if v1 > v2: v1, v2 = v2, v1
		key = (v1, v2)
		if not paths.has_key(key):
			paths[key] = 1
			if len(nodes) == P - 1:
				if not (nodes.has_key(v1) or nodes.has_key(v2)):
					continue
				nodes[v1] = 1
				nodes[v2] = 1
				print v1, v2
			else:
				nodes[v1] = 1
				nodes[v2] = 1
				print v1, v2
	Q = get_rand(RANGE_Q)
	print Q
	for q in xrange(Q):
		action = random.choice([0, 0, 0, 1, 2, 2, 2, 2])
		if action == 0:
			parent = random.choice(list(nodes.keys()))
			child = parent
			while nodes.has_key(child):
				child = get_rand(RANGE_P)
			nodes[child] = 1
			print action, parent, child
		elif action == 1:
			nodeValue = rootValue
			while nodeValue == rootValue:
				nodeValue = random.choice(list(nodes.keys()))
				del nodes[nodeValue]
				print action, nodeValue
		elif action == 2:
			child = get_rand(RANGE_P)
			k = get_rand(RANGE_K)
			print action, child, k

