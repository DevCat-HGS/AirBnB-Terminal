#ifndef MONITORSISTEMA_H
#define MONITORSISTEMA_H

#include <iostream>
#include <fstream>
using namespace std;
class MonitorSistema {
private:
    size_t memoriaTotal;
    int interaccionesTotales;
    
public:
    // Constructor
    MonitorSistema() : memoriaTotal(0), interaccionesTotales(0) {}
    
    // Métodos según el diagrama UML
    void sumarMemoria(size_t bytes) {
        memoriaTotal += bytes;
    }
    
    void registrarInteraccion() {
        interaccionesTotales++;
    }
    
    size_t obtenerMemoria() const {
        return memoriaTotal;
    }
    
    int obtenerInteracciones() const {
        return interaccionesTotales;
    }
    
    void reporte() {
        cout << "===== REPORTE DEL SISTEMA ====="  << endl;
        cout << "Memoria total utilizada: " << memoriaTotal << " bytes" << endl;
        cout << "Interacciones totales: " << interaccionesTotales << endl;
        cout << "===================================="  << endl;
        
        // Guardar reporte en archivo
        ofstream archivo("reporte_sistema.txt", ios::app);
        if (archivo.is_open()) {
            archivo << "===== REPORTE DEL SISTEMA ====="  << endl;
            archivo << "Memoria total utilizada: " << memoriaTotal << " bytes" << endl;
            archivo << "Interacciones totales: " << interaccionesTotales << endl;
            archivo << "====================================" << endl;
            archivo.close();
        }
    }
};

#endif // MONITORSISTEMA_H