//
// Created by ASUS on 9/18/2017.
//

#include "Libro.h"

Libro::Libro(string nombre, string autor, int existencias)
{
    this->nombre = nombre;
    this->autor = autor;
    this->existencias = existencias;
}

Libro::~Libro()
{
    //dtor
}