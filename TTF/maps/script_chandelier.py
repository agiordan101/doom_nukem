#Doom-Nukem script chandelier

import sys

if (len(sys.argv) != 5):
    print("Args :", sys.argv)
    print("len =", len(sys.argv))

map_file = open(sys.argv[1], 'r')
lines = map_file.read().split('\n')
map_file.close()
tx = int(sys.argv[2])
ty = int(sys.argv[3])
tz = int(sys.argv[4])

newmap_file = open(sys.argv[1][:-4] + "_translate.txt", 'w')

for line in lines:
    split = line.split("x:")
    newmap_file.write(split[0])

    if (len(split) > 1):
        nbrs = split[1].split(",")
        newmap_file.write("x:" + str(int(nbrs[0]) + tx))
        nbrs[1] += ","
        nbrs[1] += nbrs[2]
    
        split = nbrs[1].split("y:") #Avoir ce qui est apres
        nbrs = split[1].split(",")  #Avoir le nombre avant
        newmap_file.write(", y:" + str(int(nbrs[0]) + ty))
    
        split = nbrs[1].split("z:")
        nbrs = split[1].split(",")
        newmap_file.write(", z:" + str(int(nbrs[0]) + tz))
    newmap_file.write('\n')
newmap_file.close()