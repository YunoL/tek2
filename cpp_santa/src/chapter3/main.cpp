#include "Object.hh"
#include "LittlePony.hh"
#include "Teddy.hh"
#include "Toy.hh"
#include "Box.hh"
#include "GiftPaper.hh"

size_t tableLength(Object **obj) {
  size_t i;

  for (i = 0; obj[i] != NULL; i++);

  return i;
}

Object *MyUnitTests(Object **obj) {
  // Error handling
  if (!obj) {
    std::cerr << "Error: This array is empty !" << std::endl;
    return NULL;
    // Check table length
  } else if (tableLength(obj) != 3) {
    std::cerr << "Object array is not 3" << std::endl;
    return NULL;
    // Checking types
  } else if (!(obj[0]->getType() == "toy" && static_cast<Toy*>(obj[0])->getType() == "teddy") ||
	     !(obj[1]->getType() == "wrap" && static_cast<Wrap*>(obj[1])->getType() == "box") ||
	     !(obj[2]->getType() == "wrap" && static_cast<Wrap*>(obj[2])->getType() == "giftpaper")) {
    std::cerr << "Object doesn't meet required type" << std::endl;
    return NULL;
  }

  // cast objects to corresponding types
  Teddy* bear = static_cast<Teddy*>(obj[0]);
  Box* box = static_cast<Box*>(obj[1]);
  GiftPaper* gift = static_cast<GiftPaper*>(obj[2]);

  // open box
  box->openMe();

  // Wrap Teddy bear and close box
  box->wrapMeThat(bear);

  // wrap that box
  gift->wrapMeThat(box);
  return gift;
}

void unitTest() {
  Object *obj[6] = {
    new Teddy("motherFuckerTeddy"),
    new Box("paquet"),
    new GiftPaper("ruban"),
    new Box("random box"),
    new GiftPaper("test"),
    NULL
  };

  Object *giftObj = MyUnitTests(obj);

  if (!giftObj) {
    std::cerr << "Empty Gift" << std::endl;
    return;
  }

  std::cout << "OBJECT TYPE: " << giftObj->getType() << std::endl;

  if (static_cast<Wrap*>(giftObj)->getType() != "giftpaper") {
    std::cerr << "Gift is not a GiftPaper" << std::endl;
    return;
  }


  // unwrapping gift paper and box
  GiftPaper *gift = static_cast<GiftPaper*>(giftObj);
  std::cout << "gift : " << gift << std::endl;
  Box *box = static_cast<Box*>(gift->takeWrap());
  std::cout << "box : " << box << std::endl;
  std::cout << "Opening box..." << std::endl;
  box->openMe();
  std::cout << "gift object : " << box->takeWrap() << std::endl;
}

int main() {
  unitTest();
  return 0;
}
