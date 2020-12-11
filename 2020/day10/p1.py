file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

adapterSet = set()
maxVoltage = -1
for line in Lines: 
    curInt = int(line)
    adapterSet.add(curInt)
    if curInt > maxVoltage:
        maxVoltage = curInt
adapterSet.add(maxVoltage + 3)
currentVoltage = 0
numVolts = [0,0,0]
while currentVoltage != maxVoltage + 3:
    for i in range(1,4):
        if (currentVoltage + i) in adapterSet:
            currentVoltage = currentVoltage + i
            numVolts[i-1] = numVolts[i-1] + 1
            break
print (numVolts[0] * numVolts[2])   
