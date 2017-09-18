//
// Created by ASUS on 9/18/2017.
//

#include "NodoBinario.h"

NodoBinario::NodoBinario(int valor)
{
    this->valor = valor;
    this->derecho = NULL;
    this->izquierdo = NULL;
}

NodoBinario::~NodoBinario()
{
    //dtor
}