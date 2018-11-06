'''
编写一个程序，调查用户梦想的度假胜地。
使用类似于“If you could visit one place in the world, where would you go?”的提示，
并编写一个打印调查 结果的代码块。
'''
response = {}
while True:
    name = input("\nWhat's your name?")
    message = input('If you could visit one place in the world, '
                    'where would you go?')
    response[name] = message
    repeat = input("Would you like to let another person respond? (yes/ no) ")
    if repeat == 'no':
        break
for key,value in response.items():
    print(key+':'+value)

