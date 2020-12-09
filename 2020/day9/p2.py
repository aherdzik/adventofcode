file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

def sumOfArray(array):
    total = 0
    for i in array:
        total = total + i
    return total


def getLargestAndSmallestInArray(arrayTesting):
    smallest = 9999999999999999999
    largest = -1
    for i in arrayTesting:
        if i < smallest:
            smallest = i
        if i > largest: 
            largest = i
    return (smallest + largest)

def evalForContiguousSum(curNum, totalBuffer):
    for groupSize in range(1,len(totalBuffer)):
        for startElement in range(len(totalBuffer)-groupSize+1):
            arrayTesting = totalBuffer[startElement:startElement+groupSize]
            sumResult = sumOfArray(arrayTesting)
            if sumResult == curNum:
                return getLargestAndSmallestInArray(arrayTesting)
    print("failed")   
    return -1

currentBuffer = []
totalBuffer = []
preambleSize = 26
for line in Lines: 
    currentBuffer.append(int(line))
    totalBuffer.append(int(line))
    if (len(currentBuffer) > preambleSize):
        currentBuffer.pop(0)
        curSum = currentBuffer[preambleSize-1]
        checkSet = set()
        foundSum = False
        for i in range(len(currentBuffer)-1):
            if (curSum - currentBuffer[i]) in checkSet:
                foundSum = True
                break
            checkSet.add(currentBuffer[i])
        if foundSum == False:
            print(evalForContiguousSum(curSum, totalBuffer[:len(totalBuffer)-1]))
            break  
    