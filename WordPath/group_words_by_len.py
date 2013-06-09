#!/usr/bin/env python

import sys, os

inputFh = sys.stdin

if len(sys.argv) > 1:
	inputFilePath = sys.argv[1]
	if os.path.isfile(inputFilePath):
		try:
			inputFh = open(inputFilePath, 'rb')
		except:
			print >>sys.stderr, "Couldn't open the file for reading: `%s`" % inputFilePath
			os._exit(-1)
	else:
		print >>sys.stderr, "The file does not exist: `%s`" % inputFilePath
		os._exit(-1)

uniqueWords = {}
wordsByLen = {}

def group_by_len(word):
	theLen = len(word)
	if not wordsByLen.has_key(theLen):
		wordsByLen[theLen] = []
	wordsByLen[theLen].append(word)
	return word

def add_unique_word(word):
	uniqueWords[word] = 1
	return word

genWords = (line.strip() for line in inputFh)
genLowerCaseWords = (word.lower() for word in genWords)
genUniqueWords = (add_unique_word(word) for word in genLowerCaseWords if not uniqueWords.has_key(word))
genWordsByLen = (group_by_len(word) for word in genUniqueWords)

for word in genWordsByLen:
	pass

for wordLen, words in wordsByLen.items():
	fileName = 'words_len_%d.txt' % wordLen
	tempFh = open(fileName, 'wb')
	for word in words:
		tempFh.write(word + '\n')
	tempFh.close()
