#include <iostream>

using namespace std;

class Point2D{
    public:
        Point2D(){
            X = 0;
            Y = 0;
        }

        Point2D(int inX, int inY){
            X = inX;
            Y = inY;
        }

        void show2D(){
            cout << "X: " << X << endl;
            cout << "Y: " << Y << endl;
        }

        void show2D2(){
            cout << "X=" << X;
            cout << ", Y: " << Y;
        }

        //Point2D adder(Point2D &in){
        Point2D operator+(Point2D &in){
            int rx = X + in.X;
            int ry = Y + in.Y;
            Point2D Result(rx, ry);
            return Result;
        }

        Point2D operator+(int in){
            int rx = X + in;
            int ry = Y + in;
            Point2D Result(rx, ry);
            return Result;
        }

        Point2D operator-(Point2D &in){
            int rx = X - in.X;
            int ry = Y - in.Y;
            Point2D Result(rx, ry);
            return Result;
        }

        Point2D operator*(Point2D &in){
            int rx = X * in.X;
            int ry = Y * in.Y;
            Point2D Result(rx, ry);
            return Result;
        }

    private:
        int X;
        int Y;
};

int main(){

    int x, y;
    cin >> x >> y;
    Point2D p1(x,y);
    cin >> x >> y;
    Point2D p2(x,y), p3;
  
    p3 = p1 * p2;
    cout << "Result: ";
    p3.show2D2();
    cout << endl;

    return 0;
}