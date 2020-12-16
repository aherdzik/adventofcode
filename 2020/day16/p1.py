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

ticketScanningErrorRate = 0
for otherTicket in otherTickets:
    for ticketVal in otherTicket:
        foundMatch = False
        for validRanges in ticketValues.values():
            for curRange in validRanges:
                if ticketVal in range(curRange[0], curRange[1] +1):
                    foundMatch = True
                    break
            if foundMatch:
                break
        if not foundMatch:
            ticketScanningErrorRate = ticketScanningErrorRate + ticketVal
            
print(ticketScanningErrorRate)         
