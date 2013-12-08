/*
 * Reta.cpp
 *
 *  Created on: 08/12/2013
 *      Author: Eliton
 */

#include "Reta.h"


/*
 * Funções da classe Reta
 */

Reta::Reta() {
	// TODO Auto-generated constructor stub

}

Reta::Reta(Ponto p1, Ponto p2){
	if(p1 < p2){
		this->inicio.x = p1.x;
		this->inicio.y = p1.y;
		this->final.x = p2.x;
		this->final.y = p2.y;
	}else{
		this->inicio.x = p2.x;
		this->inicio.y = p2.y;
		this->final.x = p1.x;
		this->final.y = p1.y;
	}
}

Reta::~Reta() {
	// TODO Auto-generated destructor stub
}

void Reta::print(){
	printf("Ponto inicial: ");
	inicio.print();
	printf("Ponto final: ");
	final.print();
	printf("\n");
}

/*
 * Funções da classe Ponto
 */

bool Ponto::operator< (const Ponto p1){
	if(this->x < p1.x){
		return true;
	}else{
		return false;
	}
}

void Ponto::print(){
	printf(" (%d,%d) ", this->x, this->y);
}
