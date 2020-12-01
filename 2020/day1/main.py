file1 = open('input.txt', 'r') 
Lines = file1.readlines() 
  
count = 0
newSet = set()
# Strips the newline character 
for line in Lines: 
    curInt = int(line)
    reverse = 2020 - curInt
    if reverse in newSet:
        print(curInt * reverse)
        break
    else:
        newSet.add(curInt)
    