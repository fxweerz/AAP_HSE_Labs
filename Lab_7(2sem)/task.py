'''
Разработать программу, которая должна содержать следующие функции:

ввод двумерного массива размерностью 5х4
вывод в консоль двумерного массива
формирования одномерного массива из элементов 
двумерного массива. Порядок элементов чередуется:
 А[1][1], A[1][2], A[2][1], А[1][3], A[2][2], A[3][1], и тд
нахождения максимальных элементов в каждом столбце в двумерном массиве
нахождения количества положительных значений, нулей, отрицательных значений 
в одномерном массиве
'''

def input_arr():
    print("Введите элементы массива 5x4:")
    return [[int(input()) for __ in range(4)] for _ in range(5)]

def print_arr(arr):
    print("\nИсходный массив:")
    for i in range(5): print(*arr[i])

def create_1_arr(arr):
    res = []
    for d in range(5 + 4 - 1):
        for i in range(5):
            j = d - i
            if 0 <= j < 4:
                res.append(arr[i][j])
    return res

def find_p_n_o(arr):
    p, z, o = 0, 0, 0
    for i in range(5):
        for j in range(4):
            if arr[i][j] > 0:
                p += 1
            elif arr[i][j] == 0:
                z += 1
            else:
                o += 1
    return p, z, o

def find_m(arr):
    m_arr = []
    for j in range(len(arr[0])):
        m = arr[0][j]
        for i in range(len(arr)):
            if arr[i][j] > m:
                m = arr[i][j]
        m_arr.append(m)
    return m_arr

arr = input_arr()
print_arr(arr)
brr = create_1_arr(arr)
print(*brr)
p, z, o = find_p_n_o(arr)
print(p, z, o)
print(*find_m(arr))