//
// ConveyorBeltPePeNoel.cpp for in .../rush_cpp_2
//
// Made by  syp_s
// Login    <steven.syp@epitech.eu@epitech.eu>
//
// Started on  14/01/2017 Steven Syp
//

#ifndef ConveyorBeltPePeNoel_hh_
# define ConveyorBeltPePeNoel_hh_

# include <iostream>
# include <string>
# include <time.h>
# include <cstdlib>
# include "Wrap.hh"
# include "GiftPaper.hh"
# include "Box.hh"

class IConveyorBelt {
public:
  virtual ~IConveyorBelt();
  virtual Wrap *IN() = 0;
  virtual bool OUT(Object *obj) = 0;
  virtual std::string const look() = 0;
};


class ConveyorBeltPePeNoel : public IConveyorBelt {
public:
  ConveyorBeltPePeNoel();
  ~ConveyorBeltPePeNoel();
  Wrap *IN();
  bool OUT(Object *obj);
  std::string const look();

private:
  Wrap* _actWrap;
};

IConveyorBelt*  createConveyorBelt();

#endif /* ConveyorBeltPePeNoel_hpp */
