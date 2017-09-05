#include <iostream>
#include "Toy.h"
#include "ToyStory.h"
#include "Buzz.h"
#include "Woody.h"

int main()
{
  Buzz  b("buzzi");
  Woody w("wood");
  ToyStory::tellMeAStory("GoodStory.txt", b, &Toy::speak_es, w, &Toy::speak);
}
