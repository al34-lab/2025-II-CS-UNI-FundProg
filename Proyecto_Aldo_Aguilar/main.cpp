#include "buscador.h"

using namespace std;

int main() {
    cout << "=== PRUEBA DE MOTOR DE BUSQUEDA ===\n\n";

    // generando archivo de prueba
    cout << "[1] Creando archivo 'generado.txt' desde C++... ";
    ofstream archivoCodigo("generado.txt");
    archivoCodigo << "Hola CS UNI. Generando documento de prueba\n";
    archivoCodigo << "El codigo funciona perfectamente.";
    archivoCodigo.close();
    cout << "OK.\n";

    // iniciando motor
    Buscador miMotor;

    cout << "\n[2] Indexando archivos:\n";

    //indexar el archivo generado de prueba o cualquier archivo de texto que se tenga
    miMotor.indexarLibro("generado.txt");
    miMotor.indexarLibro("test.txt");
    //aviso de que archivo "otro.txt" no se encuentra
    miMotor.indexarLibro("otro.txt");

    ///busqueda
    cout << "\n[3] Realizando busquedas:\n";
    cout << "Ingrese la palabra a buscar\n";
    string palabra; 
    cin >> palabra;

    miMotor.buscar(palabra);

    cout << "\n=== PRUEBA FINALIZADA ===\n";
    return 0;
}