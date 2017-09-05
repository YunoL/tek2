//
// Wrap.hh for wrap in /home/guillaume2.roux/rendu/my_SantaClaus
//
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
//
// Started on  Sat Jan 14 10:31:19 2017 Guillaume Roux
// Last update Sun Jan 15 00:55:06 2017 Valentin Pichard
//

#ifndef WRAP_HH_
#define WRAP_HH_

#include "Object.hh"

class Wrap : public Object {
public:
  const Object* get_Obj() const;
  Wrap(std::string const & name, std::string const & type);
  virtual ~Wrap();

  //getter
  bool	isEmpty() const;
  bool	isOpen() const;
  Object* takeWrap();
  std::string getType() const;

  //methods
  void	openMe();
  virtual void	wrapMeThat(Object *obj);

protected:
  Object* _obj;
  bool _isOpen;

private:
  std::string _type;
};

#endif
