/*
Разработать класс «массив целых чисел произвольной размерности». Члены-данные сделать закрытой частью класса. 
В этом классе разработать методы:

·        Конструктор для инициализации: количество элементов и заполнение последовательностью четных чисел.

·        Деструктор

·        Ввода элементов с клавиатуры

·        Вывода элементов консоль

·        Подсчет количества значений в массиве, делящихся на 3 без остатка

·        Удаление элемента из начала массива с уменьшением памяти

Организовать проверку всех возможностей.
*/

#include <iostream>

using namespace std;


class IntArray {
int n;
int* arr;
public:
    IntArray(int size){
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = 2 * (i+1);
        }
    }
    ~IntArray(){
        delete[] arr;
    }
    void input(){
        cout << "Введите " << n << " целых чисел:";
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
    }
    void output(){
        cout << "Список целых чисел из " << n << " элементов:";
        for(int i = 0; i < n; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    int countDel3(){
        int count = 0;
        for(int i = 0; i < n;i++){
            if(arr[i]%3 == 0){
                count++;
            }
        }
        return count;
    }
    void deleteF(){
        if(n > 0){
            int* narr = new int[n-1];
            for(int i = 1; i < n; i++){
                narr[i-1] = arr[i];
            }
            delete[] arr;
            arr = narr;
            n--;
        }
    }
};

int main(){
    int n;
    cout << "Введите количество элементов в массиве: ";
    cin >> n;
    IntArray arr(n);
    arr.output();
    cout << "Количество чисел, делящихся на 3 без остатка: " << arr.countDel3() << endl;
    arr.deleteF();
    arr.output();
    cout << endl;

    IntArray arr1(n);
    arr1.input();
    arr1.output();
    cout << "Количество чисел, делящихся на 3 без остатка: " << arr1.countDel3() << endl;
    arr1.deleteF();
    arr1.output();
    return 0;
}