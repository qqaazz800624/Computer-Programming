#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip> 

using namespace std;

class Data {
    public:
        string type;
        int buy;
        int sell;
};

Data carlist[6] = {
    {"BMW", 8000, 20000},
    {"Volkswagen", 7000, 18000},
    {"Ferrari", 12000, 35000},
    {"Proton", 4000, 50000},
    {"Audi", 10000, 30000},
    {"Lamborghini", 15000, 40000}
};

class Start_a_business {
    private:
        vector<string> Garage; 
        int car;
        int sellprice;         
        int totalcost;        
        int earn;         

    public:
        Start_a_business() {
            sellprice = 0;
            totalcost = 0;
            earn = 0;
            car = 0;
            Garage.clear();
        }

        void store(const string &x) {
            if (Garage.size() >= 10) {
                cout << "Garage FULL!\nCar not stored!\n";
                return;
            }
            for (int i = 0; i < 6; i++) {
                if (carlist[i].type == x) {
                    Garage.push_back(x);
                    totalcost += carlist[i].buy;
                    sellprice += carlist[i].sell;
                    earn -= carlist[i].buy;
                    car++;
                    cout << "Store in a car.\nType: " << x
                        << "\nnumber car in garage: " << Garage.size() << endl;
                    return;
                }
            }
            cout << "Car type not recognized.\n";
        }

        void sell(const string &x) {
            for (size_t i = 0; i < Garage.size(); i++) {
                if (Garage[i] == x) {
                    for (int j = 0; j < 6; j++) {
                        if (carlist[j].type == x) {
                            sellprice -= carlist[j].sell;
                            earn += carlist[j].sell;
                            car--;
                            cout << "You sell a car.\nType: " << x
                                << "\nSell price: " << carlist[j].sell
                                << "\nnumber car left in garage: " << Garage.size() - 1 << endl;
                            Garage.erase(Garage.begin() + i); 
                            return;
                        }
                    }
                }
            }
            cout << "Car not found!\n";
        }

        void displayi() const {
            cout << "Sell price= " << sellprice << endl;
        }

        void displaycost() const {
            cout << "Total cost= " << totalcost << endl;
        }

        void displayp() const {
            cout << "Profit= " << earn << endl;
        }
};

int main() {
    Start_a_business garage;
    char command;
    string car_type;

    while (1) {
        cin >> command;
        switch (command){
            case 'a':
                cin >> car_type;
                garage.store(car_type);
                break;
            case 's':
                cin >> car_type;
                garage.sell(car_type);
                break;
            case 'c':
                garage.displaycost();
                break;
            case 'i':
                garage.displayi();
                break;
            case 'p':
                garage.displayp();
                break;
            case 'q':
                cout << "Thank you for visiting XMing_Garage. Bye bye." << endl;
                return 0;
            default:
                cout << "Invalid command." << endl;
        }
    }

    return 0;
}
