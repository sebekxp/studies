#include "Warehouse.h"
#include <iostream>
#include <exception>
#include <fstream>

void Warehouse::acceptPackage(std::string s, int key) {
    int minIndex = findSmallest(warehouse);
    if (this->getWarehouse()[minIndex]->getShelves().size() == this->getN())
        throw "All shelves are full, you can not add more packages";

    if (checkKey(key))
//        this->getWarehouse()[minIndex]->getShelves().push_back(std::make_pair(key,std::make_shared<Package>(s)));
        this->getWarehouse()[minIndex]->getShelves().emplace_back(key, std::make_shared<Package>(s));
    else
        throw "You can not add packages with the same key";
    key++;

}

bool Warehouse::checkKey(int tempKey) {
    for (auto &i : this->getWarehouse()) {
        for (auto &j : i->getShelves())
            if (j.first == tempKey)
                return false;
    }
    return true;

}

int Warehouse::findSmallest(std::vector<std::shared_ptr<Shelves>> &warehouse) {
    int index = 0;
    bool flag = true;
    int min = this->getWarehouse()[index]->getShelves().size();
    for (int i = 1; i < this->getM(); ++i) {
        if (this->getWarehouse()[i]->getShelves().size() < min && flag) {
            index = i;
            flag = false;
        }
    }
    return index;
}

void Warehouse::addPackage() {
    bool decision = true;
    std::fstream file;
    std::string sTemp;
    int key = 0;
    char ch = 0;
    while (decision) {
        std::cout << "The name of the package: \n";
        std::cin.ignore();
        getline(std::cin, sTemp);
        int key = 0;
        std::cout << "Key of the package: ";
        std::cin >> key;
        try {
            this->acceptPackage(sTemp, key);
        }
        catch (const char *msg) {
            std::cout << msg << std::endl;
        }
        std::cout << "Add another package: [y/n]";
        std::cin >> ch;
        if (ch == 'n')
            decision = false;
    }

//
//    std::ofstream myfile;
//    myfile.open ("dane.txt");
//    myfile.close();
//    file.open("dane.txt");
//    if(file.good())
//    {
//        while(!file.eof())
//        {
//            file >> key >>sTemp;
//            try {
//                this->acceptPackage(sTemp, key);
//            }
//            catch (const char *msg) {
//                std::cout << msg << std::endl;
//            }
//        }
//        file.close();
//    }
}

std::string Warehouse::issuePackage(std::string namePackage) {
    int ii = 0;
    /*
        for (auto i = this->getWarehouse().begin();i != this->getWarehouse().end(); ++i) {
        for(auto j = (*i)->getShelves().begin(); j != (*i)->getShelves().end(); j++)
    */
    for (auto &i : this->getWarehouse()) {
        for (auto &j : i->getShelves()) {
            if (j.second->getPackageName() == namePackage) {
                std::cout << this->getWarehouse()[ii]->getShelves()[getN() - 1].second << std::endl;
                this->getWarehouse()[ii]->getShelves().pop_back();
            }
        }
        ii++;
    }
}

void Warehouse::printWarehouse() {
    int ii = 1;
    for (auto &i : this->getWarehouse()) {
        std::cout << "Shelves " << ii << ": ";
        for (auto &j : i->getShelves())
            std::cout << "[" << j.first << " | " << j.second->getPackageName() << "]" << " ";
        std::cout << std::endl;
        ii++;
    }
}