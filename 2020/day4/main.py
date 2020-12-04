file1 = open('input.txt', 'r') 
Lines = file1.readlines()   
acceptedValues = {"byr","iyr","eyr","hgt","hcl","ecl","pid"}

def evalSet(currentSet):
    for accepted in acceptedValues:
        if accepted not in currentSet:
            return False
    return True
    
def verifyString(str):
    prefixString = str[0:3]
    val = str[4:]
    if val[-1:] == "\n":
        val = val[:-1]
    if prefixString == "byr":
        bYear = int(val)
        return len(val) == 4 and bYear >=1920 and bYear <=2002
    elif prefixString == "iyr":
        iYear = int(val)
        return len(val) == 4 and iYear >=2010 and iYear <=2020
    elif prefixString == "eyr":
        eYear = int(val)
        return len(val) == 4 and eYear >=2020 and eYear <=2030
    elif prefixString == "hgt":
        cmOrIn = val[-2:]
        if cmOrIn == "cm":
            numVal = int(val[:-2])
            return numVal>=150 and numVal <=193
        elif cmOrIn == "in":
            numVal = int(val[:-2])
            return numVal>=59 and numVal <=76
    elif prefixString == "hcl":
        if val[0] != "#":
            return False
        validChars = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'}
        for char in val[1:]:
            if char not in validChars:
                return False
        return len(val) == 7
    elif prefixString == "ecl":
        return val in {"amb","blu","brn","gry","grn","hzl","oth"}
    elif prefixString == "pid":
        validChars = {'0','1','2','3','4','5','6','7','8','9'}
        for char in val:
            if char not in validChars:
                return False
        return len(val) == 9
    return False
  
def runIt():  
    currentSet = set()
    count = 0
    for line in Lines: 
        vals = line.split(" ")
        for val in vals:
            if verifyString(val):  
                currentSet.add(val[0:3])
        if line == "\n":
            if evalSet(currentSet):
                count = count + 1
            currentSet = set()
    if evalSet(currentSet):
        count = count + 1
    print(count)
  
runIt()    