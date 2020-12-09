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
    
def evalProgram(instructions, toSwap):
    if instructions[toSwap][0] == "acc":
        return False     
    curInstNum = 0
    accResult = 0
    prevRunInsts = set()
    prevInst = -1
    while curInstNum < len(instructions):
        if curInstNum in prevRunInsts:
            prevInst = -1
            break

        prevRunInsts.add(curInstNum)
        instToRun = instructions[curInstNum]
        if toSwap == curInstNum:
            if instToRun[0]== "nop":
                instToRun = ("jmp", instToRun[1])
            elif instToRun[0]== "jmp":
                instToRun = ("nop", instToRun[1])
            
        instChange, accChange = doInst(instToRun)
        prevInst = curInstNum
        curInstNum = curInstNum + instChange
        accResult = accResult + accChange
    
    if prevInst == len(instructions) - 1:
        print(accResult)
        return True   
    return False
    
for i in range(len(instructions)):
    if evalProgram(instructions,i):
        break
    
    
    
