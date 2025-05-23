#ifndef RESERVACION_H
#define RESERVACION_H

#include <string>
#include <iostream>
#include <cstring> // Añadido para strcpy

class Alojamiento; // Declaración adelantada
class Huesped; // Declaración adelantada

class Reservacion {
private:
    std::string codigo;
    std::string fechaInicio;
    int duracion;
    std::string docHuesped;
    std::string metodoPago;
    std::string fechaPago;
    float monto;
    char observaciones[1000];
    Alojamiento* alojamiento;
    Huesped* huesped;
    
public:
    // Constructor
    Reservacion(std::string codigo = "", std::string fechaInicio = "", int duracion = 0,
               std::string docHuesped = "", std::string metodoPago = "", std::string fechaPago = "",
               float monto = 0.0, Alojamiento* alojamiento = nullptr, Huesped* huesped = nullptr)
        : codigo(codigo), fechaInicio(fechaInicio), duracion(duracion), docHuesped(docHuesped),
          metodoPago(metodoPago), fechaPago(fechaPago), monto(monto), alojamiento(alojamiento),
          huesped(huesped) {
        strcpy(observaciones, "");
    }
    
    // Getters y setters
    std::string getCodigo() const { return codigo; }
    void setCodigo(std::string cod) { codigo = cod; }
    
    std::string getFechaInicio() const { return fechaInicio; }
    void setFechaInicio(std::string fecha) { fechaInicio = fecha; }
    
    int getDuracion() const { return duracion; }
    void setDuracion(int dur) { duracion = dur; }
    
    std::string getDocHuesped() const { return docHuesped; }
    void setDocHuesped(std::string doc) { docHuesped = doc; }
    
    std::string getMetodoPago() const { return metodoPago; }
    void setMetodoPago(std::string metodo) { metodoPago = metodo; }
    
    std::string getFechaPago() const { return fechaPago; }
    void setFechaPago(std::string fecha) { fechaPago = fecha; }
    
    float getMonto() const { return monto; }
    void setMonto(float m) { monto = m; }
    
    const char* getObservaciones() const { return observaciones; }
    void setObservaciones(const char* obs) { strcpy(observaciones, obs); }
    
    Alojamiento* getAlojamiento() const { return alojamiento; }
    void setAlojamiento(Alojamiento* aloj) { alojamiento = aloj; }
    
    Huesped* getHuesped() const { return huesped; }
    void setHuesped(Huesped* hues) { huesped = hues; }
    
    // Métodos según el diagrama UML
    bool validarTraslapes() {
        // Implementación básica: verificar si hay traslapes con otras reservaciones
        // Por simplicidad, asumimos que no hay traslapes
        return true;
    }
    
    std::string formatearFecha() {
        // Implementación básica: formatear la fecha para mostrarla
        return fechaInicio;
    }
    
    void imprimirComprobante() {
        std::cout << "===== COMPROBANTE DE RESERVACIÓN ====="  << std::endl;
        std::cout << "Código: " << codigo << std::endl;
        std::cout << "Fecha de inicio: " << fechaInicio << std::endl;
        std::cout << "Duración: " << duracion << " días" << std::endl;
        std::cout << "Huésped: " << docHuesped << std::endl;
        std::cout << "Método de pago: " << metodoPago << std::endl;
        std::cout << "Fecha de pago: " << fechaPago << std::endl;
        std::cout << "Monto: $" << monto << std::endl;
        std::cout << "Observaciones: " << observaciones << std::endl;
        if (alojamiento != nullptr) {
            std::cout << "Alojamiento: " << alojamiento->getNombre() << std::endl;
        }
        std::cout << "===================================="  << std::endl;
    }
    
    // Sobrecarga del operador de igualdad para comparar reservaciones
    bool operator==(const Reservacion& otra) const {
        return codigo == otra.codigo;
    }
    
    // Sobrecarga del operador de salida para mostrar información
    friend std::ostream& operator<<(std::ostream& os, const Reservacion& reservacion) {
        os << "Código: " << reservacion.codigo << "\n"
           << "Fecha de inicio: " << reservacion.fechaInicio << "\n"
           << "Duración: " << reservacion.duracion << " días\n"
           << "Monto: $" << reservacion.monto;
        return os;
    }
};

#endif // RESERVACION_H