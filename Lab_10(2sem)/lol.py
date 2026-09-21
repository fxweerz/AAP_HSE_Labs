'''
Разработайте две программы:

·        Сформировать массив значений по заданной функции и 
записать полученные данные во внешний файл.

·        Считать данные из полученного файла, построить 
по полученным данным график. На графике: выделить линию нуля 
по оси ох, подписать названия графика и осей, настроить сетку.
'''

import numpy as np
import matplotlib.pyplot as plt

def f(x):
    return 5 * np.cos(0.3 * np.pi * x - 1)

def main():
    arr = np.array([[x_, f(x_)] for x_ in np.arange(-50, 50, 0.1)])
    with open("Lab_10(2sem)/data.txt", "w") as file:
        for i in arr: file.write(f"{i[0]} {i[1]}\n")
    with open("Lab_10(2sem)/data.txt", "r") as file:
        x, y = np.array([]), np.array([])
        for i in file:
            x = np.append(x, float(i.strip().split()[0]))
            y = np.append(y, float(i.strip().split()[1]))
    plt.plot(x, y,  label='f(x)')
    plt.axhline(0, color='red', label='y = 0')
    plt.xlabel("x")
    plt.ylabel("y")
    plt.grid(True)
    plt.legend(loc='upper right')
    plt.show()

if __name__ == "__main__":
    main()