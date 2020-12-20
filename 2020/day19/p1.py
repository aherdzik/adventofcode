file1 = open('input.txt', 'r') 

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

def getAllSetCombos(set1, set2):
    totalset= set()
    for str1 in set1:
        for str2 in set2:
            totalset.add(str1 + str2)
    return totalset
    
def appendToSetList(nums, sets, keyToRules):
    if len(nums) == 1:
        sets.append(getStringCombosForSet(keyToRules[nums[0]], keyToRules))
    elif len(nums) == 2:
        sets.append(getAllSetCombos(getStringCombosForSet(keyToRules[nums[0]], keyToRules), getStringCombosForSet(keyToRules[nums[1]], keyToRules)))
    else:
        print("ERROR TOO MANY NUMS")

def getStringCombosForSet(ruleString, keyToRules):
    if ruleString[0] == "\"":
        return set(ruleString.replace("\"",""))
        
    nums = []
    sets = []
    while len(ruleString) > 0:
        if ruleString[0].isdigit():
            if ruleString.find(" ") == -1:
                nums.append(int(ruleString))
                ruleString = ""
            else:
                nums.append(int(ruleString[:ruleString.find(" ")]))
                ruleString= ruleString[ruleString.find(" ")+1:]
        elif ruleString[0] == "|":
            appendToSetList(nums, sets, keyToRules)
            nums = []
            ruleString = ruleString[2:]
            
    appendToSetList(nums, sets, keyToRules)

    finishedSets = set()
    for curSet in sets:
        finishedSets = finishedSets | curSet
    return finishedSets
    

mainSet = getStringCombosForSet(keyToRules[0], keyToRules)
total = 0
for data in dataset:
    if data in mainSet:
        total = total +1
        
print(total)

    
