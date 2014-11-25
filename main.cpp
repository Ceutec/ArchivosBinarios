#include <iostream>
#include <fstream>

using namespace std;

void escribirNumeros(string nombre_archivo, int cant)
{
    ofstream out(nombre_archivo.c_str());
    for(int i=0; i < cant; i++)
    {
        int num;
        cout<<"Ingrese un numero: ";
        cin>>num;
        out.write((char*)&num,4);
    }
}

int getMayor(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(0,ios::end);
    int tamano = in.tellg();
    in.seekg(0,ios::beg);

    int mayor = -999;
    while(in.tellg()<tamano)
    {
        int num;
        in.read((char*)&num,4);
        if(mayor<num)
            mayor = num;
    }
    return mayor;
}

void imprimir(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    in.seekg(0,ios::end);
    int cant = in.tellg()/4;
    in.seekg(0);
    for(int i=0;i<cant;i++)
    {
        int num;
        in.read((char*)&num,4);
        cout<<num<<endl;
    }
    in.close();
}


void escribirNumero(string nombre_archivo, int num, int pos)
{
    ofstream out(nombre_archivo.c_str(),ios::in);
    out.seekp(pos*4);
    out.write((char*)&num,4);
    out.close();
}

int main()
{
    escribirNumeros("archivo",4);
    escribirNumero("archivo",10,2);
    imprimir("archivo");
    cout<<"El mayor es: "<<getMayor("archivo");

    return 0;
}
