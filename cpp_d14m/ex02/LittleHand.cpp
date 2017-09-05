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

int boxLength(Coconut const* const* coconuts_packet)
{
  int i = 0;
  while (coconuts_packet[i])
    i++;
  return i;
}

FruitBox* const* LittleHand::organizeCoconut(Coconut const* const* coconuts_packet)
{
  if (!coconuts_packet)
    return NULL;
  int i = 0;
  int count = 0;
  int nb_box = (boxLength(coconuts_packet) / 6);
  if (boxLength(coconuts_packet) % 6 != 0)
    nb_box++;
  FruitBox**  box = new FruitBox*[nb_box + 1];
  while (i  < nb_box)
  {
    box[i] = new FruitBox(6);
    for (size_t x = 0; x < 6; x++) {
      if (count < boxLength(coconuts_packet))
        box[i]->putFruit(const_cast<Coconut*>(coconuts_packet[count]));
      else
      {
        box[i]->putFruit(NULL);
        break;
      }
      count++;
    }
    i++;
  }
  box[i] = NULL;
  return box;
}
