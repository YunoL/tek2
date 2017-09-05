//
// IElf.hh for IElf in /home/zeng_d/rendu/PiscineCPP/cpp_santa
//
// Made by David Zeng
// Login   <zeng_d@epitech.net>
//
// Started on  Sat Jan 14 16:07:01 2017 David Zeng
// Last update Sat Jan 14 22:47:42 2017 Valentin Pichard
//

#ifndef IELF_HH_
# define IELF_HH_

# include <string>
# include "Wrap.hh"
# include "TablePePeNoel.hh"
# include "ConveyorBeltPePeNoel.hh"

class IElf {
public:
  virtual ~IElf(void) {}

  virtual void          wrap(Wrap *, Object*) = 0;
  virtual Wrap          *pressIN(void) = 0;
  virtual void          pressOUT(Object *) = 0;
  virtual std::string   *lookObjectTable(void) = 0;
  virtual std::string   lookObjectConveyorBelt(void) = 0;
  virtual void          setBelt(IConveyorBelt *) = 0;
  virtual void          setTable(ITable *) = 0;
};

#endif /* !IELF_HH_ */
