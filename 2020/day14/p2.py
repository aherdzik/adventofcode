file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

def intToBitString(memData):
    bitResult = [0]* 36
    index = 35
    while memData >0:
        if memData % 2 == 1:
            bitResult[index] = 1
        memData= int(memData / 2)
        index = index -1 
    return bitResult
    
def bitStringToInt(masked):
    toReturn = 0
    for i in range(36):
        if masked[35-i] == 1:
            toReturn = toReturn + (2 ** i)
    return toReturn

def applyMaskHelper(memBitString, currentMask, start):
    for i in range(start, len(currentMask)):
        if currentMask[i] == "1":
            memBitString[i] = 1
        elif currentMask[i] == "X":
            zeroClone = list(memBitString)
            oneClone = list(memBitString)
            zeroClone[i] = 0
            oneClone[i] = 1
            return applyMaskHelper(zeroClone, list(currentMask), i+1) | applyMaskHelper(oneClone, list(currentMask), i+1)
    return {bitStringToInt(memBitString)}
    
def getAddressesForAddressAndMask(memAddress, currentMask):
    memBitString = intToBitString(memAddress)
    return applyMaskHelper(memBitString, currentMask, 0)

currentData = dict()
currentMask = []
for line in Lines: 
    if line[:7] == "mask = ":
        line = line[7:]
        currentMask = []
        for char in line:
            if char == "0" or char == "1" or char == "X":
                currentMask.append(char)
    else:
        line = line[4:]
        memAddress = int(line[:int(line.find(']'))])
        line = line[int(line.find('= ')+2):]
        memData = int(line)
        addressesToAdd = getAddressesForAddressAndMask(memAddress, currentMask)
        for adr in addressesToAdd:
            currentData[adr] = memData
        
totalSum = 0
for item in currentData.items():
    totalSum = totalSum + item[1]
    
print(totalSum)