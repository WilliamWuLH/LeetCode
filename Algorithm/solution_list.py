import os

Solution_path = os.path.join('..', 'solution')
Output_file = os.path.join('..', 'Solution_List.md')

GitHub_url = 'https://github.com/WilliamWuLH/LeetCode/tree/master/Solution/'

solution_list = sorted(os.listdir(Solution_path))

solution_dict = {}
for i in solution_list:
    solution_dict[ int(i.split('_')[0]) if i.split('_')[0] != 'LCP' else int(i.split('_')[1]) ] = i

solution_list = sorted(solution_dict.items(), key=lambda id:id[0])

with open(Output_file, 'w', encoding="utf-8") as f:
    f.writelines('| # | Solution |  \n')
    f.writelines('|:---:|:---|  \n')
    for key, val in solution_list:
        s = '| {id} | [{name}]({url}) |  \n'.format(id=key, name=val, url=GitHub_url+val)
        f.writelines(s)
