#ifndef MONITORSISTEMA_H
#define MONITORSISTEMA_H

#include <iostream>
#include <fstream>

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
        std::cout << "===== REPORTE DEL SISTEMA ====="  << std::endl;
        std::cout << "Memoria total utilizada: " << memoriaTotal << " bytes" << std::endl;
        std::cout << "Interacciones totales: " << interaccionesTotales << std::endl;
        std::cout << "===================================="  << std::endl;
        
        // Guardar reporte en archivo
        std::ofstream archivo("reporte_sistema.txt", std::ios::app);
        if (archivo.is_open()) {
            archivo << "===== REPORTE DEL SISTEMA ====="  << std::endl;
            archivo << "Memoria total utilizada: " << memoriaTotal << " bytes" << std::endl;
            archivo << "Interacciones totales: " << interaccionesTotales << std::endl;
            archivo << "====================================" << std::endl;
            archivo.close();
        }
    }
};

#endif // MONITORSISTEMA_H