#!/bin/python
from curses.ascii import isalnum
from pickle import FALSE
import random

# Utility

def getNextPosition(currentPos, direction, rowNumber, colNumber):
  if direction == 0: # NORTH
    if currentPos[0] > 0:
      return (currentPos[0] - 1, currentPos[1])
    else:
      return (-1,-1)
  elif direction == 2: # EAST
    if currentPos[1] < colNumber - 1:
      return (currentPos[0], currentPos[1] + 1)
    else:
      return (-1,-1)
  elif direction == 4: # SOUTH
    if currentPos[0] < rowNumber - 1:
      return (currentPos[0] + 1, currentPos[1])
    else:
      return (-1,-1)
  elif direction == 6: # WEST
    if currentPos[1] > 0:
      return (currentPos[0], currentPos[1] - 1)
    else:
      return (-1,-1)
  elif direction == 1: # NE
    north = getNextPosition(currentPos, 0, rowNumber, colNumber)[0]
    east = getNextPosition(currentPos, 2, rowNumber, colNumber)[1]

    if north >= 0 and east>= 0:
      return (north,east)
    else:
      return (-1,-1)
  elif direction == 3: # SE
    south = getNextPosition(currentPos, 4, rowNumber, colNumber)[0]
    east = getNextPosition(currentPos, 2, rowNumber, colNumber)[1]

    if south >= 0 and east>= 0:
      return (south,east)
    else:
      return (-1,-1)
  elif direction == 5: #SW
    south = getNextPosition(currentPos, 4, rowNumber, colNumber)[0]
    west = getNextPosition(currentPos, 6, rowNumber, colNumber)[1]

    if south >= 0 and west>= 0:
      return (south, west)
    else:
      return (-1,-1)
  elif direction == 7: #NW
    north = getNextPosition(currentPos, 0, rowNumber, colNumber)[0]
    west = getNextPosition(currentPos, 6, rowNumber, colNumber)[1]

    if north >= 0 and west>= 0:
      return (north, west)
    else:
      return (-1,-1)

def isCanInserted(pos, direction, table, str, rowNumber, colNumber):
  currentPos = pos
  i = 0

  while(currentPos[0] >= 0 and currentPos[1] >= 0 
        and currentPos[0] < rowNumber and currentPos[1] < colNumber):
    if(table[currentPos[0]][currentPos[1]] != "" and 
        table[currentPos[0]][currentPos[1]] != str[i]):
      return False

    currentPos = getNextPosition(currentPos, direction,  rowNumber, colNumber)
    i += 1
    if(len(str) == i):
      return True
  
  return False


def insertWordRandom(table, str, rowNumber, colNumber):
  direction = random.randint(0,7)
  position = (random.randint(0,rowNumber-1), random.randint(0,colNumber-1))

  while not isCanInserted(position, direction, table, str, rowNumber, colNumber):
    direction = random.randint(0,7)
    position = (random.randint(0,rowNumber-1), random.randint(0,colNumber-1))
  
  for i in str:
    table[position[0]][position[1]] = i
    position = getNextPosition(position, direction, rowNumber, colNumber)
  
# Main code

rows = int(input())
cols = int(input())
words = []

readedWord = input()
while(readedWord != "."):
  words.append(readedWord)
  readedWord = input()

table = [["" for _ in range(cols)] for _ in range(rows)]

for i in words:
  insertWordRandom(colNumber=cols, rowNumber=rows, table=table, str=i)

for i in table:
  for ch in i:
    if ch == "" or not isalnum(ch):
      print(chr(random.randint(ord("A"),ord("Z"))), end=" ")
    else:
      print(ch, end=" ")
  print()

print()

for i in words:
  print(i)