#ifndef WAREHOUSE1_SHELVES_H
#define WAREHOUSE1_SHELVES_H

#include <vector>
#include <memory>
#include "Package.h"

class Shelves {
public:
    std::vector<std::pair<int,std::shared_ptr<Package>>> &getShelves() { return shelves; }

private:
    std::vector<std::pair<int,std::shared_ptr<Package>>> shelves;
};

#endif //WAREHOUSE1_SHELVES_H
