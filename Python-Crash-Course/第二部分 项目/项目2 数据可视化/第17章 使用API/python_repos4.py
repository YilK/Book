# 添加了自定义工具提示
import requests
import pygal
from pygal.style import LightColorizedStyle as LCS, LightenStyle as LS

url = 'https://api.github.com/search/repositories?q=language:python&sort=stars'
r = requests.get(url)
r.encoding = r.apparent_encoding
print('Status code:', r.status_code)

response_dict = r.json()
print('Total repositories:', response_dict['total_count'])

# 探索仓库的相关信息
repo_dicts = response_dict['items']
print('Repositories returned:', len(repo_dicts))

plot_dicts = []
names = []
for repo_dict in repo_dicts:
    names.append(repo_dict['name'])
    plot_dict = {
        'value': repo_dict['stargazers_count'],
        'label': str(repo_dict['description'])
    }
    plot_dicts.append(plot_dict)

my_style = LS('#333366', base_style=LCS)

chart = pygal.Bar(style=my_style, x_label_rotation=45, show_legend=False)
'''
x_label_station=45:让标签绕x轴顺时针旋转45度
show_legend:不显示图例

'''

chart.title = 'Most-Starred Python Project on Github'
chart.x_labels = names

chart.add('', plot_dicts)
chart.render_to_file('python_repos4.svg')
