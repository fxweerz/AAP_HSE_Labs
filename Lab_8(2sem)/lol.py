"""
Разработать классы «точка» и «половина шара».
Члены-данные сделать закрытой частью в каждом классе.
Для каждого класса разработать: конструктор с параметрами для инициализации, методы ввода/вывода.
Разработать 2 функции определения принадлежности точки половине шара:
 метод класса и функцию с двумя параметрами (точка и половина шара).
"""

class Point:
    def __init__(self, x=0, y=0, z=0):
        self.__x = x
        self.__y = y
        self.__z = z

    def input_point(self):
        self.__x = float(input("Введите координату X: "))
        self.__y = float(input("Введите координату Y: "))
        self.__z = float(input("Введите координату Z: "))

    def output_point(self):
        print(f"Точка: ({self.__x}, {self.__y}, {self.__z})")

    def get_coordinates(self):
        return self.__x, self.__y, self.__z

class Polsphera:
    def __init__(self, x=0, y=0, z=0, r=1):
        self.__p = Point(x, y, z)
        self.__r = r

    def input_polsphera(self):
        self.__p.input_point()
        self.__r = float(input("Введите радиус: "))

    def output_polsphera(self):
        print(f"Половина шара: центр {self.__p.get_coordinates()}, радиус {self.__r}")

    def get_center(self):
        return self.__p.get_coordinates()

    def get_r(self):
        return self.__r
    
    def is_point_in_polsphera(self, point):
        px, py, pz = point.get_coordinates()
        cx, cy, cz = self.__p.get_coordinates()
        return (px - cx) ** 2 + (py - cy) ** 2 + (pz - cz) ** 2 <= self.__r ** 2

def is_point_in_polsphera(point, polsphera):
    px, py, pz = point.get_coordinates()
    cx, cy, cz = polsphera.get_center()
    return (pz >= cz) and ((px - cx) ** 2 + (py - cy) ** 2 + (pz - cz) ** 2 <= polsphera.get_r() ** 2)

a = Point()
a.input_point()
a.output_point()
b = Polsphera()
b.input_polsphera()
b.output_polsphera()
print(is_point_in_polsphera(a, b))