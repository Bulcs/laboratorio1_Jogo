#include <iostream>
#include "jogadores.h"

using namespace std;

int jogadores::getjogadores(){
	return jogadores;
}

void jogadores::setjogadores(int players){
	jogadores = players;
}

int jogadores::getn(){
	return n;
}

void jogadores::setn(int numero){
	n = numero;
}