file1 = open('input2.txt', 'r') 
Lines = file1.readlines() 
#more than 1523448607262
#3278997609887
def arrAsString(arr):
    toPrint= ""
    for i in arr:
        toPrint+= str(i)
    print(toPrint)

def intToBitString(memData):
    bitResult = [0]* 36
    index = 35
    while memData >0:
        if memData % 2 == 1:
            bitResult[index] = 1
        memData= memData / 2
        index = index -1 
    return bitResult
    
def bitStringToInt(masked):
    toReturn = 0
    for i in range(36):
        if masked[35-i] == 1:
            toReturn = toReturn + (2 ** i)
    return toReturn

def applyMaskHelper(memBitString, currentMask):
    numsToReturn = set()
    for i in range(len(currentMask)):
        if currentMask[i] == "1":
            memBitString[i] = 1
        elif currentMask[i] == "X":
            currentMask[i] = "0"
            zeroClone = list(memBitString)
            oneClone = list(memBitString)
            zeroClone[i] = 0
            oneClone[i] = 1
            numsToReturn = numsToReturn| applyMaskHelper(zeroClone, list(currentMask))
            numsToReturn = numsToReturn| applyMaskHelper(oneClone, list(currentMask))
            return numsToReturn
    numsToReturn.add(bitStringToInt(memBitString))
    arrAsString(memBitString)
    return numsToReturn   
    
def getAddressesForAddressAndMask(memAddress, currentMask):
    memBitString = intToBitString(memAddress)
    mainSet = set()
    mainSet = mainSet | applyMaskHelper(memBitString, currentMask)
    return mainSet

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