//
// main.cpp<chapter2> for  in /home/zeng_d
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Sun Jan 15 00:05:11 2017 David Zeng
// Last update Sun Jan 15 00:05:11 2017 David Zeng
//

#include "Object.hh"
#include "LittlePony.hh"
#include "Teddy.hh"
#include "Toy.hh"
#include "Box.hh"
#include "GiftPaper.hh"

Object **MyUnitTests() {
  Object **obj = new Object*[3];

  obj[0] = new LittlePony("gay pony");
  obj[1] = new Teddy("bisounours");
  obj[2] = NULL;
  return obj;
}

void unitTest() {
  Object **obj = MyUnitTests();

  if (!obj) {
    std::cerr << "Error: This array is empty !" << std::endl;
    return;
  }

  std::cout << "MyUnitTests" << std::endl;
  for (size_t i = 0; obj[i] != NULL; i++) {

    // printing object metadata
    std::cout << "obj[" << i << "]:" << std::endl;
    std::cout << "NAME: " << obj[i] << std::endl;
    std::cout << "OBJECT TYPE: " << obj[i]->getType() << std::endl;

    if (obj[i]->getType() == "toy") {
      Toy *toy = static_cast<Toy*>(obj[i]);

      std::cout << "TOY TYPE: " << toy->getType() << std::endl;
      std::cout << "taking " << obj[i] << ": ";
      toy->isTaken();
    } else {
      std::cerr << "TOY TYPE undefined" << std::endl;
    }

    std::cout << std::endl;
    // delete when done using it
    delete obj[i];
  }
  delete[] obj;
}

int main() {
  unitTest();
  return 0;
}
