//
// main.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Fri Jan 18 16:13:55 2013 louis brunner
// Last update Sat Jan 19 01:39:07 2013 louis brunner
//

#include "Ice.hh"
#include "Cure.hh"
#include "Character.hh"
#include "MateriaSource.hh"

int main()
{
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* zaz = new Character("zaz");

  ICharacter* bob = new Character("bob");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  zaz->equip(tmp);
  std::cout << tmp->getXP() << std::endl;
  zaz->use(0, *bob);
  std::cout << tmp->getXP() << std::endl;
  tmp = src->createMateria("cure");
  zaz->equip(tmp);
  std::cout << tmp->getXP() << std::endl;
  zaz->use(1, *bob);
  zaz->use(1, *bob);
  std::cout << tmp->getXP() << std::endl;

  IMateriaSource* src2 = new MateriaSource();
  src2->learnMateria(tmp);
  tmp = src2->createMateria("ice");
  bob->equip(tmp);
  std::cout << tmp->getXP() << std::endl;
  bob->use(0, *bob);
  bob->use(1, *bob);
  std::cout << tmp->getXP() << std::endl;

  delete bob;
  delete zaz;
  delete src;
  delete src2;

  return 0;
}
