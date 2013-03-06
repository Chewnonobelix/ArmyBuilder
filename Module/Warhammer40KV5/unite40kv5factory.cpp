#include "unite40kv5factory.h"

Unite40KV5Factory::Unite40KV5Factory()
{
}

UniteWarhammer40KV5* Unite40KV5Factory::build()
{
    return new UniteWarhammer40KV5;
}
