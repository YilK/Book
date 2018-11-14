import unittest
from employee import Employee  # 导入类


class TestEmployee(unittest.TestCase):
    """针对Employee类的测试"""

    def setUp(self):
        """创建一个对象,供测试方法使用"""
        self.people = Employee('h', 'jk', 8500)

    def test_give_default_raise(self):
        self.people.give_raise()  # 默认增加年薪
        self.assertEqual(self.people.yearly_salary, 13500)

    def test_give_custom_raise(self):
        self.people.give_raise(10000)  # 增加1w年薪
        self.assertEqual(self.people.yearly_salary, 18500)


unittest.main()
