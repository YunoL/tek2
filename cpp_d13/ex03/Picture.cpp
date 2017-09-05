#include "Picture.h"

Picture::Picture()
{
  this->data = "";
}

Picture::Picture (const std::string& file)
{
  this->getPictureFromFile(file);
}

Picture::~Picture ()
{

}

bool  Picture::getPictureFromFile(const std::string& file)
{
  std::ifstream myFile;
  char  buffer;
  std::string content;

  myFile.open(file.c_str(), std::fstream::in);
  if (myFile)
  {
  	while (!myFile.eof())
  	{
  		buffer = (char) myFile.get();
  		if (buffer != -1)
  			content += buffer;
  	}
  }
  else
  {
    this->data = "ERROR";
    return false;
  }
  this->data = content;
  myFile.close();
  return true;
}

Picture& Picture::operator=(Picture const & pic)
{
  this->data = pic.data;
  return *this;
}
