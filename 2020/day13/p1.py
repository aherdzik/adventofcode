file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

def findMods(busNums, numToCheck):
    for i in busNums:
        if numToCheck % i == 0:
            return i
    return -1


timestamp = int(Lines[0])
splitNums = Lines[1].split(",")
busNums = set()
for line in splitNums: 
    if line != "x":
        busNums.add(int(line))
 
timestampIter = timestamp 
result = findMods(busNums, timestampIter)

while result == -1:
    timestampIter = timestampIter + 1
    result = findMods(busNums, timestampIter)

print(result * (timestampIter-timestamp ))
