#include <stdio.h>
#include <string.h>

typedef struct {
    char type[16];
    int buy;
    int sell;
} Data;

Data carlist[6] = {
    {"BMW", 8000, 20000},
    {"Volkswagen", 7000, 18000},
    {"Ferrari", 12000, 35000},
    {"Proton", 4000, 50000},
    {"Audi", 10000, 30000},
    {"Lamborghini", 15000, 40000}
};


typedef struct {
    char Garage[10][16];
    int car;        
    int sellprice;  
    int totalcost;  
    int earn;       
} XMingGarage;


void Start_a_business(XMingGarage *garage) {
    garage->car = 0;
    garage->sellprice = 0;
    garage->totalcost = 0;
    garage->earn = 0;
    for (int i = 0; i < 10; i++) {
        strcpy(garage->Garage[i], "");
    }
}

void store(XMingGarage *garage, char x[16]) {
    if (garage->car >= 10) {
        printf("Garage FULL!\nCar not stored!\n");
        return;
    }
    for (int i = 0; i < 6; i++) {
        if (strcmp(carlist[i].type, x) == 0) {
            strcpy(garage->Garage[garage->car], x);
            garage->car++;
            garage->totalcost += carlist[i].buy;
            garage->sellprice += carlist[i].sell;
            garage->earn -= carlist[i].buy; 
            printf("Store in a car.\nType: %s\nnumber car in garage: %d\n", x, garage->car);
            return;
        }
    }
    printf("Car type not recognized.\n");
}


void sell(XMingGarage *garage, char x[16]) {
    for (int i = 0; i < garage->car; i++) {
        if (strcmp(garage->Garage[i], x) == 0) {
            int matchedIndex = -1;
            for (int j = 0; j < 6; j++) {
                if (strcmp(carlist[j].type, x) == 0) {
                    matchedIndex = j;
                    garage->sellprice -= carlist[j].sell;
                    garage->earn += carlist[j].sell; 
                    break;
                }
            }
            if (matchedIndex != -1) {
                printf("You sell a car.\nType: %s\nSell price: %d\nnumber car left in garage: %d\n", x, carlist[matchedIndex].sell, garage->car - 1);
                for (int k = i; k < garage->car - 1; k++) {
                    strcpy(garage->Garage[k], garage->Garage[k + 1]);
                }
                garage->car--;
                return;
            }
        }
    }
    printf("Car not found!\n");
}

void displayi(XMingGarage *garage) {
    printf("Sell price= %d\n", garage->sellprice);
}

void displaycost(XMingGarage *garage) {
    printf("Total cost= %d\n", garage->totalcost);
}

void displayp(XMingGarage *garage) {
    printf("Profit= %d\n", garage->earn);
}

int main() {
    XMingGarage garage;
    Start_a_business(&garage);

    char command, car_type[16];
    while (1) {
        scanf(" %c", &command);
        if (command == 'q') {
            printf("Thank you for visiting XMing_Garage. Bye bye.\n");
            break;
        }
        switch (command) {
            case 'a':
                scanf(" %s", car_type);
                store(&garage, car_type);
                break;
            case 's':
                scanf(" %s", car_type);
                sell(&garage, car_type);
                break;
            case 'c':
                displaycost(&garage);
                break;
            case 'i':
                displayi(&garage);
                break;
            case 'p':
                displayp(&garage);
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
    }
    return 0;
}