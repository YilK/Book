'''
可使用方法replace() 将字符串中的特定单词都替换为另一个单词。
下面是一个简单的示例，演示了如何将句子中的'dog' 替换为'cat'

>>> message = "I really like dogs."
>>> message.replace('dog', 'cat')
'I really like cats.'

读取你刚创建的文件learning_python.txt中的每一行，
将其中的Python都替换为另一门语言的名称，如C。将修改后的各行都打印到屏幕上。
'''

with open('learning_python.txt', encoding='UTF-8') as f:
    lines = f.readlines()
    for line in lines:
        print(line.replace('Python', 'C').strip())
