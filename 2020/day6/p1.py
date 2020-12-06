file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

usableChars = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}

count = 0
currentSet = set()
firstLine = True

for line in Lines: 
    if line == "\n":
        count = count + len(currentSet)
        currentSet = set()
        firstLine = True
        continue
    newSet = set()
    for char in line:
        if char in usableChars:
            if firstLine == True:
                currentSet.add(char)
            else:
                newSet.add(char)
                
    if firstLine == True:
        firstLine = False   
        continue
    finalset = set()
    for char in usableChars:
        if (char in currentSet) and (char in newSet):
            finalset.add(char)
    currentSet = finalset
    firstLine = False    
      
count = count + len(currentSet)
print count