file1 = open('input2.txt', 'r') 

keyToRules = dict()
dataset= set()
readingInKeys = True
for line in file1.readlines():
    line = line.replace("\n","")
    if line == "":
        readingInKeys = False
        continue
    if readingInKeys:
        intsize = line.find(":")
        dictKey = int(line[:intsize])
        keyToRules[dictKey] = line[intsize+2:]
    else:
        dataset.add(line)
print(keyToRules)
print(dataset)
    
