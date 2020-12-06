file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

def getRecurseHelper(str, low, high):
    if low == high:
        return low
    
    pivotPoint = (low + high) /2 
    if str[0] == 'F' or str[0] == 'L':
        return getRecurseHelper(str[1:], low, pivotPoint)
    elif str[0] == 'B' or str[0] == 'R':
        return getRecurseHelper(str[1:], pivotPoint + 1, high)
    else:
        print("FAILURE")
        return -1

def getRowNum(str):
    return getRecurseHelper(str, 0, 127)

def getSeatNum(str):
    return getRecurseHelper(str, 0, 7)

receivedNumbers = set()
possibleSeats = set()

for line in Lines: 
    row = getRowNum(line[:7])
    col = getSeatNum(line[7:])
    result = (row * 8) + col
    receivedNumbers.add(result)
    possibleSeats.discard(result)
    if (result + 2 in receivedNumbers) and result + 1 not in receivedNumbers:
        possibleSeats.add(result + 1)
    if (result - 2 in receivedNumbers) and result - 1 not in receivedNumbers:
        possibleSeats.add(result - 1)
        
for num in possibleSeats:
    print("POSSIBLE SEAT", num)
        