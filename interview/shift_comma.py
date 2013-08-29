#!/usr/bin/env python

inputStr = list('1,234,34,54')
print ''.join(inputStr)
TOTAL_LEN = len(inputStr)
firstComma = 0
firstNonComma = 0
commaLen = 0
while max(firstComma, firstNonComma) < TOTAL_LEN:
	if commaLen < 1:
		while (firstComma < TOTAL_LEN) and (inputStr[firstComma] != ','):
			firstComma += 1
		firstNonComma = firstComma + 1
	while (firstNonComma < TOTAL_LEN) and (inputStr[firstNonComma] == ','):
		firstNonComma += 1
	commaLen = firstNonComma - firstComma
	if firstNonComma >= TOTAL_LEN: break
	nextComma = firstNonComma + 1
	while (nextComma < TOTAL_LEN) and (inputStr[nextComma] != ','):
		nextComma += 1
	wordLen = nextComma - firstNonComma
	for idx in xrange(wordLen):
		inputStr[firstComma + idx] = inputStr[firstNonComma + idx]
	for idx in xrange(commaLen):
		inputStr[firstComma + wordLen + idx] = ','
	firstComma += wordLen
	firstNonComma += wordLen
	wordLen = 0

print ''.join(inputStr)

