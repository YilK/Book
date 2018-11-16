'''
在文本编辑器中新建一个文件，写几句话来总结一下你至此学到的Python知识，
其中每一行都以“In Python you can”打头。将这个文件命名为 learning_python.txt，
并将其存储到为完成本章练习而编写的程序所在的目录中。编写一个程序，它读取这个文件，
并将你所写的内容打印三次：
    1.第一次打印时读取整个文件；
    2.第二次打印时遍历文件对象；
    3.第三次打印时将各行存储在一个列表中，再在with 代码块外打印它们。
'''

# 1
with open('learning_python.txt', encoding='UTF-8') as f:
    contents = f.read()
    print(contents.rstrip())  # 删除末尾的空行

print('-----')

# 2
with open('learning_python.txt', encoding='UTF-8') as f:
    for line in f:
        print(line.rstrip())
print('-----')

# 3
with open('learning_python.txt', encoding='UTF-8') as f:
    lines = f.readlines()  # 各行存储在一个列表中
for line in lines:
    print(line.rstrip())
