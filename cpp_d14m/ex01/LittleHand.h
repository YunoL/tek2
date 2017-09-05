#ifndef LITTLEHAND_H_
#define LITTLEHAND_H_

#include "FruitBox.h"
#include "Banana.h"
#include "Lemon.h"
#include "Lime.h"

class LittleHand {
public:
  static void sortFruitBox(FruitBox& unsorted, FruitBox& lemons, FruitBox& bananas, FruitBox& limes);
};

#endif
