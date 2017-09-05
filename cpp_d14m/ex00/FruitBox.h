#ifndef FRUITBOX_H_
#define FRUITBOX_H_

#include <iostream>
#include "FruitNode.h"
#include "Fruit.h"

class FruitBox {
public:
  FruitBox(int size);
  virtual ~FruitBox();
  int nbFruits() const;
  bool putFruit(Fruit* f);
  Fruit* pickFruit();
  FruitNode* head() const;
protected:
  int _size;
  int _count;
  FruitNode* header;
};

#endif
