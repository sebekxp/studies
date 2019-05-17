#include <iostream>
#include "Warehouse.h"
#include <memory>

int main() {
    int numShelves, sizeShelves = 0;
    std::cout << "Number/size of Shelves: ";
    std::cin >> numShelves >> sizeShelves;

    Warehouse w(numShelves, sizeShelves);
    w.addPackage();
    w.printWarehouse();

    std::cout<<"The name of the package you want to find: ";
    std::string namePackage;
    std::cin.ignore();
    getline(std::cin, namePackage);

    w.issuePackage(namePackage);
    std::cout<<"After pop_back\n";
    w.printWarehouse();


    return 0;
}