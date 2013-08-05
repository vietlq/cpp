#!/usr/bin/env python

import random

MAX_VAL = 10**2

RANGE_T = (1, 3)
RANGE_P = (1, MAX_VAL)
RANGE_Q = (1, MAX_VAL)
RANGE_X = (1, MAX_VAL)
RANGE_Y = (1, MAX_VAL)
RANGE_K = (1, MAX_VAL)
RANGE_ACT = (0, 2)

def get_rand(rangeTuple):
	return random.randint(rangeTuple[0], rangeTuple[1])

def join_nodes(nodeValue, unmappedNodes, visited, parentOf, numChildren):
	if visited[nodeValue]: return
	visited[nodeValue] = 1
	for childValue in unmappedNodes[nodeValue]:
		if visited[childValue]: continue
		join_nodes(childValue, unmappedNodes, visited, parentOf, numChildren)
		parentOf[childValue] = nodeValue
		numChildren[nodeValue] += 1

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
	unmappedNodes = {}
	visited = {}
	leafNodes = {}
	print rootValue, 0
	nodes[rootValue] = 1
	while len(nodes) < P:
		v1, v2 = get_rand(NODE_RANGE), get_rand(NODE_RANGE)
		if v1 == v2: continue
		if v1 > v2: v1, v2 = v2, v1
		key = (v1, v2)
		if not paths.has_key(key):
			if (len(nodes) < P - 1) or ((len(nodes) == P - 1) and (nodes.has_key(v1) != nodes.has_key(v2))):
				nodes[v1] = 1
				nodes[v2] = 1
				print v1, v2
			else: continue
			paths[key] = 1
			if unmappedNodes.has_key(v1):
				unmappedNodes[v1].append(v2)
			else:
				unmappedNodes[v1] = [v2]
			if unmappedNodes.has_key(v2):
				unmappedNodes[v2].append(v1)
			else:
				unmappedNodes[v2] = [v1]
	#
	for v in unmappedNodes.keys(): visited[v], numChildren[v] = 0, 0
	#
	join_nodes(rootValue, unmappedNodes, visited, parentOf, numChildren)
	#
	for key, value in numChildren.items():
		nodes[key] = 1
		if value == 0:
			leafNodes[key] = 1
	#
	print 'numChildren = ', numChildren
	print 'parentOf = ', parentOf
	print 'leafNodes = ', sorted(leafNodes.keys())
	# 
	Q = get_rand(RANGE_Q)
	print Q
	for q in xrange(Q):
		action = random.choice([0, 0, 0, 1, 2, 2, 2, 2])
		if action == 0:
			parent = random.choice(list(parentOf.keys()))
			child = parent
			while parentOf.has_key(child):
				child = get_rand(RANGE_P)
			print action, parent, child
			nodes[child] = 1
			parentOf[child] = parent
			leafNodes[child] = 1
			if numChildren.has_key(parent):
				numChildren[parent] += 1
			else:
				numChildren[parent] = 1
			if leafNodes.has_key(parent):
				del leafNodes[parent]
		elif action == 1:
			nodeValue = rootValue
			while nodeValue == rootValue:
				nodeValue = random.choice(list(leafNodes.keys()))
				print action, nodeValue
				parentValue = parentOf[nodeValue]
				numChildren[parentValue] -= 1
				del nodes[nodeValue]
				del leafNodes[nodeValue]
				if numChildren[parentValue] == 0:
					leafNodes[parentValue] = 1
		elif action == 2:
			child = get_rand(RANGE_P)
			k = get_rand(RANGE_K)
			print action, child, k

