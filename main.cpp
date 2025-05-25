#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "SistemaUdeAStay.h"

using namespace std;


void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    }    

int main() {
    SistemaUdeAStay sistema;
    int opcion = 0;
    bool loggedIn = false;
    
  //  limpiarPantalla();
    cout << "===== Bienvenido al Sistema UdeAStay ====="  << endl;
    
    while (true) {
        if (!loggedIn) {
            cout << "\n1. Iniciar sesion\n2. Salir\nSeleccione una opcion: ";
            cin >> opcion;
            
            switch (opcion) {
                case 1:
                    loggedIn = sistema.login();
                    if (loggedIn) {
                        sistema.cargarDatos();
                    }
                    break;
                case 2:
                    cout << "Gracias por usar el Sistema UdeAStay. ¡Hasta pronto!" << endl;
                    return 0;
                default:
                    cout << "Opcion inválida. Intente nuevamente." << endl;
            }
        } else {
            // El menú se maneja dentro del método login() para cada tipo de usuario
            loggedIn = false;
            sistema.guardarDatos();
            cout << "Sesión finalizada." << endl;
        }
    }
    
    return 0;
}
