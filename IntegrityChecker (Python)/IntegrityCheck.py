#Kyle Ouellette
#CSC 3810
#2/12/20
#Write a Python program that:

#1. Checks for the presence of a file in its running directory named 'integrity.txt'. If present, read the value (a hash) from the file into memory.
#2. Generate the hash (use hashlib again) of a filesystem object (see below). Use sha256 for the algorithm.
#3. If the file exists in step 1, compare the value read from file (if exists) to the generated hash. If they match, output a message stating such. If they don't match, output a warning message.
#4. Otherwise, if the integrity file didn't exist in step #1, stores the generated hash in a plain text named, integrity.

import os.path
from os import path
import hashlib

#Check if there is a file named "integrity.txt

if path.exists("integrity.txt"):
	integFile = open("integrity.txt", "r")
	fileVal = integFile.read()
	fileHash = hashlib.sha256(fileVal).hexdigest()
	integFile.seek(0)
	fileLine = integFile.readline()
	contentHash = hashlib.sha256(fileLine).hexdigest()
	if fileHash == contentHash:
		print("Hashes match")
#If the hashes do not match, print out that there was an error.
	else:
		print("Error. Hashes do not match")
#If there was no file named "integrity.txt", create a new file called "integrity.txt" and store its hash inside of it.
else:
	integFile = open("integrity.txt", "w+")
	fileVal = integFile.read()
	fileVal.strip()
	integFile.write(hashlib.sha256(fileVal).hexdigest())	
