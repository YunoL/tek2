#include "TableRand.hh"

TableRand::TableRand() {
  for (size_t i = 0; i < 10; i++) {
    int j = rand() % 4;
    if (j == 0)
      this->_tableObjects[i] = new Teddy("nounours");
    else if (j == 1)
      this->_tableObjects[i] = new LittlePony("gay pony");
    else if (j == 2)
      this->_tableObjects[i] = new Box("boite");
    else
      this->_tableObjects[i] = new GiftPaper("ribbon");
  }
}

TableRand::~TableRand() {
    for (size_t i = 0; i < 10; i++) {
      if (this->_tableObjects[i])
        delete this->_tableObjects[i];
    }
}
