/*
 * main.cpp
 *
 *  Created on: 07/12/2013
 *      Author: Eliton
 */

#include<stdio.h>
#include "Reta.h"

int main(){
	int n;



	scanf("%d", &n);

	while(n > 0){
		int qtdRetas;
		scanf("%d", &qtdRetas);

		Reta retas[qtdRetas];

		for(int i = 0; i < qtdRetas; i++){
			scanf("%d %d %d %d", &retas[i].inicio.x,
				&retas[i].inicio.y, &retas[i].final.x, &retas[i].final.y );
		}
		for(int i = 0; i < qtdRetas; i++){
			retas[i].print();
		}

		n--;
	}



	return 0;
}



