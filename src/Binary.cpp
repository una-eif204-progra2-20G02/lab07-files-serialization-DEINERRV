#include "Binary.h"
#include <fstream>
using namespace std;

void Binary::save(Persona * persona) {
    ofstream archivo;

    try { archivo.open("ArchivoBinario.dat", ios::app | ios::binary);  }

    catch (std::ifstream::failure a) {
        cout << "no se pudo abrir el archivo";
        exit(1);
    }

    archivo.write((char *) &persona, sizeof(Persona));

    archivo.close();
}

void Binary::save(std::vector<Persona> personas) {
    ofstream archivo;

    try { archivo.open("ArchivoBinario.dat", ios::app | ios::binary);  }

    catch (std::ifstream::failure a) {
        cout << "no se pudo abrir el archivo";
        exit(1);
    }

    for(Persona persona : personas) {
        archivo.write((char *) &personas, sizeof(Persona));
    }

    archivo.close();
}