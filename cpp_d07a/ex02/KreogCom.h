/*
** KreogCom.h for kreogcom in /home/guillaume2.roux/rendu/cpp_d07a/ex02
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Tue Jan 10 18:41:55 2017 Guillaume Roux
** Last update Tue Jan 10 18:41:57 2017 Guillaume Roux
*/

#ifndef KREOGCOM_H_
#define KREOGCOM_H_

class KreogCom
{
public:
	KreogCom(int x, int y, int serial);
	~KreogCom();
	void	addCom(int x, int y, int serial);
	KreogCom 	*getCom();
	void	removeCom();
	void	ping() const;
	void	locateSquad() const;
private:
	int	_x;
	int	_y;
	const int	m_serial;
	KreogCom*	next;
};

#endif