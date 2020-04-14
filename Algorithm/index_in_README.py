import os
import re
README_path = 'F:\LeetCode/README.md'
solution_path = 'F:\LeetCode/solution'
README_index = []
solution_index = []

def find_file(path):
    for dirpath, dirnames, filenames in os.walk(path):
        # print(dirpath)
        # print(dirnames)
        for name in filenames:
            # print(name)
            ID = name[0:name.index('_')]
            solution_index.append(ID)

def ID_in_README():
    with open(README_path, 'r') as f:
        for line in f:
            if '|' in line:
                msg = line.split('|')
                ID = re.findall(r"\d+\.?\d*",msg[1])
                if len(ID):
                    README_index.append(ID[0])

def find_index_not_in_README():
    for index in solution_index:
        if README_index.count(index) == 0:
            print(index)

def find_index_not_in_solution():
    for index in README_index:
        if solution_index.count(index) == 0:
            print(index)

if __name__ == "__main__":
    print(os.getcwd())
    find_file(solution_path)
    # print(solution_index)
    ID_in_README()
    # print(README_index)
    find_index_not_in_README()
    print('---------------------------------------------')
    find_index_not_in_solution()