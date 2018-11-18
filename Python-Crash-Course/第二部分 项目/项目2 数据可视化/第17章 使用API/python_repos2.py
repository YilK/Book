import requests
import pygal
from pygal.style import LightColorizedStyle as LCS, LightenStyle as LS

url = 'https://api.github.com/search/repositories?q=language:python&sort=stars'
r = requests.get(url)
print('Status code:', r.status_code)

response_dict = r.json()
print('Total repositories:', response_dict['total_count'])

# 探索仓库的相关信息
repo_dicts = response_dict['items']
print('Repositories returned:', len(repo_dicts))

names = []  # 存储仓库的名字
stars = []  # 存储仓库获得的星星数
for repo_dict in repo_dicts:
    names.append(repo_dict['name'])
    stars.append(repo_dict['stargazers_count'])

# 可视化
my_stytle = LS('#333366', base_style=LCS)

chart = pygal.Bar(style=my_stytle, x_label_rotation=45, show_legend=False)
'''
x_label_station=45:让标签绕x轴顺时针旋转45度
show_legend:不显示图例

'''

chart.title = 'Most-Starred Python Project on Github'
chart.x_labels = names
chart.add('', stars)
chart.render_to_file('python_repos2.svg')
