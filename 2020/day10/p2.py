file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

adapterSet = set()
adapterSet.add(0)
maxVoltage = -1
for line in Lines: 
    curInt = int(line)
    adapterSet.add(curInt)
    if curInt > maxVoltage:
        maxVoltage = curInt
adapterSet.add(maxVoltage + 3)

combinationDict = dict()
for currentVoltage in range(1, maxVoltage + 4):
    if currentVoltage not in adapterSet:
        continue
    totalCombo = 0
    for i in range(1,4):
        if (currentVoltage - i) in adapterSet:
            if currentVoltage - i == 0:
                 totalCombo = totalCombo+1
            elif currentVoltage - i in combinationDict:
                totalCombo = totalCombo + combinationDict[currentVoltage - i]   
    combinationDict[currentVoltage] = totalCombo
            
print (combinationDict[maxVoltage + 3])   
