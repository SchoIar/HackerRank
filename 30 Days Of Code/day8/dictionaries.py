num = int(input())

phoneBook = {}

#getting all data
for i in range(0, num):
    entry = str(input()).split(" ")
    name = entry[0]
    phoneNumber = int(entry[1])
    phoneBook[name] = phoneNumber

#TODO:Figure out a way to check for a newline, if found, exit the program. 
nameSearch = input()
for line in nameSearch:
    if line == '\n':
        exit(1)


