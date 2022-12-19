num = int(input())

phoneBook = {}

#getting all data
for i in range(0, num):
    entry = str(input()).split(" ")
    name = entry[0]
    phoneNumber = int(entry[1])
    phoneBook[name] = phoneNumber

#TODO:Figure out a way to check for a newline, if found, exit the program. 
while True:
    try:
        queery = input()
        if queery in phoneBook:
            print(str(queery) + "=" + str(phoneBook[queery]))
        else:
            print("Not found")
    except:
        break

