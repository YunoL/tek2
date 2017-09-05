//
// TablePePeNoel.cpp for in .../rush_cpp_2
//
// Made by  syp_s
// Login    <steven.syp@epitech.eu@epitech.eu>
//
// Started on  14/01/2017 Steven Syp
//

#ifndef TablePePeNoel_hh_
# define TablePePeNoel_hh_

# include <iostream>
# include <string>
# include "Object.hh"
# include "Teddy.hh"
# include "LittlePony.hh"
# include "Box.hh"
# include "GiftPaper.hh"

class ITable {
public:
  virtual ~ITable();
  virtual bool put(Object* obj) = 0;
  virtual Object* take(int pos) = 0;
  virtual std::string *look() = 0;
  virtual size_t getTableLength() = 0;
};

class TablePePeNoel : public ITable {
public:
  TablePePeNoel();
  ~TablePePeNoel();
  bool put(Object* obj);
  Object *take(int pos);
  std::string *look();
  size_t getTableLength();

protected:
  Object *_tableObjects[10];
};

ITable *createTable();

#endif /* TablePePeNoel_hpp */
