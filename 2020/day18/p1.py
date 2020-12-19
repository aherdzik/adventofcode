def findMatchingEndParenIndex(string):
    numParens, index = 1,0
    while numParens > 0:
        if string[index] == "(":
            numParens = numParens + 1
        elif string[index] == ")":
            numParens = numParens - 1
        index = index + 1
    return index

def evalExpression(string):
    toReturn = 0
    currentIndex = 0
    currentOp = ""
    while currentIndex < len(string):
        if string[currentIndex] == "(":
            endIndex = findMatchingEndParenIndex(string[currentIndex+1:]) + currentIndex
            parenTotal = evalExpression(string[currentIndex+1:endIndex])
            if currentOp == "+":
                toReturn = toReturn + parenTotal
            elif currentOp == "*":  
                toReturn = toReturn * parenTotal
            else:
                toReturn = parenTotal
            currentIndex = endIndex + 1
            continue
        elif string[currentIndex] == "*":
            currentOp = "*"
        elif string[currentIndex] == "+":
            currentOp = "+"
        else:
            nextNum = int(string[currentIndex])
            if currentOp == "+":
                toReturn = toReturn + nextNum
            elif currentOp == "*":  
                toReturn = toReturn * nextNum
            else:
                toReturn = nextNum
        currentIndex = currentIndex + 1        
    return toReturn


file1 = open('input.txt', 'r') 
total = 0
for line in file1.readlines():
    total = total + evalExpression(line.replace(" ","").replace("\n",""))
print(total)

    
