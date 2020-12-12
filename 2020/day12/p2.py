file1 = open('input.txt', 'r') 
Lines = file1.readlines() 

def clampInst(inst):
    while inst < 0:
        inst = inst + 4
    while inst >3:
        inst = inst -4
    return inst
    
def rotateShip(waypointX,waypointY,command,inst):
    inst = inst/ 90
    savedX = waypointX
    if command == "L":
        inst = inst * -1
    inst = clampInst(inst) 
    if inst == 1:
        waypointX = -1* waypointY
        waypointY = savedX
    elif inst == 2:
        waypointX = waypointX * -1
        waypointY = waypointY * -1
    elif inst == 3:
        waypointX = waypointY
        waypointY = -1* savedX
        
    return waypointX,waypointY   
    
def cardinalWaypointMove(command,waypointX,waypointY, inst):
    if command == "N":
        waypointY = waypointY - inst
    elif command == "S":
        waypointY = waypointY + inst
    elif command == "E":
        waypointX =waypointX + inst
    elif command == "W":
        waypointX =waypointX - inst
    return waypointX, waypointY

def makeMove(line,horiz,vert,waypointX,waypointY):
    command = line[:1]
    inst = int(line[1:])
    if command in {"N","E","S","W"} :
        waypointX, waypointY = cardinalWaypointMove(command,waypointX,waypointY, inst)
    elif command == "F":
        horiz = horiz + (inst * waypointX)
        vert = vert + (inst * waypointY)
    else:
        waypointX,waypointY = rotateShip(waypointX,waypointY,command,inst)
    #print("X:",horiz,"Y:",vert,"WaypointX:",waypointX,"WaypointY:",waypointY)
    return horiz,vert,waypointX,waypointY

horiz = 0
vert = 0
waypointX = 10
waypointY = -1
for line in Lines: 
    horiz, vert, waypointX, waypointY = makeMove(line,horiz,vert,waypointX,waypointY)
print(abs(horiz) + abs(vert))    
     
