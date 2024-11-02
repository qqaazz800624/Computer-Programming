#include <iostream>

using namespace std;

class Point2D{
    public:
        Point2D(){
            X = 0;
            Y = 0;
        }

        Point2D(int x, int y){
            X = x;
            Y = y;
        }

        void show2D(){
            cout << "X: " << X << endl;
            cout << "Y: " << Y << endl;
        }

        int getX(){
            return X;
        }

        int getY(){
            return Y;
        }

        void setX(int x){
            X = x;
        }

        void setY(int y){
            Y = y;
        }


    private:
        int X;
        int Y;
};

class Point3D : protected Point2D{
    public:
        Point3D(){
            Z = 0;
        }

        Point3D(int inX, int inY, int inZ) : Point2D(inX, inY){
            Z = inZ;
        }

        void show3D(){
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
    
    Point2D p2d1(3, 4), p2d2(10, 20);

    cout << "P2d1:\n";
    p2d1.show2D();
    cout << "P2d2:\n";
    p2d2.show2D();

    Point3D p3d1, p3d2;

    cout << "p3d1:\n";
    //p3d1.show2D();
    p3d1.show3D();
    cout << "p3d2:\n";
    p3d2.show3D();

    
    return 0;
}