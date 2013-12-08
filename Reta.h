/*
 * Reta.h
 *
 *  Created on: 08/12/2013
 *      Author: Eliton
 */

#ifndef RETA_H_
#define RETA_H_
#include <stdio.h>

class Ponto{
public:
	int x;
	int y;

	void print();
	bool operator < (const Ponto p1);

};

class Reta {
public:
	Ponto inicio;
	Ponto final;
	Reta();
	Reta(Ponto p1, Ponto p2);
	virtual ~Reta();
	void print();
};

#endif /* RETA_H_ */
