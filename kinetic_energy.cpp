/*
This is my first C++ program!
It shows a message on the console.
*/
#include <iostream> // header for std::cout
#include <iomanip>  // header for std::setprecision

// Function prototype for kinetic energy calculation
double kinetic_energy(double mass, double velocity);

// Main function (program entry point)
int main() 
{
    double energy = kinetic_energy(15, 300); // Calculate kinetic energy

    // Output the result using C++-style I/O
    std::cout << std::fixed << std::setprecision(3); // Set precision to 3 decimal places
    std::cout << "The value of the kinetic energy is: " << energy << " joules" << std::endl;

    return 0;
}

// User-defined function to calculate kinetic energy
double kinetic_energy(double mass, double velocity)
{
    return 0.5 * mass * velocity * velocity; // Kinetic energy formula
}
