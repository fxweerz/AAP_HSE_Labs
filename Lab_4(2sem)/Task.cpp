/*
Разработать:

·        класс «2-мерный вектор» (алгебраический),

·        конструктор(ы) для инициализации,

·        перегруженные операторы << и >> потокового ввода/вывода,

·        перегруженную операцию || вычисления скалярного произведения векторов как метода (функцию-член класса),

·        перегруженную операцию + сложения двух векторов (функцию-друг класса).

·        В функции main организовать тестирование всех возможностей разработанного класса.
*/

#include <iostream>

using namespace std;

class Vector2D{
int x, y;
public:
    Vector2D() {
        x = 0;
        y = 0;
    }
    Vector2D(int _x, int _y) {
        x = _x;
        y = _y;
    }
    friend istream& operator>>(istream& in, Vector2D& v) {
        cout << "Enter x: ";
        in >> v.x;
        cout << "Enter y: ";
        in >> v.y;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Vector2D& v) {
        out << "(" << v.x << ", " << v.y << ")\n";
        return out;
    }
    int operator||(Vector2D& v){
        return (x*v.x + y*v.y);
    }
    friend Vector2D operator+(Vector2D&, Vector2D&);
};


int main(){
    Vector2D a;
    Vector2D b = Vector2D(2, 6);
    cin >> a;
    cout << a << b;
    cout << (a || b) << '\n';
    cout << (a+b);
}

Vector2D operator+(Vector2D& a, Vector2D& c){
        Vector2D res;
        res.x = a.x + c.x;
        res.y = a.y + c.y;
        return res;
}