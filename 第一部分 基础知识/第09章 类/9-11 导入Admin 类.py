'''
以为完成练习9-8而做的工作为基础，将User 、Privileges 和Admin 类存储在一个模块中，
再创建一个文件，在其中创建一个Admin 实例 并对其调用方法show_privileges() ，
以确认一切都能正确地运行。
'''
from user import Admin

admin1 = Admin('admin')
admin1.privileges.show_privileges()
