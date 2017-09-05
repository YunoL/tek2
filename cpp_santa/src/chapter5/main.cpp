//
// main.cpp for  in /Users/sypzowski/Desktop/pool/rush_cpp_2/p4/
//
// Made by Steven Syp
// Login   <steven.syp@epitech.eu@epitech.eu>
//
// Started on  Sat Jan 14 17:33:40 2017 Steven Syp
// Last update Sat Jan 14 17:50:15 2017 Steven Syp
//


#include "ConveyorBeltPePeNoel.hh"
#include "TablePePeNoel.hh"
#include "ElfOfPePeNoel.hh"

int main() {
  // initial values
  TablePePeNoel *table = new TablePePeNoel();
  ConveyorBeltPePeNoel *belt = new ConveyorBeltPePeNoel();
  ElfOfPePeNoel *elf = new ElfOfPePeNoel();

  // Setup elf fields
  elf->setTable(table);
  elf->setBelt(belt);

  // add item to table
  table->put(new Teddy("ted"));

  Toy *obj = static_cast<Toy*>(table->take(0));
  Wrap *wrap = elf->pressIN();
  std::cout << obj << " : from table" << std::endl;
  if (wrap->getType() == "giftpaper") {
    GiftPaper *giftpaper = static_cast<GiftPaper*>(wrap);
    elf->wrap(giftpaper, obj);
    elf->pressOUT(obj);
  } else {
    Wrap *gift = new GiftPaper("paper");
    gift->wrapMeThat(obj);
    elf->pressOUT(obj);
  }
  return 0;
}
