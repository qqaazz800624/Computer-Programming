/*
This is my first C++ program!
It shows a message on the console.
*/
# include <cstdio>
# include <iostream> // header for std::cout
# include <iomanip> // header for std::setprecision
using namespace std;

double kinetic_energy(int, double);
// The main function
int main() // program entry
{
    double energy;
    energy = kinetic_energy(15, 300);
    printf("The value of the kinetic energy is: %.3f\n", energy);
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "The value of the kinetic energy is: " << energy << std::endl;
    cout << "The value of the kinetic energy is: " << energy << endl;
    return 0;
}
// user-defined function
double kinetic_energy(int m, double v)
{
    double ke;
    ke = 0.5 * m * v * v;
    return ke;
}