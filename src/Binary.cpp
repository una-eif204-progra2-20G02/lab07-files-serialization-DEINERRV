#include "Binary.h"
#include <fstream>
using namespace std;

void Binary::save(Persona * persona) {
    ofstream archivo;

    try { archivo.open("ArchivoBinario.dat", ios::out | ios::binary);  }

    catch (std::ifstream::failure a) {
        cout << "no se pudo abrir el archivo";
        exit(1);
    }

    archivo.write((char *) persona, sizeof(Persona));

    archivo.close();
}

void Binary::save(std::vector<Persona> personas) {
    ofstream archivo;

    try { archivo.open("ArchivoBinario.dat", ios::out | ios::binary);  }

    catch (std::ifstream::failure a) {
        cout << "no se pudo abrir el archivo";
        exit(1);
    }

    for(Persona persona : personas) {
        archivo.write((char *) &persona, sizeof(Persona));
    }

    archivo.close();
}

std::vector<Persona> Binary::read() {
    ifstream archivo;

    try { archivo.open("ArchivoBinario.dat", ios::in | ios::binary); }

    catch (std::ifstream::failure a) {
        cout << "no se pudo abrir el archivo";
        exit(1);
    }

    std::vector<Persona> personas;
    Persona persona;

    while(!archivo.eof()) {
        archivo.read((char *) &persona, sizeof(Persona));
        personas.push_back(persona);
    }

    archivo.close();

    personas.pop_back();
    return personas;
}

