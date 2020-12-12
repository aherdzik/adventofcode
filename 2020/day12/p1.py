file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

def clampDir(dir):
    while dir < 0:
        dir = dir + 4
    while dir >3:
        dir = dir -4
    return dir
    
def rotateShip(dir,command, inst):
    inst = inst/ 90
    if command == "L":
        inst = inst * -1
    dir = dir + inst
    return clampDir(dir)    
    
def cardinalMove(command,horiz,vert,val):
    if command == "N":
        vert = vert - val
    elif command == "S":
        vert = vert + val
    elif command == "E":
        horiz =horiz + val
    elif command == "W":
        horiz =horiz - val
    return horiz, vert

def makeMove(line,dir,horiz,vert):
    command = line[:1]
    inst = int(line[1:])
    if command in {"N","E","S","W"} :
        horiz, vert = cardinalMove(command,horiz,vert, inst)
    elif command == "F":
        dirToCommandMap = {0:"N", 1:"E", 2: "S", 3: "W"}
        horiz, vert = cardinalMove(dirToCommandMap[dir],horiz,vert, inst)
    else:
        dir = rotateShip(dir,command,inst)
    return dir,horiz,vert

dir = 1  #0=N, 1=E, 2=S, 3=W
horiz = 0
vert = 0
for line in Lines: 
    dir, horiz, vert = makeMove(line,dir,horiz,vert)
print(abs(horiz) + abs(vert))    
     
