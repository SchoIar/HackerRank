num = int(input())

phoneBook = {}

#getting all data
for i in range(0, num):
    entry = str(input()).split(" ")
    name = entry[0]
    phoneNumber = int(entry[1])
    phoneBook[name] = phoneNumber

#printing all found matches: 