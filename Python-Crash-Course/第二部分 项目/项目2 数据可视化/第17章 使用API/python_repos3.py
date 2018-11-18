#改进了

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

# 创建一个Pygal类Config的实例，通过修改实例的属性可定制图表的外观
my_config = pygal.Config()

my_config.x_label_rotation = 45  # x轴标签顺时针旋转45度
my_config.show_legend = False  # 不显示图例
my_config.title_font_size = 24  # 标题的大小
my_config.label_font_size = 14  # x,y轴副标签字体的大小，副标签是 x 轴上的项目名以及 y 轴上的大部分数字
my_config.major_label_font_size = 18  # 主标签的字体大小。。主标签是 y 轴上为5000整数倍的刻度
my_config.truncate_label = 15  # 将较长的项目名缩短为15个字符
my_config.show_y_guides = False  # 隐藏图表中的水平
my_config.width = 1000  # 自定义图表的宽度，充分利用浏览器的空间

chart = pygal.Bar(my_config, style=my_stytle)
chart.title = 'Most-Starred Python Project on Github'
chart.x_labels = names

chart.add('333', stars)  # 虽然这里增加了图例但是图表中还是没有显示出来42
chart.render_to_file('python_repos3.svg')
