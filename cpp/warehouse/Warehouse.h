#ifndef WAREHOUSE1_WAREHOUSE_H
#define WAREHOUSE1_WAREHOUSE_H

#include <string>
#include <vector>
#include <stack>
#include <memory>
#include "Shelves.h"

class Warehouse {
public:
    Warehouse(int m, int n) : M(m), N(n) {
        for (int i = 0; i < m; ++i) {
            warehouse.push_back(std::make_shared<Shelves>());
        }
    }

    ~Warehouse() {
        warehouse.clear();
    }

    int findSmallest(std::vector<std::shared_ptr<Shelves>> &warehouse);

    void acceptPackage(std::string, int);

    void addPackage();

    std::string issuePackage(std::string);

    void printWarehouse();

    bool checkKey(int);

    const int getM() const { return M; };

    const int getN() const { return N; };

    std::vector<std::shared_ptr<Shelves>> &getWarehouse() { return warehouse; }

private:
    const int M;
    const int N;
    std::vector<std::shared_ptr<Shelves>> warehouse;
};

#endif //WAREHOUSE1_WAREHOUSE_H
