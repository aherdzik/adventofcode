file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

timestamp = int(Lines[0])
splitNums = Lines[1].split(",")
busData = dict()
for line in range(len(splitNums)): 
    if splitNums[line] != "x":
        busData[line] = int(splitNums[line])
        
currentNum = 0
step = 0
for k in busData.items():
    if currentNum == 0:
        currentNum = k[0] + k[1]
        step = k[1]
    else:
        while (currentNum + k[0]) % k[1] != 0:
            print(currentNum , k[1], currentNum + k[0] % k[1] )
            currentNum = currentNum + step
        step = step * k[1]
print(currentNum)
