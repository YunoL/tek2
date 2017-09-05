//
// GiftPaper.hh for giftpaper in /home/guillaume2.roux/rendu/my_SantaClaus
//
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
//
// Started on  Sat Jan 14 11:34:21 2017 Guillaume Roux
// Last update Sat Jan 14 13:39:15 2017 Valentin Pichard
//

#ifndef GIFTPAPER_HH_
#define GIFTPAPER_HH_

#include "Wrap.hh"

class GiftPaper : public Wrap {
public:
  GiftPaper(std::string const & name);
  ~GiftPaper();
};

#endif
