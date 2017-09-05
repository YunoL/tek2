#ifndef FRUITNODE_H_
#define FRUITNODE_H_

#include "Fruit.h"

struct FruitNode
{
  Fruit* _fruit;
  FruitNode *next;
};

#endif
