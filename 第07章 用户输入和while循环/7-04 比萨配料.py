'''
编写一个循环，提示用户输入一系列的比萨配料，并在用户输入'quit' 时结束循环。
每当用户输入一种配料后，都打印一条消息，说我们会在比萨 中添加这种配料。
'''
message = ''
while True:
    message = input('请添加一种配料,若不想添加请输入 quit :')
    if message == 'quit':
        break
    else:
        print('添加:', message)
