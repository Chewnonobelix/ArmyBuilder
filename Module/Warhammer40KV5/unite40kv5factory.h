#ifndef UNITE40KV5FACTORY_H
#define UNITE40KV5FACTORY_H

#include "Module/Warhammer40KV5/unitewarhammer40kv5.h"
#include "Header/Model/unitefactory.h"

class Unite40KV5Factory: public UniteFactory
{
public:
    Unite40KV5Factory();
    UniteWarhammer40KV5* build();
};

#endif // UNITE40KV5FACTORY_H
