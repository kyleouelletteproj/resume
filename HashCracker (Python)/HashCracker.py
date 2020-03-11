#Program 1 by Kyle Ouellette
#CSC 3810-01
#Write a simple Python program that takes each word (string) as input from words.txt, computes the sha256 hash and compares the result to the entries in hashes.txt.

#Import hashlib to use sha256 and timeit to calculate time, string for whitespace removal
import hashlib
import time
import string

#Open the words and hashes file to read from
words = open("words.txt","r")
hashes = open("hashes.txt","r+w")
hashedWords = open("hashedwords.txt","a+r")
similarHashes = open("similarHashes.txt","a")
#Initialize the word variable to read line and strip \n
wordsLine = words.readline()
wordsLine.strip()

#Set the timer
startTime = time.time()
#Send all hashed words into a file called hashedWords
while wordsLine:
        hashedWords.write(hashlib.sha256(wordsLine).hexdigest())
        wordsLine = words.readline()
        wordsLine = wordsLine.strip()
        hashedWords.write('\n')

#Variable for matches found
matchesFound = 0;

#Set a variable for the hashed word to compare to the hashes
#Start compare loop
#Nest the loop that will iterate through all hashes each word
for hash in hashes:
#Remove the \n's and compare the hashes, and if a match is found print out that it was found and the time it was found.
	for word in hashedWords:
		hash = hash.replace("\n","")
		word = word.replace("\n","")
		if hash == word:
			similarHashes.write(word)
			similarHashes.write('\n')
			print('Match Found For Hash ',hash,'. Time Elapsed: ',time.time()-startTime)
			matchesFound+=1
#Otherwise, print that the match was not found and the time.
		else:
			print('Match Not Found. Time Elapsed: ',time.time()-startTime)
	hashedWords.seek(0)
#Print the amount of matches found
print('Matches found: ',matchesFound)
#Close the opened files
words.close()
hashes.close()
hashedwords.close()
