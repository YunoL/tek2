#ifndef TOY_H_
#define TOY_H_

#include "Picture.h"
#include <iostream>

class Toy
{
public:
  enum ToyType {
    BASIC_TOY,
    ALIEN,
    BUZZ,
    WOODY
   };
  class Error {
  public:
      enum ErrorType
	{
	  UNKNOWN,
	  PICTURE,
	  SPEAK
	};
      Error();
      ErrorType type;
      std::string what() const;
      std::string where() const;
      void setType(ErrorType type);
  };
  Toy();
  Toy(ToyType type, std::string const &name, std::string const &picture);
  Toy(Toy const & copy);
  virtual ~Toy();
  int  getType() const;
  std::string const & getName() const;
  std::string const & getAscii() const;
  void setName(std::string const &name);
  bool setAscii(std::string const &picture);
  Toy& operator=(Toy const & toy);
  virtual bool speak(std::string const & message);
  virtual bool speak_es(std::string const & message);
  Toy::Error const & getLastError() const;
  Toy& operator<<(std::string const & message);
protected:
  ToyType _type;
  std::string _name;
  Picture _picture;
  Error error;
};

std::ostream & operator<<(std::ostream & os, Toy const & obj);

#endif
