import random

# Input the number of Monte Carlo Cycles
# a = int(input("Enter a number of cycles: "))
a = 1500
win = 0
lose = 0

# Establish Truth what's behind the doors
# for i in range(1,4):
#    print(i)

# The Price Is Right Loads The Doors
x = random.uniform(0.0, 3.0)
# print(x)
if x < 1.0:
    door = [True, False, False]
elif x < 2.0:
    door = [False, True, False]
else:
    door = [False, False, True]

# for i in door:
#    print(i)

# Run The Experiment a Times
for i in range(1, a + 1):
    # Contestant Picks A Door
    x = random.uniform(0.0, 3.0)
    # print(x)
    if x < 1.0:
        pick = 1
    elif x < 2.0:
        pick = 2
    else:
        pick = 3

    # Monte Hall Reveals A Door Without The Prize
    # So We Must Find One Of The Two Remaining
    # Doors That Doesn't Have The Prize

    # Determine Door To Reveal
    if (door[0] == False) and (pick != 1):
        reveal = 1
    elif (door[1] == False) and (pick != 2):
        reveal = 2
    else:
        reveal = 3

    # Contestant changes door choice
    if (pick == 1) and (reveal == 2):
        pick = 3
    elif (pick == 1) and (reveal == 3):
        pick = 2
    elif (pick == 2) and (reveal == 1):
        pick = 3
    elif (pick == 2) and (reveal == 3):
        pick = 1
    elif (pick == 3) and (reveal == 1):
        pick = 2
    else:
        pick = 1
    # print("pick: ", pick)

    if door[pick - 1] == True:
        # print("win")
        win += 1
    else:
        # print("lose")
        lose += 1

print("win: ", win, ",  lose: ", lose)
win = (win / a) * 100
lose = (lose / a) * 100
print("Win: ", win, "%,    Lose: ", lose, "%")
