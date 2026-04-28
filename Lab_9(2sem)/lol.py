'''
Разработать класс «2-мерный вектор», конструктор для 
инициализации, метод ввода, метод вывода __str__, перегруженную 
операцию < (меньше) сравнения длин дух векторов. 

Создать собственное исключение при проверке равенства одной 
из координат нулю при инициализации и любом обновлении.  

В вводе добавить обработку этого исключения: вывести сообщение 
и вызвать метод ввода еще раз. 

В главной функции организовать тестирование всех возможностей 
разработанного класса.
'''
class My_err(Exception):
    pass

class Vector_2D:
    def __init__(self, x=1, y=1):
        self.__x = x
        self.__y = y
        if self.__x == 0 or self.__y == 0:
            raise My_err("Координаты не могут быть равны нулю.")
    
    def input_vector(self):
        while True:
            try:
                self.__x = float(input("Введите координату X: "))
                self.__y = float(input("Введите координату Y: "))
                if self.__x == 0 or self.__y == 0:
                    raise My_err("Координаты не могут быть равны нулю.")
                break
            except My_err as e:
                print(e)
                print("Пожалуйста, введите координаты снова.")

    def __str__(self):
        return f"Вектор: ({self.__x}, {self.__y})"

    def get_coord(self):
        return self.__x, self.__y

    def __lt__(self, other):
        ox, oy = other.get_coord()
        return (self.__x)**2 + (self.__y)**2 < (ox)**2 + (oy)**2

def main():
    v1 = Vector_2D()
    v1.input_vector()
    print(v1)
    v2 = Vector_2D(0, 4)
    print(v2)
    print(v1 < v2)
    try:
        v3 = Vector_2D(0, 5)
    except My_err as e:
        print(e)

if __name__ == "__main__":
    main()