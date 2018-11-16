'''
想想可存储到列表中的东西，如山岳、河流、国家、城市、语言或你喜欢的任何东西。
编写一个程序，在其中创建一个包含这些元素的列表，
然后，对于本章介绍的每个函数，都至少使用一次来处理这个列表。
'''
example_list=['pomegranate','strawberry''water','melon','grape','waxberry']
print(example_list)
print(example_list[1])
print(example_list[2])

example_list.append('apple')
example_list.insert(1,'apple2')
print(example_list)

del example_list[1]
one=example_list.pop()
print(one)
example_list.remove('grape')
print(example_list)

example_list.sort()
print(example_list)
print(sorted(example_list,reverse=True))#不改变原来的对象
example_list.reverse()
print(example_list)

print(len(example_list))
