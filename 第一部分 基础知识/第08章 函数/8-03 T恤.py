'''
编写一个名为make_shirt() 的函数，它接受一个尺码以及要印到T恤上的字样。
这个函数应打印一个句子，概要地说明T恤的尺码和字样。
使用位置实参调用这个函数来制作一件T恤；再使用关键字实参来调用这个函数。
'''
def make_shirt(size,font):
    print('size:'+size+';font:'+font)

#位置实参调用
make_shirt('L','hello')
#关键字实参调用
make_shirt(font='hjk',size='XL')
