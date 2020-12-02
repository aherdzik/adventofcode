file1 = open('input.txt', 'r') 
Lines = file1.readlines() 
  
count = 0
for line in Lines: 
        preLine = line
        firstBlock = line.find('-')
        firstNum = int(line[:firstBlock])
        line = line[firstBlock+1:]
        secondBlock = line.find(' ')
        secondNum = int(line[:secondBlock])
        line = line[secondBlock+1:]
        searchChar = line[0]
        line = line[line.find(' ')+1:]
        line = line[firstNum-1] + line[secondNum-1]
        currentCount = 0
        for i in line:
            if i == searchChar:
                currentCount = currentCount + 1
        if currentCount == 1:
            count = count+ 1
print(count)
    