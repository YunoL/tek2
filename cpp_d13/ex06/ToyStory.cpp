#include "ToyStory.h"

void ToyStory::tellMeAStory(std::string const &filename,
                            Toy &toy1,
                            bool (Toy::*func1)(std::string const &message),
                            Toy &toy2,
                            bool (Toy::*func2)(std::string const &message))
{
  std::ifstream file;
  file.open(filename.c_str(), std::fstream::in);
  if (file.is_open())
  {
    std::string line;
    int count = 0;
    while (getline(file, line))
    {
      if (line.compare(0, 8,"picture:") == 0)
      {
        std::string picture = line.substr(8);
        if (count % 2)
        {
          if (toy1.setAscii(picture) == true)
					     std::cout << toy1.getAscii() << std::endl;
          else
            toy1.getLastError();
				}
        else
        {
          if (toy2.setAscii(picture) == true)
					     std::cout << toy2.getAscii() << std::endl;
          else
            toy2.getLastError();
				}
      }
      else
      {
        if (count % 2)
        {
          std::cout << toy1;
					(toy1.*func1)(line);
        }
        else
        {
          std::cout << toy2;
          (toy2.*func2)(line);
        }
      }
      count++;
    }
  }
  else
  {
    std::cout << "Bad Story" << '\n';
    return;
  }
  file.close();
}
