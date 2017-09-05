//
// TablePePeNoel.cpp for in .../rush_cpp_2
//
// Made by  syp_s
// Login    <steven.syp@epitech.eu@epitech.eu>
//
// Started on  14/01/2017 Steven Syp
//

#include "TablePePeNoel.hh"

ITable::~ITable() {}

TablePePeNoel::TablePePeNoel() {
  int i = 0;

  while (i < 10)
    this->_tableObjects[i++] = NULL;
}

TablePePeNoel::~TablePePeNoel() {
  int i = 0;

  while (i < 10) {
    if (this->_tableObjects[i]) {
      delete this->_tableObjects[i];
      this->_tableObjects[i] = NULL;
    }
    i++;
  }
}

bool TablePePeNoel::put(Object* obj) {
  for (size_t i = 0; i < 10; i++) {
    if (this->_tableObjects[i] == NULL) {
      this->_tableObjects[i] = obj;
      return true;
    }
  }
  std::cerr << "The table is full !" << '\n';
  return false;
}

Object *TablePePeNoel::take(int pos) {
  if (this->_tableObjects[pos] != NULL) {
    Object* tmp = this->_tableObjects[pos];
    this->_tableObjects[pos] = NULL;
    return tmp;
  }
  std::cerr << "The Object does not exist !" << '\n';
  return NULL;
}

std::string *TablePePeNoel::look() {
  std::string *objectNames = new std::string[10];
  int i, j = 0;

  for (i = 0 ; i < 10; i++)
    if (this->_tableObjects[i])
      objectNames[j++] = this->_tableObjects[i]->getName();
  while (j < 10)
    objectNames[j++] = "";
  if (!j) {
    std::cerr << "The table's empty." << '\n';
    return NULL;
  }
  return objectNames;
}

size_t TablePePeNoel::getTableLength() {
    size_t nb = 0;
    for (size_t i = 0; i < 10; i++) {
        if (this->_tableObjects[i] != NULL)
            nb++;
    }
    return nb;
}

ITable *createTable() {
  ITable* tab = new TablePePeNoel;
  tab->put(new Teddy("nounours"));
  tab->put(new LittlePony("gay pony"));
  tab->put(new Box("boite"));
  tab->put(new GiftPaper("papier"));
  tab->put(new Box("boite/20"));
  tab->put(new GiftPaper("PQ"));
  return tab;
}
