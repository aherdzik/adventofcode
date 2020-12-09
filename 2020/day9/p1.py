file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

currentBuffer = []
preambleSize = 26
for line in Lines: 
    currentBuffer.append(int(line))
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
            print(curSum)
            break
        
        
    