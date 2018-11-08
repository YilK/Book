'''
既然你知道了如何遍历字典，现在请整理你为完成练习6-3而编写的代码，
将其中的一系列print 语句替换为一个遍历字典中的键和值的循环。
确定该 循环正确无误后，再在词汇表中添加5个Python术语。当你再次运行这个程序时，
这些新术语及其含义将自动包含在输出中。
'''
vocabulary = {
    'int': '整型数据',
    'float': '浮点数',
    'assert': '断言',
    'print': '打印输出',
    'input': '输入'
}
vocabulary['dict'] = '字典'
vocabulary['str'] = '字符串'
vocabulary['list'] = '列表'
vocabulary['class'] = '类'
vocabulary['append'] = '添加'

# 遍历输出
for key, value in vocabulary.items():
    print(key + ':' + value)
