#ifndef RATATOUILLE_H_
#define RATATOUILLE_H_

#include <iostream>
#include <sstream>

class Ratatouille {
public:
  Ratatouille();
  Ratatouille(Ratatouille const& copy);
  ~Ratatouille();
  Ratatouille& operator=(Ratatouille const& copy);
  Ratatouille& addVegetable(unsigned char c);
  Ratatouille& addCondiment(unsigned int i);
  Ratatouille& addSpice(double spice);
  Ratatouille& addSauce(const std::string &sauce);
  std::string kooc(void);
private:
  std::ostringstream os;
};

#endif
