#ifndef WAREHOUSE1_PACKAGE_H
#define WAREHOUSE1_PACKAGE_H

#include <string>

class Package {
public:
    std::string getPackageName() const { return namePackage; }

private:
    std::string namePackage;
};

#endif //WAREHOUSE1_PACKAGE_H



