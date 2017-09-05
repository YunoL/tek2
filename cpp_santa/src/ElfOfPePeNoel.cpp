//
//  ElfOfPePeNoel.cpp
//  cpp_santa
//
//  Created by Valentin Pichard on 14/01/2017.
//
//

#include "ElfOfPePeNoel.hh"

ElfOfPePeNoel::ElfOfPePeNoel()  {}
ElfOfPePeNoel::~ElfOfPePeNoel() {}

void ElfOfPePeNoel::wrap(Wrap *wrap, Object *obj) {
  wrap->wrapMeThat(obj);
}

Wrap            *ElfOfPePeNoel::pressIN(void) {
    if (this->_belt != NULL)
        return this->_belt->IN();
    return NULL;
}

void            ElfOfPePeNoel::pressOUT(Object *obj) {
    if (this->_belt != NULL)
      this->_belt->OUT(obj);
}

std::string     *ElfOfPePeNoel::lookObjectTable(void) {
    if (this->_table != NULL)
        return (this->_table->look());
    return NULL;
}

std::string     ElfOfPePeNoel::lookObjectConveyorBelt(void) {
    if (this->_belt != NULL)
        return (this->_belt->look());
    return NULL;
}

void            ElfOfPePeNoel::setBelt(IConveyorBelt *belt) {
    this->_belt = belt;
}

void            ElfOfPePeNoel::setTable(ITable *table) {
    this->_table = table;
}
