/*
Разработать базовый класс «Объемная фигура в 3-мерном пространстве» и разработать в нем:

·         конструктор(ы),

·         методы вывода на экран координат точки привязки фигуры (в консольном режиме)

·         установки (сдвига) фигуры в заданную точку,

·         виртуальную функцию вычисления объема фигуры,

·         виртуальную функцию растяжения по оси Z.

Разработать порожденный класс «Шаровой сегмент», разработать в нем:

·         конструктор, наследующий конструктор базового класса,

·         метод вывода на экран основных параметров фигуры,

·         метод растяжения фигуры по радиусу,

·         метод вычисления объема.

Разработать отдельную функцию сравнения объемов двух объемных фигур. (возвращает в точку вызова процентное соотношение объемов)

В функции main организовать тестирование всех возможностей разработанных классов.
*/

#include <iostream>

using namespace std;

class Figure3D{
protected:
    int x, y, z;
public:
    Figure3D() {
        x = 0;
        y = 0;
        z = 0;
    }
    Figure3D(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }
    void printCoord(){
        cout << "x: " << x << ", y: " << y << ", z: " << z << '\n';
    }
    void moveTo(int _x, int _y, int _z){
        x = _x;
        y = _y;
        z = _z;
    }
    virtual double v() {return 0.0;}
    virtual void rast(double R_) {}
};

class SpherSegm : public Figure3D{
double h, R;
public:
    SpherSegm() : Figure3D() {
        h = 0;
        R = 0;
    }
    SpherSegm(int _x, int _y, int _z, int _h, int _r) : Figure3D(_x, _y, _z){
        h = _h;
        R = _r;
    }
    void print(){
        cout << "Radius: " << R << ", Height: " << h << '\n';
        printCoord();
    }
    void rast(double R_) {
        R = R_;
    }
    double v(){
        return 3.14*h*h*(R - h/3);
    }
};

double comp(Figure3D& a, Figure3D& b){
    return (a.v()/b.v())*100;
}

int main(){
    Figure3D c(1,2,3);
    c.printCoord();
    SpherSegm a(1, 2, 3, 4, 5);
    SpherSegm b(2, 3, 4, 5, 6);
    a.print();
    b.print();
    cout << "V_a: " << a.v() << '\n';
    cout << "V_b: " << b.v() << '\n';
    cout << "comp(a, b): " << comp(a, b) << "%\n";
    a.moveTo(4,5,6);
    a.print();
    b.rast(10);
    b.print();
    cout << "comp(a, b): " << comp(a, b) << "%\n";
}
