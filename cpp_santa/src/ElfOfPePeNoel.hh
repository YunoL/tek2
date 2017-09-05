//
//  ElfOfPePeNoel.hpp
//  cpp_santa
//
//  Created by Valentin Pichard on 14/01/2017.
//
//

#ifndef ElfOfPePeNoel_hpp
#define ElfOfPePeNoel_hpp

#include <string>
#include <iostream>
#include "IElf.hh"

enum Buttons {
  IN,
  OUT,
};

class ElfOfPePeNoel : public IElf {
public:
  ElfOfPePeNoel(void);
  ~ElfOfPePeNoel(void);

  void            wrap(Wrap *, Object *);
  Wrap            *pressIN(void);
  void            pressOUT(Object *);
  std::string     *lookObjectTable(void);
  std::string     lookObjectConveyorBelt(void);
  void            setBelt(IConveyorBelt *);
  void            setTable(ITable *);

protected:
  Object *_obj;
  IConveyorBelt *_belt;
  ITable *_table;
};


#endif /* ElfOfPePeNoel_hpp */
