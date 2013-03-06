#ifndef UNITEFACTORY_H
#define UNITEFACTORY_H

#include "Header/Model/unite.h"

class UniteFactory
{
public:
    UniteFactory();
    virtual Unite* build() = 0;
};

#endif // UNITEFACTORY_H
