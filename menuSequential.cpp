#ifndef MENUSEQUENTIAL_CPP
#define MENUSEQUENTIAL_CPP

#include "Sequential/SequentialFile.h"

// nombre_csv_sin_ext : Por ejemplo, si el CSV se llama: alfredo.csv, ingresar solo alfredo
// Nombres de los archivos: 
//      cereal.csv -> cereal
//      FIFA22_PlayerCards_Format.csv -> FIFA22_PlayerCards_Format

// insert: (line) Introducir los parametros del registro en una linea csv
    // Se es exitoso, se retorna un 1, de lo contrario un 0
// search:  (key) una cadena de la llave de un regsitro a hallar
    // Se retorna una cadena en formato csv
// remove: ('') ''
    // Se es exitoso, se retorna un 1, de lo contrario un 0
// rangeSearch (inicio) llave con la que se comienza la busqueda, (fin) llave con la que termina la busqueda
    // Se retorna una cadena con los registros en formato csv, de tal manera que entre cada registro hay un \n

const std::string cereal = "cereal";
const std::string fifa = "FIFA22_PlayerCards_Format";




extern "C"
bool insert_S_Fifa(char* line){
    std::string str(line);
    Registros::CartaFifa traduccion;
    traduccion.readCSVLine(str);
    SequentialFile<Registros::CartaFifa> sf(fifa);
    try{
        sf.add(traduccion);
    }
    catch(...){
        return false;
    }
    return true;
}
extern "C"
void search_S_Fifa(char* key,char* result){
    SequentialFile<Registros::CartaFifa> sf(fifa);
    try{
        std::string str(key);
        Registros::CartaFifa objetivo = sf.search(key);
        std::string retorno = objetivo.writeCSVLine();
        result = &retorno[0];
        
    }
    catch(...){
        throw "error";
    }
}
extern "C"
bool remove_S_Fifa(char* key){
    std::string str(key);
    SequentialFile<Registros::CartaFifa> sf(fifa);
    try
    {
        sf.remove(str);
    }
    catch(...)
    {
        return false;
    }
    return true;
}
extern "C"
void rangeSearch_S_Fifa(char* inicio, char* fin,char* result){
    SequentialFile<Registros::CartaFifa> sf(fifa);
    try
    {
        std::string start(inicio);
        std::string end(fin);
        std::vector<Registros::CartaFifa> listaRegistros = sf.rangeSearch(start, end);
        std::string aux = "";
        for(Registros::CartaFifa i: listaRegistros){
            aux.append(i.writeCSVLine());
            aux.append("\n");
        }
        
        
        result = &aux[0];
        
    }
    catch(...)
    {
        throw "error";
    }
}

extern "C"
bool insert_S_Cereal(char* line){
    std::string str(line);
    Registros::Cereal traduccion;
    traduccion.readCSVLine(str);
    SequentialFile<Registros::Cereal> sf(cereal);
    try{
        sf.add(traduccion);
    }
    catch(...){
        return false;
    }
    return true;
}
extern "C"
void search_S_Cereal(char* key, char* result){
    SequentialFile<Registros::Cereal> sf(cereal);
    try{
        std::string str(key);
        Registros::Cereal objetivo = sf.search(str);
        std::string retorno = objetivo.writeCSVLine();
        std::cout<<retorno;
        
        result = &retorno[0];
        
    }
    catch(...){
        throw "error";
    }
}
extern "C"
bool remove_S_Cereal(std::string key){
    std::string str(key);
    SequentialFile<Registros::Cereal> sf(cereal);
    try
    {
        sf.remove(str);
    }
    catch(...)
    {
        return false;
    }
    return true;
}
extern "C"
void rangeSearch_S_Cereal(char* inicio, char* fin, char* result){
    SequentialFile<Registros::Cereal> sf(cereal);
    try
    {
        std::string start(inicio);
        std::string end(fin);
        std::vector<Registros::Cereal> listaRegistros = sf.rangeSearch(start, end);
        std::string aux = "";
        for(Registros::Cereal i: listaRegistros){
            aux += i.writeCSVLine();
            aux += "\n";
        }
        result = &aux[0];
    }
    catch(...)
    {
        throw "error";
    }
}

#endif