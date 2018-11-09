'''
将User 类存储在一个模块中，并将Privileges 和Admin 类存储在另一个模块中。
再创建一个文件，在其中创建一个Admin 实例，并对其调用方 法show_privileges() ，
以确认一切都依然能够正确地运行。
'''
from user2 import Admin

admin1 = Admin('admin')
admin1.privileges.show_privileges()
