#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char** argv){
 std::ifstream archivoEntrada("puntajes.csv");
 std::ofstream archivoSalida("promedios.csv");
 std::string linea;
 int suma = 0;
 for(unsigned long rut = 14916641; rut<=19932391; rut++){
  std::getline(archivoEntrada, linea);
  std::istringstream datos(linea);
  std::string dato;
  for(int contador=0; contador<7; contador++){
   std::getline(datos, dato, ';');
   int valor = (std::stoi(dato));
   if(valor<900){
    suma+=valor;
   } 
   if(contador==6){
    float promedio = ((float(suma))/6.0);
    archivoSalida << std::to_string(rut) << ";" << std::to_string(promedio) << ";" << std::endl;
    suma=0;
   }
  }
 }
 archivoEntrada.close();
 archivoSalida.close();
 
 return EXIT_SUCCESS;
}
