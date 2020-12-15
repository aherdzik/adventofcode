file1 = open('input.txt', 'r') 

lastTimeNumberCalledMap, currentIndex, lastNumUsed= dict(), 1,0

def playGame(lastTimeNumberCalledMap, currentIndex, lastNumUsed):
    if lastNumUsed not in lastTimeNumberCalledMap.keys():
        lastTimeNumberCalledMap[lastNumUsed] = currentIndex
        return 0
    else:
        diff = currentIndex - lastTimeNumberCalledMap[lastNumUsed]
        lastTimeNumberCalledMap[lastNumUsed] = currentIndex
        return diff

lastNumUsed = 0
for line in file1.readlines() : 
    commaSplit = line.split(',')
    for num in commaSplit:   
        curNum = int(num)
        lastNumUsed = playGame(lastTimeNumberCalledMap, currentIndex, curNum)
        currentIndex = currentIndex + 1
        
while currentIndex < 30000000:
    lastNumUsed = playGame(lastTimeNumberCalledMap,currentIndex, lastNumUsed)
    currentIndex = currentIndex + 1
print(lastNumUsed)
