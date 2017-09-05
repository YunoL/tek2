#include "LittleHand.h"
#include <iostream>

void LittleHand::sortFruitBox(FruitBox& unsorted, FruitBox& lemons, FruitBox& bananas, FruitBox& limes)
{
    Fruit*  fruit;
    FruitBox tmp(unsorted.nbFruits());
    while ((fruit = unsorted.pickFruit()))
      tmp.putFruit(fruit);
    while ((fruit = tmp.pickFruit()))
    {
      if (dynamic_cast<Banana*>(fruit) && fruit->getVitamins() == 5 && bananas.nbFruits() < bananas.getSize())
        bananas.putFruit(fruit);
      else if (dynamic_cast<Lime*>(fruit) && limes.nbFruits() < limes.getSize())
        limes.putFruit(fruit);
      else if (dynamic_cast<Lemon*>(fruit) && lemons.nbFruits() < lemons.getSize())
        lemons.putFruit(fruit);
      else
        unsorted.putFruit(fruit);
    }
}
