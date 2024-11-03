#include <iostream>

using namespace std;

class Point1D{
    public:
        Point1D(){
            X = 0;
        }

        Point1D(int x){
            X = x;
        }

        void show1D(){
            cout << "X: " << X << endl;
        }

        int getX(){
            return X;
        }

        void setX(int x){
            X = x;
        }

    private:
        int X;
};

class Point2D : protected Point1D{
    public:
        Point2D(){
            Y = 0;
        }

        Point2D(int x, int y) : Point1D(x){
            Y = y;
        }

        void show2D(){
            show1D();
            cout << "Y: " << Y << endl;
        }

        int getY(){
            return Y;
        }

        void setY(int y){
            Y = y;
        }

    private:
        int Y;
};

class Point3D : public Point2D{
    public:
        Point3D(){
            Z = 0;
        }

        Point3D(int x, int y, int z) : Point2D(x, y){
            Z = z;
        }

        void show3D(){
            show1D();
            show2D();
            cout << "Z: " << Z << endl;
        }

        int getZ(){
            return Z;
        }

        void setZ(int z){
            Z = z;
        }

    private:
        int Z;
};


int main(){
    
    Point1D p1d1, p1d2(99);
    cout << "P1d1: " << endl;
    p1d1.show1D();
    cout << "P1d2: " << endl;
    p1d2.show1D();

    Point2D p2d1(3,4), p2d2(10,20);
    cout << "P2d1: " << endl;
    //p2d1.show1D();
    p2d1.show2D();
    cout << "P2d2: " << endl;
    p2d2.show2D();
    
    Point3D p3d1;
    cout << "P3d1: " << endl;
    p3d1.show3D();
    
    return 0;
}