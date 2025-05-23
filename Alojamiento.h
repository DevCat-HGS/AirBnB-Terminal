#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include <string>
#include <iostream>
#include "Lista.h"

class Reservacion; // Declaración adelantada
class Anfitrion; // Declaración adelantada

class Alojamiento {
private:
    std::string codigo;
    std::string nombre;
    std::string tipo;
    std::string departamento;
    std::string municipio;
    std::string direccion;
    float precioNoche;
    Lista<std::string> amenidades;
    Anfitrion* anfitrion;
    Lista<Reservacion*> fechasReservadas;
    
public:
    // Constructor
    Alojamiento(std::string codigo = "", std::string nombre = "", std::string tipo = "", 
               std::string departamento = "", std::string municipio = "", std::string direccion = "", 
               float precioNoche = 0.0, Anfitrion* anfitrion = nullptr)
        : codigo(codigo), nombre(nombre), tipo(tipo), departamento(departamento),
          municipio(municipio), direccion(direccion), precioNoche(precioNoche), anfitrion(anfitrion) {}
    
    // Getters y setters
    std::string getCodigo() const { return codigo; }
    void setCodigo(std::string cod) { codigo = cod; }
    
    std::string getNombre() const { return nombre; }
    void setNombre(std::string nom) { nombre = nom; }
    
    std::string getTipo() const { return tipo; }
    void setTipo(std::string t) { tipo = t; }
    
    std::string getDepartamento() const { return departamento; }
    void setDepartamento(std::string dep) { departamento = dep; }
    
    std::string getMunicipio() const { return municipio; }
    void setMunicipio(std::string mun) { municipio = mun; }
    
    std::string getDireccion() const { return direccion; }
    void setDireccion(std::string dir) { direccion = dir; }
    
    float getPrecioNoche() const { return precioNoche; }
    void setPrecioNoche(float precio) { precioNoche = precio; }
    
    Lista<std::string>& getAmenidades() { return amenidades; }
    
    Anfitrion* getAnfitrion() const { return anfitrion; }
    void setAnfitrion(Anfitrion* anf) { anfitrion = anf; }
    
    Lista<Reservacion*>& getFechasReservadas() { return fechasReservadas; }
    
    // Métodos según el diagrama UML
    void mostrarInfo() {
        std::cout << "Código: " << codigo << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Tipo: " << tipo << std::endl;
        std::cout << "Ubicación: " << municipio << ", " << departamento << std::endl;
        std::cout << "Dirección: " << direccion << std::endl;
        std::cout << "Precio por noche: $" << precioNoche << std::endl;
        
        std::cout << "Amenidades: ";
        Nodo<std::string>* actual = amenidades.getCabeza();
        while (actual != nullptr) {
            std::cout << actual->getDato() << ", ";
            actual = actual->getSiguiente();
        }
        std::cout << std::endl;
    }
    
    bool verificarDisponibilidad(std::string inicio, std::string fin) {
        // Implementación básica: verificar si hay alguna reserva que se solape
        Nodo<Reservacion*>* actual = fechasReservadas.getCabeza();
        while (actual != nullptr) {
            Reservacion* reserva = actual->getDato();
            // Aquí se debería implementar la lógica para verificar si las fechas se solapan
            // Por simplicidad, asumimos que no hay solapamiento
            actual = actual->getSiguiente();
        }
        return true; // Por defecto, asumimos disponibilidad
    }
    
    void agregarReservacion(Reservacion* reservacion) {
        fechasReservadas.agregar(reservacion);
    }
    
    void quitarReservacion(Reservacion* reservacion) {
        fechasReservadas.eliminar(reservacion);
    }
    
    // Sobrecarga del operador de igualdad para comparar alojamientos
    bool operator==(const Alojamiento& otro) const {
        return codigo == otro.codigo;
    }
    
    // Sobrecarga del operador de salida para mostrar información
    friend std::ostream& operator<<(std::ostream& os, const Alojamiento& alojamiento) {
        os << "Código: " << alojamiento.codigo << "\n"
           << "Nombre: " << alojamiento.nombre << "\n"
           << "Tipo: " << alojamiento.tipo << "\n"
           << "Ubicación: " << alojamiento.municipio << ", " << alojamiento.departamento << "\n"
           << "Precio por noche: $" << alojamiento.precioNoche;
        return os;
    }
};

#endif // ALOJAMIENTO_H