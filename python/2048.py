import numpy as np
import random
import sys
import tkinter as tk
import os
import termios

	

def mat2list(cur_mat):
    list_cur = []
    for row in range(len(cur_mat)):
        for column in range(len(cur_mat)):
            list_cur.append(cur_mat[row][column])
    return list_cur

def list2mat(cur_list):
    mat_cur = np.matrix([cur_list[0:4],cur_list[4:8],cur_list[8:12],cur_list[12:16]])
    return mat_cur

def findZeros(list1):
    list2= []
    for ind in range(len(list1)):
        if list1[ind] == 0:
         list2.append(ind)
    return list2

def print_matrix(cur_matrix):
    print_mat = []
    for row in range(len(cur_matrix)):
        for column in range(len(cur_matrix)):
            if cur_matrix[row,column] == 0:
                print_mat.append('_')
            else:
                print_mat.append(cur_matrix[row,column])
    print(print_mat[0],"\t",print_mat[1],"\t",print_mat[2],"\t",print_mat[3])
    print(print_mat[4],"\t",print_mat[5],"\t",print_mat[6],"\t",print_mat[7])
    print(print_mat[8],"\t",print_mat[9],"\t",print_mat[10],"\t",print_mat[11])
    print(print_mat[12],"\t",print_mat[13],"\t",print_mat[14],"\t",print_mat[15])

def initial_matrix():
    zero_mat = np.zeros( [4,4] , dtype = int)
    zero_list = mat2list(zero_mat)
    zero_indices = findZeros(zero_list)
    random_number = random.sample(zero_indices, 2)
    #print(random_number)
    zero_list[random_number[0]] = 2
    zero_list[random_number[1]] = 2
    initial_mat = list2mat(zero_list)
    print_matrix(initial_mat)
    return initial_mat


current_mat = np.copy(initial_matrix())
prev_mat = []
prev_key = ''
key_pressed = 0


def RIGHT(cur_matrix = current_mat):
    comp_mat = np.copy(cur_matrix)
    next_mat = cur_matrix
    for row in range(len(cur_matrix)):
        count = 0
        for column in [2,1,0]:
            if column == 2 and cur_matrix[row,column] != 0:
                if cur_matrix[row,column+1] == 0:
                    next_mat[row,column+1] = cur_matrix[row,column+1] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row,column+1] == cur_matrix[row,column]:
                    next_mat[row,column+1] = cur_matrix[row,column+1] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                    count = count + 1
            elif column == 1 and cur_matrix[row,column] != 0:
                if cur_matrix[row,column+2] == 0 and cur_matrix[row,column+1] == 0:
                    next_mat[row,column+2] = cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row,column+2] == 0 and cur_matrix[row,column+1] == cur_matrix[row,column]:
                    next_mat[row,column+2] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                    count = count + 1
                elif cur_matrix[row,column+1] == 0 and cur_matrix[row,column+2] == cur_matrix[row,column] and count == 0:            
                    next_mat[row,column+2] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                    count = count + 1
                elif cur_matrix[row,column+1] == 0:
                    next_mat[row,column+1] = cur_matrix[row,column+1] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row,column+1] == cur_matrix[row,column]:
                    next_mat[row,column+1] = cur_matrix[row,column+1] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                    count = count + 1
            elif column == 0 and cur_matrix[row,column] != 0:
                if cur_matrix[row,column+3] == 0 and cur_matrix[row,column+2] == 0 and cur_matrix[row,column+1] == 0:
                    next_mat[row,column+3] = cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row,column+2] == 0 and cur_matrix[row,column+1] == 0 and cur_matrix[row,column+3] == cur_matrix[row,column] and count == 0:
                    next_mat[row,column+3] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row,column+3] == 0 and cur_matrix[row,column+1] == 0 and cur_matrix[row,column+2] == cur_matrix[row,column]:
                    next_mat[row,column+3] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row,column+2] == 0 and cur_matrix[row,column+3] == 0 and cur_matrix[row,column+1] == cur_matrix[row,column]:
                    next_mat[row,column+3] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row,column+2] == 0 and cur_matrix[row,column+1] == cur_matrix[row,column] and count == 0:
                    next_mat[row,column+2] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row,column+1] == 0 and cur_matrix[row,column+2] == cur_matrix[row,column] and count == 0:
                    next_mat[row,column+2] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row,column+2] == 0 and cur_matrix[row,column+1] == 0:
                    next_mat[row,column+2] = cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row,column+1] == 0:
                    next_mat[row,column+1] = cur_matrix[row,column+1] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row,column+1] == cur_matrix[row,column]:
                    next_mat[row,column+1] = cur_matrix[row,column+1] + cur_matrix[row,column]
                    next_mat[row,column] = 0
    if np.count_nonzero(comp_mat == next_mat) != 16:
        new_list = mat2list(next_mat)
        zero_indices = findZeros(new_list)
        random_number = random.choice(zero_indices)
        new_list[random_number] = 2
        next_mat = list2mat(new_list)
    cur_matrix = np.copy(next_mat)
    return cur_matrix

def LEFT(cur_matrix = current_mat):
    comp_mat = np.copy(cur_matrix)
    next_mat = cur_matrix
    for row in range(len(cur_matrix)):
        count = 0
        for column in [1,2,3]:
            if column == 1 and cur_matrix[row,column] != 0:
                if cur_matrix[row,column-1] == 0:
                    next_mat[row,column-1] = cur_matrix[row,column-1] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                    count = count + 1
                elif cur_matrix[row,column-1] == cur_matrix[row,column]:
                    next_mat[row,column-1] = cur_matrix[row,column-1] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                    count = count + 1
            elif column == 2 and cur_matrix[row,column] != 0:
                if cur_matrix[row,column-2] == 0 and cur_matrix[row,column-1] == 0:
                    next_mat[row,column-2] = cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row,column-2] == 0 and cur_matrix[row,column-1] == cur_matrix[row,column]:
                    next_mat[row,column-2] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                    count = count + 1
                elif cur_matrix[row,column-1] == 0 and cur_matrix[row,column-2] == cur_matrix[row,column] and count == 0:
                    next_mat[row,column-2] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                    count = count + 1
                elif cur_matrix[row,column-1] == 0:
                    next_mat[row,column-1] = cur_matrix[row,column-1] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row,column-1] == cur_matrix[row,column]:
                    next_mat[row,column-1] = cur_matrix[row,column-1] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                    count = count + 1
            elif column == 3 and cur_matrix[row,column] != 0:
                if cur_matrix[row,column-3] == 0 and cur_matrix[row,column-2] == 0 and cur_matrix[row,column-1] == 0:
                    next_mat[row,column-3] = cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row,column-2] == 0 and cur_matrix[row,column-1] == 0 and cur_matrix[row,column-3] == cur_matrix[row,column] and count == 0:
                    next_mat[row,column-3] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row,column-3] == 0 and cur_matrix[row,column-1] == 0 and cur_matrix[row,column-2] == cur_matrix[row,column]:
                    next_mat[row,column-3] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row,column-2] == 0 and cur_matrix[row,column-3] == 0 and cur_matrix[row,column-1] == cur_matrix[row,column]:
                    next_mat[row,column-3] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row,column-2] == 0 and cur_matrix[row,column-1] == cur_matrix[row,column] and count == 0:
                    next_mat[row,column-2] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row,column-1] == 0 and cur_matrix[row,column-2] == cur_matrix[row,column] and count == 0:
                    next_mat[row,column-2] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row,column-2] == 0 and cur_matrix[row,column-1] == 0:
                    next_mat[row,column-2] = cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row,column-1] == 0 or cur_matrix[row,column-1] == cur_matrix[row,column]:
                    next_mat[row,column-1] = cur_matrix[row,column-1] + cur_matrix[row,column]
                    next_mat[row,column] = 0
    if np.count_nonzero(comp_mat == next_mat) != 16:
        new_list = mat2list(next_mat)
        zero_indices = findZeros(new_list)
        random_number = random.choice(zero_indices)
        new_list[random_number] = 2
        next_mat = list2mat(new_list)
    cur_matrix = np.copy(next_mat)
    return cur_matrix

def DOWN(cur_matrix = current_mat):
    comp_mat = np.copy(cur_matrix)
    next_mat = cur_matrix
    for column in range(len(cur_matrix)):
        count  = 0
        for row in [2,1,0]:
            if row == 2 and cur_matrix[row,column] != 0:
                if cur_matrix[row+1,column] == 0:
                    next_mat[row+1,column] = cur_matrix[row+1,column] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row+1,column] == cur_matrix[row,column]:
                    next_mat[row+1,column] = cur_matrix[row+1,column] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                    count = count + 1
            elif row == 1 and cur_matrix[row,column] != 0:
                if cur_matrix[row+2,column] == 0 and cur_matrix[row+1,column] == 0:
                    next_mat[row+2,column] = cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row+2,column] == 0 and cur_matrix[row+1,column] == cur_matrix[row,column]:
                    next_mat[row+2,column] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                    count = count + 1
                elif cur_matrix[row+1,column] == 0 and cur_matrix[row+2,column] == cur_matrix[row,column] and count == 0:
                    next_mat[row+2,column] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                    count = count + 1
                elif cur_matrix[row+1,column] == 0:
                    next_mat[row+1,column] = cur_matrix[row+1,column] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row+1,column] == cur_matrix[row,column]:
                    next_mat[row+1,column] = cur_matrix[row+1,column] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                    count = count + 1
            elif row == 0 and cur_matrix[row,column] != 0:
                if cur_matrix[row+3,column] == 0 and cur_matrix[row+2,column] == 0 and cur_matrix[row+1,column] == 0:
                    next_mat[row+3,column] = cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row+2,column] == 0 and cur_matrix[row+1,column] == 0 and cur_matrix[row+3,column] == cur_matrix[row,column] and count == 0:
                    next_mat[row+3,column] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row+3,column] == 0 and cur_matrix[row+1,column] == 0 and cur_matrix[row+2,column] == cur_matrix[row,column]:
                    next_mat[row+3,column] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row+2,column] == 0 and cur_matrix[row+3,column] == 0 and cur_matrix[row+1,column] == cur_matrix[row,column]:
                    next_mat[row+2,column] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row+2,column] == 0 and cur_matrix[row+1,column] == cur_matrix[row,column] and count == 0:
                    next_mat[row+2,column] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row+1,column] == 0 and cur_matrix[row+2,column] == cur_matrix[row,column] and count == 0:
                    next_mat[row+2,column] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row+2,column] == 0 and cur_matrix[row+1,column] == 0:
                    next_mat[row+2,column] = cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row+1,column] == 0 or cur_matrix[row+1,column] == cur_matrix[row,column]:
                    next_mat[row+1,column] = cur_matrix[row+1,column] + cur_matrix[row,column]
                    next_mat[row,column] = 0
    if np.count_nonzero(comp_mat == next_mat) != 16:
        new_list = mat2list(next_mat)
        zero_indices = findZeros(new_list)
        random_number = random.choice(zero_indices)
        new_list[random_number] = 2
        next_mat = list2mat(new_list)
    cur_matrix = np.copy(next_mat)
    return cur_matrix

def UP(cur_matrix = current_mat):
    comp_mat = np.copy(cur_matrix)
    next_mat = cur_matrix
    for column in range(len(cur_matrix)):
        count = 0
        for row in [1,2,3]:
            if row == 1 and cur_matrix[row,column] != 0:
                if cur_matrix[row-1,column] == 0:
                    next_mat[row-1,column] = cur_matrix[row-1,column] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row-1,column] == cur_matrix[row,column]:
                    next_mat[row-1,column] = cur_matrix[row-1,column] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                    count = count + 1
            elif row == 2 and cur_matrix[row,column] != 0:
                if cur_matrix[row-2,column] == 0 and cur_matrix[row-1,column] == 0:
                    next_mat[row-2,column] = cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row-2,column] == 0 and cur_matrix[row-1,column] == cur_matrix[row,column]:
                    next_mat[row-2,column] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                    count = count + 1
                elif cur_matrix[row-1,column] == 0 and cur_matrix[row-2,column] == cur_matrix[row,column] and count == 0:
                    next_mat[row-2,column] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                    count = count + 1
                elif cur_matrix[row-1,column] == 0:
                    next_mat[row-1,column] = cur_matrix[row-1,column] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row-1,column] == cur_matrix[row,column]:
                    next_mat[row-1,column] = cur_matrix[row-1,column] + cur_matrix[row,column]
                    next_mat[row,column] = 0
                    count = count + 1
            elif row == 3 and cur_matrix[row,column] != 0:
                if cur_matrix[row-3,column] == 0 and cur_matrix[row-2,column] == 0 and cur_matrix[row-1,column] == 0:
                    next_mat[row-3,column] = cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row-2,column] == 0 and cur_matrix[row-1,column] == 0 and cur_matrix[row-3,column] == cur_matrix[row,column] and count == 0:
                    next_mat[row-3,column] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row-3,column] == 0 and cur_matrix[row-1,column] == 0 and cur_matrix[row-2,column] == cur_matrix[row,column]:
                    next_mat[row-3,column] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row-2,column] == 0 and cur_matrix[row-3,column] == 0 and cur_matrix[row-1,column] == cur_matrix[row,column]:
                    next_mat[row-2,column] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row-2,column] == 0 and cur_matrix[row-1,column] == cur_matrix[row,column] and count == 0:
                    next_mat[row-2,column] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row-1,column] == 0 and cur_matrix[row-2,column] == cur_matrix[row,column] and count == 0:
                    next_mat[row-2,column] = cur_matrix[row,column]*2
                    next_mat[row,column] = 0
                elif cur_matrix[row-2,column] == 0 and cur_matrix[row-1,column] == 0:
                    next_mat[row-2,column] = cur_matrix[row,column]
                    next_mat[row,column] = 0
                elif cur_matrix[row-1,column] == 0 or cur_matrix[row-1,column] == cur_matrix[row,column]:
                    next_mat[row-1,column] = cur_matrix[row-1,column] + cur_matrix[row,column]
                    next_mat[row,column] = 0
    if np.count_nonzero(comp_mat == next_mat) != 16:
        new_list = mat2list(next_mat)
        zero_indices = findZeros(new_list)
        random_number = random.choice(zero_indices)
        new_list[random_number] = 2
        next_mat = np.copy(list2mat(new_list))
    cur_matrix = np.copy(next_mat)
    return cur_matrix
    
def CheckMat(cur_matrix):
    curr_list = mat2list(cur_matrix)
    NoOfZeros = findZeros(curr_list)
    if NoOfZeros == []:
        Up_Mat = np.copy(UP(cur_matrix))    
        Down_Mat = np.copy(DOWN(cur_matrix))
        Right_Mat = np.copy(RIGHT(cur_matrix))
        Left_Mat = np.copy(LEFT(cur_matrix))
        if np.count_nonzero(current_mat == Up_Mat) == 16 and np.count_nonzero(current_mat == Down_Mat) == 16 and np.count_nonzero(current_mat == Right_Mat) == 16 and np.count_nonzero(current_mat == Left_Mat) == 16:
            print("GAME OVER")
            print("\n\nYour Final Game Looks like\n\n")
            print_matrix(current_mat)
            sys.exit()

'''def key(event):
    os.system('cls')
    print("You Pressed ",event.keysym)
    global prev_mat
    global current_mat
    global prev_key
    if event.keysym == 'Escape':
        print("\n\nYour Final Game looks like\n\n")
        print_matrix(current_mat)
        sys.exit()
        root.destroy()
    if event.keysym == 'Up':
        prev_mat = np.copy(current_mat)
        curr_mat = UP(current_mat)
        current_mat = curr_mat
        print("\n\n")
        print_matrix(current_mat)
        print("\n\n")
        CheckMat(current_mat)
    elif event.keysym == 'Down':
        prev_mat = np.copy(current_mat)
        curr_mat = DOWN(current_mat)
        current_mat = curr_mat
        print("\n\n")
        print_matrix(current_mat)
        print("\n\n")
        CheckMat(current_mat)
    elif event.keysym == 'Right':
        prev_mat = np.copy(current_mat)
        curr_mat = RIGHT(current_mat)
        current_mat = curr_mat
        print("\n\n")
        print_matrix(current_mat)
        print("\n\n")
        CheckMat(current_mat)
    elif event.keysym == 'Left':
        prev_mat = np.copy(current_mat)
        curr_mat = LEFT(current_mat)
        current_mat = curr_mat
        print("\n\n")
        print_matrix(current_mat)
        print("\n\n")
        CheckMat(current_mat)
    elif event.keysym == prev_key:
        print("Only One UNDO possible")
    elif event.keysym == 'BackSpace':
        current_mat = np.copy(prev_mat)
        print("\n\n")
        print_matrix(current_mat)
        print("\n\n")
    else:
        print("Use the Arrow keys or Backspace or Escape only")
        print("\n\nYOUR CURRENT GAME\n\n")
        print_matrix(current_mat)
    prev_key = event.keysym
    print( "\nPress a Arrow key for your next move (Escape key to exit):" )'''

def main():
    #os.system('cls')
    print("\n\nGAME START\n\n")
    print("ULTIMATE GOAL:\n\tMANAGE TO GET A 2048 OR HIGHER TILE!!!")
    print("Instructions:\n\n1.Use [i,j,k,l] keys to Move the Tiles\n2.Use b to UNDO a move(Only one UNDO allowed after each move)\n3.Use Esc button to Quit game at any time\n\n")
    print("\n\n")
    #orig_settings = termios.tcgetattr(sys.stdin)

    #tty.setcbreak(sys.stdin)
    x = 0
    while 1:
        #root = tk.Tk()
        current_key = input("\nPress a key (Escape key to exit):" )
        #root.bind_all('<Key>', key)
        #root.withdraw()
        #root.mainloop()
        #os.system('cls')
        #x = sys.stdin.read(1)[0]
        #print("You Pressed ",key_pressed)
        #print("You Pressed ", event.keysym)
        print("You Pressed ", current_key)
        global prev_mat
        global current_mat
        global prev_key
        if current_key == 'q':
            print("\n\nYour Final Game looks like\n\n")
            print_matrix(current_mat)
            sys.exit()
            #root.destroy()
        if current_key == 'i':
            prev_mat = np.copy(current_mat)
            curr_mat = UP(current_mat)
            current_mat = curr_mat
            print("\n\n")
            print_matrix(current_mat)
            print("\n\n")
            CheckMat(current_mat)
        elif current_key == 'k':
            prev_mat = np.copy(current_mat)
            curr_mat = DOWN(current_mat)
            current_mat = curr_mat
            print("\n\n")
            print_matrix(current_mat)
            print("\n\n")
            CheckMat(current_mat)
        elif current_key == 'l':
            prev_mat = np.copy(current_mat)
            curr_mat = RIGHT(current_mat)
            current_mat = curr_mat
            print("\n\n")
            print_matrix(current_mat)
            print("\n\n")
            CheckMat(current_mat)
        elif current_key == 'j':
            prev_mat = np.copy(current_mat)
            curr_mat = LEFT(current_mat)
            current_mat = curr_mat
            print("\n\n")
            print_matrix(current_mat)
            print("\n\n")
            CheckMat(current_mat)
        elif current_key == prev_key:
            print("Only One UNDO possible")
        elif current_key == 'u':
            current_mat = np.copy(prev_mat)
            print("\n\n")
            print_matrix(current_mat)
            print("\n\n")
        else:
            print("Use the Arrow keys or Backspace or Escape only")
            print("\n\nYOUR CURRENT GAME\n\n")
            print_matrix(current_mat)
        prev_key = current_key
        print("\nPress a Arrow key for your next move (Escape key to exit):")


    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, orig_settings)



if __name__ == '__main__':
    main()
