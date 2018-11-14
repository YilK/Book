import unittest
from city_functions import city_country


class TestCase(unittest.TestCase):
    """测试city_functions.py"""

    def test_city_country(self):  # 所有以test_打头的方法都将自动运行
        result = city_country('杭州', '中国')  # 使用要测试的函数
        self.assertEqual(result, '杭州,中国')  # 断言方法
        # 核实 result 是否等于 '杭州,中国'

    def test_city_country_population(self):
        result = city_country('义乌', '中国', 123456)
        self.assertEqual(result, '义乌,中国-population123456')


unittest.main()
