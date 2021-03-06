#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Libro.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;
int pos= 104;
//Escribe todos los datos del libro en un archivo con nombre nombre_archivo en la posicion dada
void escribir(string nombre_archivo, Libro*libro, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in);
    if(!out.is_open())
    {
        out.open(nombre_archivo.c_str());
    }
    out.seekp(posicion*pos);
    out.write((char*)libro->nombre.c_str(),50);
    out.write((char*)libro->autor.c_str(),50);
    out.write((char*)&libro->existencias,4);
    out.close();
}

//Devuelve el libro guardado en el archivo en la posicion dada
Libro* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*pos);
    int existencias;
    char nombre[50];
    char autor[50];
    in.read(nombre,50);
    in.read(autor,50);
    in.read((char*)&existencias,4);
    Libro *libro = new Libro(nombre, autor, existencias);
    return libro;
}

//Crea un mapa en base a las llaves y valores dados, asocia cada llave con los valores en la misma posicion
map<string, int> convertirEnMapa(set<string> llaves, set<int> valores)
{
    map<string, int> respuesta;
    set<string>::iterator x = llaves.begin();
    set<int>::iterator y =  valores.begin();

    while(x!=llaves.end()){
        respuesta[*x] = *y;
        y++;
        x++;
    }
    return respuesta;
}

//Devuelve una cola con los mismos valores que el parametro exepto que no tiene el ultimo valor
queue<int> popBack(queue<int> cola)
{
    queue<int> respuesta;
    stack<int> respuestaF;
    stack<int> temporal;
    int agregar,contador;
    while(!cola.empty())
    {
        agregar = cola.front();
        temporal.push(agregar);
        cola.pop();
    }
    temporal.pop();
    while(!temporal.empty())
    {
        agregar = temporal.top();
        respuestaF.push(agregar);
        temporal.pop();
    }
    while(!respuestaF.empty())
    {
        agregar = respuestaF.top();
        respuesta.push(agregar);
        respuestaF.pop();
    }
    return respuesta;
}

//Reemplaza todos los valores del arbol
void reemplazarValores(NodoBinario* raiz, int valor)
{
    if (raiz==NULL){
        return;
    }
    if(raiz->valor = valor){
    }
    reemplazarValores(raiz->derecho,valor);
    reemplazarValores(raiz->izquierdo,valor);
}

//Devuelve la cantidad de bits "encendidos" o con el valores de 1
bool Bit(char valor, int pos)
{
int mascara = 1;
mascara = mascara<<pos;
return valor & mascara;
}
int contarBits(char byte)
{
  int contara=0;
  for(int n=0;n<8;n++)
  {
      if(Bit(byte,n)){
          contara++;
      }
  }
  return contara;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
