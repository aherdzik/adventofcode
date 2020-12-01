file1 = open('input.txt', 'r') 
Lines = file1.readlines() 
  
count = 0
newSet = set()
# Strips the newline character 
for line in Lines: 
    newSet.add(int(line))
    

for val1 in newSet:
    if val1 >= 2020:
        continue
    for val2 in newSet:
        reverse = 2020- val1- val2
        if reverse <=0:
            continue
        if reverse in newSet:
            print(val1*val2*reverse)
