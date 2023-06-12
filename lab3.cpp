#include <iostream>

class PC {
private:
    double cpu_speed;
    int hd_capacity;
    int ram_capacity;
    double cost;

public:
    PC() {
        cpu_speed = 2.2;
        hd_capacity = 500;
        ram_capacity = 8;
        cost = calculateCost();
    }

    PC(double speed, int hd, int ram) {
        cpu_speed = speed;
        hd_capacity = hd;
        ram_capacity = ram;
        cost = calculateCost();
    }

    void getPCDetails() {
        std::cout << "Please enter the speed of CPU in GHz: ";
        std::cin >> cpu_speed;
        std::cout << "Please enter the size of the hard disk in GB: ";
        std::cin >> hd_capacity;
        std::cout << "Please enter the size of the RAM in GB: ";
        std::cin >> ram_capacity;
        cost = calculateCost();
    }

    double calculateCost() {
        return 500 + cpu_speed * 100 + hd_capacity * 0.05 + ram_capacity * 10;
    }

    void displayPCDetails() {
        std::cout << "CPU Speed: " << cpu_speed << " GHz" << std::endl;
        std::cout << "Hard Disk Capacity: " << hd_capacity << " GB" << std::endl;
        std::cout << "RAM Capacity: " << ram_capacity << " GB" << std::endl;
        std::cout << "Cost: $" << cost << std::endl;
    }
};

int main() {
    int numPCs;
    std::cout << "Enter the number of PCs to be purchased: ";
    std::cin >> numPCs;

    PC* pcs = new PC[numPCs];

    for (int i = 0; i < numPCs; i++) {
        std::cout << "\nEnter details for PC " << i + 1 << ":" << std::endl;
        pcs[i].getPCDetails();
    }

    double totalCost = 0.0;
    std::cout << "\nPC Details:\n" << std::endl;


    for (int i = 0; i < numPCs; i++) {
        std::cout << "PC " << i + 1 << ":" << std::endl;
        pcs[i].displayPCDetails();
        totalCost += pcs[i].calculateCost();
        std::cout << std::endl;
    }

    std::cout << "Total Cost of all PCs: $" << totalCost << std::endl;

    delete[] pcs;

    return 0;
}
