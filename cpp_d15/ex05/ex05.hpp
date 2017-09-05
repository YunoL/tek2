#ifndef EX05_HPP_
#define EX05_HPP_

#include <iostream>

template<typename X>
class array {
public:
  array() {
    _tab = NULL;
    _n = 0;
  }

  array(unsigned int n) {
    _n = n;
    _tab = new X[_n]();
  }

  array(const array<X>& copy) {
    _n = copy._n;
    _tab = NULL;
    _tab = new X[_n];
    for (unsigned int i = 0; i < _n; i++) {
      _tab[i] = copy._tab[i];
    }
  }

  virtual ~array() {
    if (_tab)
      delete[] _tab;
  }

  array<X>&  operator=(const array<X>& obj) {
    _n = obj._n;
    if (_tab)
      delete[] _tab;
    _tab = new X[_n];
    for (unsigned int i = 0; i < _n; i++) {
      _tab[i] = obj._tab[i];
    }
    return *this;
  }

  X& operator[](unsigned int index) {
    if (index >= _n)
    {
			X* copy = new X[index + 1]();
      for (unsigned int i = 0; i < _n; i++) {
        copy[i] = _tab[i];
      }
			delete[] _tab;
			_tab = copy;
			_n = index + 1;
		}
		return _tab[index];
  }

  X& operator[](unsigned int index) const {
		if (index >= _n) {
			throw std::exception();
		}
		return _tab[index];
	}

  unsigned int size() const
  {
    return _n;
  }

  void dump() const {
		std::cout << "[";
    for (unsigned int i = 0; i < _n; i++) {
      std::cout << _tab[i];
      if (i < _n - 1)
        std::cout << ", ";
    }
		std::cout << "]" << std::endl;
	}

  template<typename U>
  array<U>  convertTo(U(*convert)(const X&)) const
  {
    array<U> duplicate(_n);
    for (unsigned int i = 0; i < _n; i++) {
      duplicate[i] = (*convert)(_tab[i]);
    }
		return duplicate;
  }
protected:
  unsigned int _n;
  X* _tab;
};

template<>
void array<bool>::dump() const {
  std::cout << "[";
  for (unsigned int i = 0; i < _n; i++) {
    std::cout << (_tab[i] ? "true" : "false");
    if (i < _n - 1)
      std::cout << ", ";
    }
	std::cout << "]" << std::endl;
}

#endif
