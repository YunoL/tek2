//
// Object.hh for object in /home/guillaume2.roux/rendu/my_SantaClaus
//
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
//
// Started on  Sat Jan 14 09:03:58 2017 Guillaume Roux
// Last update Sun Jan 15 00:52:15 2017 Valentin Pichard
//

#ifndef OBJECT_HH_
# define OBJECT_HH_

# include <iostream>

class Object {
public:
  Object(std::string const & name, std::string const & type);
  virtual ~Object();

  // some getters
  std::string	const & getName() const;
  std::string   getType() const;

private:
  std::string	_name;
  std::string   _type;
 };

std::ostream & operator<<(std::ostream & os, Object const *obj);

#endif
