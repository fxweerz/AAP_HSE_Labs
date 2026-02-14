/*
Разработать классы «точка» и «цилиндр». Члены-данные сделать закрытой частью
 в каждом классе.

Для каждого класса разработать два конструктора: по умолчанию и с параметрами
 для инициализации, деструкторы, методы ввода/вывода.

Разработать: метод класса «цилиндр» и функцию с двумя параметрами
 (точка и цилиндр) определения принадлежности точки цилиндру.
*/


#include <iostream>

using namespace std;

class Point{
int x, y, z;
public:
    Point(){
        x = 0;
        y = 0;
        z = 0;
    }
    Point(int x_, int y_, int z_){
        x = x_;
        y = y_;
        z = z_;
    }
    ~Point(){
        x = 0;
        y = 0;
        z = 0;
    }
    void input();
    void output();
    int get_x() {return x;}
    int get_y() {return y;}
    int get_z() {return z;}
};

class Cylinder{
    int r;
    int h;
    Point cent;
public:
    Cylinder(){
        r = 0;
        h = 0;
    }
    Cylinder(int r_, int h_, Point p_){
        r = r_;
        h = h_;
        cent = p_;
    }
    ~Cylinder(){
        r = 0;
        h = 0;
    }
    void input();
    void output();
    bool is_p_in(Point &p);
    int get_h() {return h;}
    int get_r() {return r;}
    Point get_cent() {return cent;}
};

bool is_p_in(Point &p, Cylinder &c);

int main(){
    Point p;
    p.input();
    Cylinder c;
    c.input();
    p.output();
    c.output();
    if(is_p_in(p,c)){
        cout << "Точка принадлежит цилиндру." << endl;
    } else {
        cout << "Точка не принадлежит цилиндру." << endl;
    }
    if(c.is_p_in(p)){
        cout << "Точка принадлежит цилиндру." << endl;
    } else {
        cout << "Точка не принадлежит цилиндру." << endl;
    }
    return 0;
}

void Point::input(){
    cout << "Введите координаты точки (x, y, z):" << endl;
    cin >> x >> y >> z;
}

void Point::output(){
    cout << "Точка с координатами (" << x << ", " << y << ", " << z << ")" << endl;
}

void Cylinder::input(){
    cout << "Введите радиус цилиндра: ";
    cin >> r;
    cout << "Введите высоту цилиндра: ";
    cin >> h;
    cent.input();
}

void Cylinder::output(){
    cout << "Цилиндр с радиусом " << r << " и высотой " << h << endl;
    cent.output();
}

bool Cylinder::is_p_in(Point &p){
    return ((p.get_z() <= h && p.get_z() >= 0) && 
    (p.get_x() * p.get_x() + p.get_y() * p.get_y() <= r * r)); 
}

bool is_p_in(Point &p, Cylinder &c){
    Point cent = c.get_cent();
    int dx = (p.get_x() - cent.get_x());
    int dy = (p.get_y() - cent.get_y());
    int dz = (p.get_z() - cent.get_z());
    return (dz <= c.get_h() && dz >= 0) && 
    ((dx * dx + dy * dy <= c.get_r() * c.get_r()));
}