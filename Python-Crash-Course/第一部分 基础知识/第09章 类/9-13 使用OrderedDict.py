'''
在练习6-4中，你使用了一个标准字典来表示词汇表。请使用OrderedDict 类来重写这个程序，
并确认输出的顺序与你在字典中添加键 —值对的顺序一致。
'''
from collections import OrderedDict

vocabulary = OrderedDict()
vocabulary['int'] = '整型数据'
vocabulary['float'] = '浮点数'
vocabulary['dict'] = '字典'
vocabulary['str'] = '字符串'
vocabulary['list'] = '列表'
vocabulary['class'] = '类'
vocabulary['append'] = '添加'

for key, value in vocabulary.items():
    print(key + ':' + value)
