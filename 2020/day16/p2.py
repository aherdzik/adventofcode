file1 = open('input.txt', 'r') 

level = 1
def parseOutNumberRanges(numRange):
    toReturn = []
    firstPart = []
    for i in numRange[:numRange.find("or")-1].split('-'):
        firstPart.append(int(i))
    toReturn.append(firstPart)
    secondPart = []
    for i in numRange[numRange.find("or")+3:].split('-'):
        secondPart.append(int(i))
    toReturn.append(secondPart)
    return toReturn

def commaSeparatedIntsToArray(line):
    toReturn = []
    for i in line.split(','):
        toReturn.append(int(i))
    return toReturn
    
ticketValues, myTicket, otherTickets, level = dict(),[],[],1
for line in file1.readlines(): 
    if level == 1 and line.startswith("your ticket"):
        level = 2
    elif level == 1 and len(line) >2:
        key = line[0:line.find(':')]
        ticketValues[key] = parseOutNumberRanges(line[line.find(':')+2:])
    elif level == 2:
        myTicket = commaSeparatedIntsToArray(line)
        level = 3
    elif level == 3 and line.startswith("nearby ticket"):
        level = 4
    elif level == 4:
        otherTickets.append(commaSeparatedIntsToArray(line))
        level = 4

#invalid ticket removal
ticketsToRemove = []
for otherTicketIndex in range(len(otherTickets)):
    added = False
    for ticketVal in otherTickets[otherTicketIndex]:
        foundMatch = False
        for validRanges in ticketValues.values():
            for curRange in validRanges:
                if ticketVal in range(curRange[0], curRange[1] +1):
                    foundMatch = True
                    break
            if foundMatch:
                break
        if not foundMatch:
            added = True
            ticketsToRemove.insert(0,otherTicketIndex)
        if added:
            break           
for toRemove in ticketsToRemove:
    del otherTickets[toRemove]  

#find viable pairings            
keysFound = dict()
for ticketValues in ticketValues.items():
    ranges = ticketValues[1]
    keysFound[ticketValues[0]] = []
    for i in range(len(otherTickets[0])):
        matches = True
        for otherTicket in otherTickets:
            if otherTicket[i] not in range(ranges[0][0],ranges[0][1]+1) and otherTicket[i] not in range(ranges[1][0],ranges[1][1]+1):
                matches = False
                break
        if matches:
            keysFound[ticketValues[0]].append(i)
           
#find actual pairings          
wordToNum = dict()                  
while len(keysFound) > 0:
    for key in keysFound:
        if len(keysFound[key]) == 1:
            foundVal = keysFound[key][0]
            for restOfKey in keysFound:
                keysFound[restOfKey].remove(foundVal)
            wordToNum[foundVal] = key
            del keysFound[key]
            break

#calculate solution   
total = 1
for val in wordToNum.items():
    if val[1].startswith("departure"):
        total = total * myTicket[val[0]]
print(total)
