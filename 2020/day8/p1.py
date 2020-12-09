file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

instructions = []

def parseInst(line):
    instruction = line[:3]
    line = line[4:]
    currentInt = int(line[1:])
    if line[0] == '-':
        currentInt = currentInt * -1
    return (instruction, currentInt)
    
for line in Lines: 
    instructions.append(parseInst(line))
    
def doInst(curInst):
    instChange = 0
    accChange = 0
    if curInst[0] == "acc":
        accChange = accChange + curInst[1]
        instChange = instChange + 1
    elif curInst[0] == "jmp":
        instChange = instChange + curInst[1]
    elif curInst[0] == "nop":
        instChange = instChange + 1
    return (instChange, accChange)

curInstNum = 0
accResult = 0
prevRunInsts = set()
while curInstNum < len(instructions):
    if curInstNum in prevRunInsts:
        break
    prevRunInsts.add(curInstNum)
    instChange, accChange = doInst(instructions[curInstNum])
    curInstNum = curInstNum + instChange
    accResult = accResult + accChange
    
print(accResult)