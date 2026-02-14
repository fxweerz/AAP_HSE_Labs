/*
Разработать структуру «Двумерный массив», в котором будет храниться
 сам cтатический массив n = 10 и его размерности, заданные пользователем.
  В программе объявить прототипы функций. 
Разработать функции:
ввода двумерного массива, 
вывода двумерного массива, 
формирования одномерного массива из всех столбцов, 
расчета суммы значений элементов побочной диагонали двумерного массива
 (проверить массив на равенство размерностей вернуть значение в главную функцию),
поиска количества элементов больших меньшего из двух полученных значений и меньших
 большего в одномерном массиве (в одной функции, вернуть оба значения в главную функцию).
Организовать тестирование всех возможностей программы.
*/


#include <iostream>

using namespace std;

struct Matrix{
    int i;
    int j;
    int arr[10][10];
};

void input_matrix(Matrix& m){
    cout << "Введите количество строк (до 10) и количество столбцов (до 10): ";
    cin >> m.i >> m.j;
    cout << "Введите элементы матрицы:" << endl;
    for(int x = 0; x < m.i; x++){
        for(int y = 0; y < m.j; y++){
            cin >> m.arr[x][y];
        }
    }
}

void output_matrix(Matrix& m){
    cout << "Матрица:" << endl;
    for(int x = 0; x < m.i; x++){
        for(int y = 0; y < m.j; y++)
            cout << m.arr[x][y] << " ";
        cout << endl;
    }
}

void from_collums(Matrix& m, int* arr){
    for(int i = 0; i < m.j; i++){
        for(int j = 0; j < m.i; j++)
            arr[i * m.i + j] = m.arr[j][i];
    }
}

void output_array(int* arr, int size){
    cout << "Одномерный массив из столбцов:" << endl;
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int sum_from_diag(Matrix& m){
    int sum = 0;
    for(int i = 0; i < m.i; i++){
        for(int j = 0; j < m.j; j++){
            if(i + j == m.i - 1)
                sum += m.arr[i][j];
        }
    }
    return sum;
}

void counter(int* arr, int size, int k, int l){
    int c1 = 0, c2 = 0;
    int maxn, minn;
    if(k > l){
        maxn = k;
        minn = l;
    } else {
        maxn = l;
        minn = k;
    }
    for(int i = 0; i < size; i++){
        if(arr[i] > minn)
            c1++;
        if(arr[i] < maxn)
            c2++;
    }
    cout << "количества элементов больших меньшего из двух полученных значений: " << c1 << endl;
    cout << "количества элементов меньших большего из двух полученных значений: " << c2 << endl;
}

int main(){
    Matrix m;
    input_matrix(m);
    output_matrix(m);

    int* arr = new int[m.j * m.i];
    from_collums(m, arr);
    output_array(arr, m.i * m.j);

    if(m.i != m.j)
        cout << "Матрица не квадратная" << endl;
    else {
        int sum = sum_from_diag(m);
        cout << "Сумма побочной диагонали: " << sum << endl;
    }

    int k, l;
    cout << "Введите два числа: " << endl;
    cin >> k >> l;
    counter(arr, m.i * m.j, k, l);
}