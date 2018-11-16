'''
想出至少5个你渴望去旅游的地方。
    1.将这些地方存储在一个列表中，并确保其中的元素不是按字母顺序排列的。
    2.按原始排列顺序打印该列表。不要考虑输出是否整洁的问题，只管打印原始Python列表。
    3.使用sorted() 按字母顺序打印这个列表，同时不要修改它。
    4.再次打印该列表，核实排列顺序未变。
    5.使用sorted() 按与字母顺序相反的顺序打印这个列表，同时不要修改它。
    6.再次打印该列表，核实排列顺序未变。
    7.使用reverse() 修改列表元素的排列顺序。打印该列表，核实排列顺序确实变了。
    8.使用reverse() 再次修改列表元素的排列顺序。打印该列表，核实已恢复到原来的排列顺序。
    9.使用sort() 修改该列表，使其元素按字母顺序排列。打印该列表，核实排列顺序确实变了。
    10.使用sort() 修改该列表，使其元素按与字母顺序相反的顺序排列。打印该列表，核实排列顺序确实变了。
'''
places=['shanghai','hangzhou','yunan','beijing','shenzhen']

print(places)

print(sorted(places))

print(places)

print(sorted(places,reverse=True))

print(places)

places.reverse()
print(places)

places.reverse()
print(places)

places.sort()
print(places)

places.sort(reverse=True)
print(places)


