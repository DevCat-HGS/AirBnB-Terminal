#ifndef SISTEMAUDEASAY_H
#define SISTEMAUDEASAY_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>
#include "Lista.h"
#include "Alojamiento.h"
#include "Huesped.h"
#include "Reservacion.h"
#include "Anfitrion.h"
#include "MonitorSistema.h"

class SistemaUdeASay {
private:
    Lista<Alojamiento*> alojamientos;
    Lista<Anfitrion*> anfitriones;
    Lista<Huesped*> huespedes;
    Lista<Reservacion*> reservaciones;
    MonitorSistema monitor;
    
    // Métodos privados para manejo de archivos
    void guardarAlojamientos() {
        std::ofstream archivo("alojamientos.txt");
        if (!archivo.is_open()) {
            std::cout << "Error al abrir el archivo de alojamientos." << std::endl;
            return;
        }
        
        Nodo<Alojamiento*>* actual = alojamientos.getCabeza();
        while (actual != nullptr) {
            Alojamiento* alojamiento = actual->getDato();
            archivo << alojamiento->getCodigo() << "|"
                    << alojamiento->getNombre() << "|"
                    << alojamiento->getTipo() << "|"
                    << alojamiento->getDepartamento() << "|"
                    << alojamiento->getMunicipio() << "|"
                    << alojamiento->getDireccion() << "|"
                    << alojamiento->getPrecioNoche() << "|"
                    << (alojamiento->getAnfitrion() ? alojamiento->getAnfitrion()->getDocumento() : "") << std::endl;
            
            // Guardar amenidades
            Nodo<std::string>* amenidad = alojamiento->getAmenidades().getCabeza();
            if (amenidad != nullptr) {
                archivo << "AMENIDADES:";
                while (amenidad != nullptr) {
                    archivo << amenidad->getDato() << ",";
                    amenidad = amenidad->getSiguiente();
                }
                archivo << std::endl;
            }
            
            actual = actual->getSiguiente();
        }
        
        archivo.close();
    }
    
    void guardarAnfitriones() {
        std::ofstream archivo("anfitriones.txt");
        if (!archivo.is_open()) {
            std::cout << "Error al abrir el archivo de anfitriones." << std::endl;
            return;
        }
        
        Nodo<Anfitrion*>* actual = anfitriones.getCabeza();
        while (actual != nullptr) {
            Anfitrion* anfitrion = actual->getDato();
            archivo << anfitrion->getDocumento() << "|"
                    << anfitrion->getAntiguedad() << "|"
                    << anfitrion->getPuntuacion() << std::endl;
            
            actual = actual->getSiguiente();
        }
        
        archivo.close();
    }
    
    void guardarHuespedes() {
        std::ofstream archivo("huespedes.txt");
        if (!archivo.is_open()) {
            std::cout << "Error al abrir el archivo de huéspedes." << std::endl;
            return;
        }
        
        Nodo<Huesped*>* actual = huespedes.getCabeza();
        while (actual != nullptr) {
            Huesped* huesped = actual->getDato();
            archivo << huesped->getDocumento() << "|"
                    << huesped->getNombre() << "|"
                    << huesped->getAntiguedadMeses() << "|"
                    << huesped->getPuntuacion() << std::endl;
            
            actual = actual->getSiguiente();
        }
        
        archivo.close();
    }
    
    void guardarReservaciones() {
        std::ofstream archivo("reservaciones.txt");
        if (!archivo.is_open()) {
            std::cout << "Error al abrir el archivo de reservaciones." << std::endl;
            return;
        }
        
        Nodo<Reservacion*>* actual = reservaciones.getCabeza();
        while (actual != nullptr) {
            Reservacion* reservacion = actual->getDato();
            archivo << reservacion->getCodigo() << "|"
                    << reservacion->getFechaInicio() << "|"
                    << reservacion->getDuracion() << "|"
                    << reservacion->getDocHuesped() << "|"
                    << reservacion->getMetodoPago() << "|"
                    << reservacion->getFechaPago() << "|"
                    << reservacion->getMonto() << "|"
                    << reservacion->getObservaciones() << "|"
                    << (reservacion->getAlojamiento() ? reservacion->getAlojamiento()->getCodigo() : "") << "|"
                    << (reservacion->getHuesped() ? reservacion->getHuesped()->getDocumento() : "") << std::endl;
            
            actual = actual->getSiguiente();
        }
        
        archivo.close();
    }
    
    void cargarAlojamientos() {
        std::ifstream archivo("alojamientos.txt");
        if (!archivo.is_open()) {
            std::cout << "No se encontró el archivo de alojamientos. Se creará uno nuevo." << std::endl;
            return;
        }
        
        std::string linea;
        while (std::getline(archivo, linea)) {
            if (linea.empty()) continue;
            
            if (linea.substr(0, 11) == "AMENIDADES:") {
                // Procesar amenidades para el último alojamiento agregado
                if (alojamientos.getCabeza() != nullptr) {
                    Alojamiento* ultimoAlojamiento = alojamientos.getCabeza()->getDato();
                    std::string amenidadesStr = linea.substr(11);
                    size_t pos = 0;
                    std::string token;
                    while ((pos = amenidadesStr.find(',')) != std::string::npos) {
                        token = amenidadesStr.substr(0, pos);
                        if (!token.empty()) {
                            ultimoAlojamiento->getAmenidades().agregar(token);
                        }
                        amenidadesStr.erase(0, pos + 1);
                    }
                }
                continue;
            }
            
            // Procesar datos del alojamiento
            size_t pos = 0;
            std::string token;
            std::string datos[8];
            int i = 0;
            
            while ((pos = linea.find('|')) != std::string::npos && i < 8) {
                token = linea.substr(0, pos);
                datos[i++] = token;
                linea.erase(0, pos + 1);
            }
            if (!linea.empty() && i < 8) {
                datos[i] = linea;
            }
            
            // Crear alojamiento
            Alojamiento* alojamiento = new Alojamiento(
                datos[0], // codigo
                datos[1], // nombre
                datos[2], // tipo
                datos[3], // departamento
                datos[4], // municipio
                datos[5], // direccion
                std::stof(datos[6]) // precioNoche
            );
            
            // Asignar anfitrión si existe
            if (!datos[7].empty()) {
                Anfitrion anfitrionBusqueda;
                anfitrionBusqueda.setDocumento(datos[7]);
                Anfitrion* anfitrion = anfitriones.buscar(&anfitrionBusqueda);
                if (anfitrion != nullptr) {
                    alojamiento->setAnfitrion(anfitrion);
                    anfitrion->getAlojamientos().agregar(alojamiento);
                }
            }
            
            alojamientos.agregar(alojamiento);
        }
        
        archivo.close();
    }
    
    void cargarAnfitriones() {
        std::ifstream archivo("anfitriones.txt");
        if (!archivo.is_open()) {
            std::cout << "No se encontró el archivo de anfitriones. Se creará uno nuevo." << std::endl;
            return;
        }
        
        std::string linea;
        while (std::getline(archivo, linea)) {
            if (linea.empty()) continue;
            
            size_t pos = 0;
            std::string token;
            std::string datos[3];
            int i = 0;
            
            while ((pos = linea.find('|')) != std::string::npos && i < 3) {
                token = linea.substr(0, pos);
                datos[i++] = token;
                linea.erase(0, pos + 1);
            }
            if (!linea.empty() && i < 3) {
                datos[i] = linea;
            }
            
            // Crear anfitrión
            Anfitrion* anfitrion = new Anfitrion(
                datos[0], // documento
                std::stoi(datos[1]), // antiguedad
                std::stof(datos[2]) // puntuacion
            );
            
            anfitriones.agregar(anfitrion);
        }
        
        archivo.close();
    }
    
    void cargarHuespedes() {
        std::ifstream archivo("huespedes.txt");
        if (!archivo.is_open()) {
            std::cout << "No se encontró el archivo de huéspedes. Se creará uno nuevo." << std::endl;
            return;
        }
        
        std::string linea;
        while (std::getline(archivo, linea)) {
            if (linea.empty()) continue;
            
            size_t pos = 0;
            std::string token;
            std::string datos[4];
            int i = 0;
            
            while ((pos = linea.find('|')) != std::string::npos && i < 4) {
                token = linea.substr(0, pos);
                datos[i++] = token;
                linea.erase(0, pos + 1);
            }
            if (!linea.empty() && i < 4) {
                datos[i] = linea;
            }
            
            // Crear huésped
            Huesped* huesped = new Huesped(
                datos[0], // documento
                datos[1], // nombre
                std::stoi(datos[2]), // antiguedadMeses
                std::stof(datos[3]) // puntuacion
            );
            
            huespedes.agregar(huesped);
        }
        
        archivo.close();
    }
    
    void cargarReservaciones() {
        std::ifstream archivo("reservaciones.txt");
        if (!archivo.is_open()) {
            std::cout << "No se encontró el archivo de reservaciones. Se creará uno nuevo." << std::endl;
            return;
        }
        
        std::string linea;
        while (std::getline(archivo, linea)) {
            if (linea.empty()) continue;
            
            size_t pos = 0;
            std::string token;
            std::string datos[10];
            int i = 0;
            
            while ((pos = linea.find('|')) != std::string::npos && i < 10) {
                token = linea.substr(0, pos);
                datos[i++] = token;
                linea.erase(0, pos + 1);
            }
            if (!linea.empty() && i < 10) {
                datos[i] = linea;
            }
            
            // Crear reservación
            Reservacion* reservacion = new Reservacion(
                datos[0], // codigo
                datos[1], // fechaInicio
                std::stoi(datos[2]), // duracion
                datos[3], // docHuesped
                datos[4], // metodoPago
                datos[5], // fechaPago
                std::stof(datos[6]) // monto
            );
            
            // Asignar observaciones
            reservacion->setObservaciones(datos[7].c_str());
            
            // Asignar alojamiento si existe
            if (!datos[8].empty()) {
                Alojamiento alojamientoBusqueda;
                alojamientoBusqueda.setCodigo(datos[8]);
                Alojamiento* alojamiento = alojamientos.buscar(&alojamientoBusqueda);
                if (alojamiento != nullptr) {
                    reservacion->setAlojamiento(alojamiento);
                    alojamiento->getFechasReservadas().agregar(reservacion);
                }
            }
            
            // Asignar huésped si existe
            if (!datos[9].empty()) {
                Huesped huespedBusqueda;
                huespedBusqueda.setDocumento(datos[9]);
                Huesped* huesped = huespedes.buscar(&huespedBusqueda);
                if (huesped != nullptr) {
                    reservacion->setHuesped(huesped);
                    huesped->getReservacionesActivas().agregar(reservacion);
                }
            }
            
            reservaciones.agregar(reservacion);
        }
        
        archivo.close();
    }
    
public:
    // Constructor
    SistemaUdeASay() {}
    
    // Métodos según el diagrama UML
    bool login() {
        std::string usuario, password;
        std::cout << "Usuario: ";
        std::cin >> usuario;
        std::cout << "Contraseña: ";
        std::cin >> password;
        
        // Verificar credenciales (simplificado para el ejemplo)
        if (usuario == "admin" && password == "admin123") {
            std::cout << "Inicio de sesión exitoso." << std::endl;
            return true;
        } else {
            std::cout << "Credenciales incorrectas." << std::endl;
            return false;
        }
    }
    
    void registrarAlojamiento() {
        std::string codigo, nombre, tipo, departamento, municipio, direccion;
        float precioNoche;
        std::string docAnfitrion;
        
        std::cout << "===== REGISTRO DE ALOJAMIENTO ====="  << std::endl;
        std::cout << "Código: ";
        std::cin >> codigo;
        
        // Verificar si ya existe un alojamiento con ese código
        Alojamiento alojamientoBusqueda;
        alojamientoBusqueda.setCodigo(codigo);
        if (alojamientos.buscar(&alojamientoBusqueda) != nullptr) {
            std::cout << "Ya existe un alojamiento con ese código." << std::endl;
            return;
        }
        
        std::cin.ignore();
        std::cout << "Nombre: ";
        std::getline(std::cin, nombre);
        
        std::cout << "Tipo (casa, apartamento, habitación): ";
        std::getline(std::cin, tipo);
        
        std::cout << "Departamento: ";
        std::getline(std::cin, departamento);
        
        std::cout << "Municipio: ";
        std::getline(std::cin, municipio);
        
        std::cout << "Dirección: ";
        std::getline(std::cin, direccion);
        
        std::cout << "Precio por noche: ";
        std::cin >> precioNoche;
        
        std::cout << "Documento del anfitrión: ";
        std::cin >> docAnfitrion;
        
        // Buscar anfitrión
        Anfitrion anfitrionBusqueda;
        anfitrionBusqueda.setDocumento(docAnfitrion);
        Anfitrion* anfitrion = anfitriones.buscar(&anfitrionBusqueda);
        
        if (anfitrion == nullptr) {
            std::cout << "No se encontró un anfitrión con ese documento. ¿Desea registrarlo? (s/n): ";
            char respuesta;
            std::cin >> respuesta;
            
            if (respuesta == 's' || respuesta == 'S') {
                int antiguedad;
                float puntuacion;
                
                std::cout << "Antigüedad (años): ";
                std::cin >> antiguedad;
                
                std::cout << "Puntuación inicial: ";
                std::cin >> puntuacion;
                
                anfitrion = new Anfitrion(docAnfitrion, antiguedad, puntuacion);
                anfitriones.agregar(anfitrion);
                std::cout << "Anfitrión registrado correctamente." << std::endl;
            } else {
                std::cout << "Registro de alojamiento cancelado." << std::endl;
                return;
            }
        }
        
        // Crear alojamiento
        Alojamiento* alojamiento = new Alojamiento(codigo, nombre, tipo, departamento, municipio, direccion, precioNoche, anfitrion);
        
        // Agregar amenidades
        std::cout << "¿Cuántas amenidades desea agregar?: ";
        int numAmenidades;
        std::cin >> numAmenidades;
        std::cin.ignore();
        
        for (int i = 0; i < numAmenidades; i++) {
            std::string amenidad;
            std::cout << "Amenidad " << (i + 1) << ": ";
            std::getline(std::cin, amenidad);
            alojamiento->getAmenidades().agregar(amenidad);
        }
        
        // Agregar alojamiento al sistema y al anfitrión
        alojamientos.agregar(alojamiento);
        anfitrion->getAlojamientos().agregar(alojamiento);
        
        std::cout << "Alojamiento registrado correctamente." << std::endl;
        monitor.registrarInteraccion();
    }
    
    void registrarHuesped() {
        std::string documento, nombre;
        int antiguedadMeses;
        float puntuacion;
        
        std::cout << "===== REGISTRO DE HUÉSPED ====="  << std::endl;
        std::cout << "Documento: ";
        std::cin >> documento;
        
        // Verificar si ya existe un huésped con ese documento
        Huesped huespedBusqueda;
        huespedBusqueda.setDocumento(documento);
        if (huespedes.buscar(huespedBusqueda) != nullptr) {
            std::cout << "Ya existe un huésped con ese documento." << std::endl;
            return;
        }
        
        std::cin.ignore();
        std::cout << "Nombre: ";
        std::getline(std::cin, nombre);
        
        std::cout << "Antigüedad (meses): ";
        std::cin >> antiguedadMeses;
        
        std::cout << "Puntuación inicial: ";
        std::cin >> puntuacion;
        
        // Crear huésped
        Huesped* huesped = new Huesped(documento, nombre, antiguedadMeses, puntuacion);
        
        // Agregar huésped al sistema
        huespedes.agregar(huesped);
        
        std::cout << "Huésped registrado correctamente." << std::endl;
        monitor.registrarInteraccion();
    }
    
    void realizarReservacion() {
        std::string codigoAlojamiento, docHuesped;
        std::string fechaInicio, metodoPago;
        int duracion;
        
        std::cout << "===== REALIZAR RESERVACIÓN ====="  << std::endl;
        
        // Mostrar alojamientos disponibles
        std::cout << "Alojamientos disponibles:" << std::endl;
        Nodo<Alojamiento*>* actualAloj = alojamientos.getCabeza();
        while (actualAloj != nullptr) {
            std::cout << actualAloj->getDato()->getCodigo() << " - " << actualAloj->getDato()->getNombre() << std::endl;
            actualAloj = actualAloj->getSiguiente();
        }
        
        std::cout << "Código del alojamiento: ";
        std::cin >> codigoAlojamiento;
        
        // Buscar alojamiento
        Alojamiento alojamientoBusqueda;
        alojamientoBusqueda.setCodigo(codigoAlojamiento);
        Alojamiento* alojamiento = alojamientos.buscar(alojamientoBusqueda);
        
        if (alojamiento == nullptr) {
            std::cout << "No se encontró un alojamiento con ese código." << std::endl;
            return;
        }
        
        // Mostrar huéspedes registrados
        std::cout << "Huéspedes registrados:" << std::endl;
        Nodo<Huesped*>* actualHues = huespedes.getCabeza();
        while (actualHues != nullptr) {
            std::cout << actualHues->getDato()->getDocumento() << " - " << actualHues->getDato()->getNombre() << std::endl;
            actualHues = actualHues->getSiguiente();
        }
        
        std::cout << "Documento del huésped: ";
        std::cin >> docHuesped;
        
        // Buscar huésped
        Huesped huespedBusqueda;
        huespedBusqueda.setDocumento(docHuesped);
        Huesped* huesped = huespedes.buscar(&huespedBusqueda);
        
        if (huesped == nullptr) {
            std::cout << "No se encontró un huésped con ese documento." << std::endl;
            return;
        }
        
        std::cin.ignore();
        std::cout << "Fecha de inicio (DD/MM/AAAA): ";
        std::getline(std::cin, fechaInicio);
        
        std::cout << "Duración (días): ";
        std::cin >> duracion;
        
        // Verificar disponibilidad
        if (!alojamiento->verificarDisponibilidad(fechaInicio, "")) {
            std::cout << "El alojamiento no está disponible para esas fechas." << std::endl;
            return;
        }
        
        std::cin.ignore();
        std::cout << "Método de pago: ";
        std::getline(std::cin, metodoPago);
        
        // Calcular monto
        float monto = alojamiento->getPrecioNoche() * duracion;
        
        // Generar código único para la reservación
        std::string codigoReservacion = "RES" + std::to_string(time(nullptr));
        
        // Crear reservación
        Reservacion* reservacion = new Reservacion(
            codigoReservacion,
            fechaInicio,
            duracion,
            docHuesped,
            metodoPago,
            "Hoy", // Fecha de pago (simplificado)
            monto,
            alojamiento,
            huesped
        );
        
        // Agregar observaciones
        std::cout << "Observaciones: ";
        char observaciones[1000];
        std::cin.getline(observaciones, 1000);
        reservacion->setObservaciones(observaciones);
        
        // Agregar reservación al sistema, al alojamiento y al huésped
        reservaciones.agregar(reservacion);
        alojamiento->agregarReservacion(reservacion);
        huesped->getReservacionesActivas().agregar(reservacion);
        
        std::cout << "Reservación realizada correctamente." << std::endl;
        reservacion->imprimirComprobante();
        monitor.registrarInteraccion();
    }
    
    void cancelarReserva() {
        std::string codigoReservacion;
        
        std::cout << "===== CANCELAR RESERVACIÓN ====="  << std::endl;
        std::cout << "Código de la reservación: ";
        std::cin >> codigoReservacion;
        
        // Buscar reservación
        Reservacion reservacionBusqueda;
        reservacionBusqueda.setCodigo(codigoReservacion);
        Reservacion* reservacion = reservaciones.buscar(&reservacionBusqueda);
        
        if (reservacion == nullptr) {
            std::cout << "No se encontró una reservación con ese código." << std::endl;
            return;
        }
        
        // Eliminar reservación del alojamiento y del huésped
        if (reservacion->getAlojamiento() != nullptr) {
            reservacion->getAlojamiento()->quitarReservacion(reservacion);
        }
        
        if (reservacion->getHuesped() != nullptr) {
            reservacion->getHuesped()->getReservacionesActivas().eliminar(reservacion);
        }
        
        // Eliminar reservación del sistema
        reservaciones.eliminar(reservacion);
        delete reservacion;
        
        std::cout << "Reservación cancelada correctamente." << std::endl;
        monitor.registrarInteraccion();
    }
    
    void cargarDatos() {
        cargarAnfitriones();
        cargarHuespedes();
        cargarAlojamientos();
        cargarReservaciones();
        std::cout << "Datos cargados correctamente." << std::endl;
    }
    
    void guardarDatos() {
        guardarAnfitriones();
        guardarHuespedes();
        guardarAlojamientos();
        guardarReservaciones();
        std::cout << "Datos guardados correctamente." << std::endl;
    }
    
    void consultarAlojamientos() {
        std::cout << "===== CONSULTA DE ALOJAMIENTOS ====="  << std::endl;
        
        if (alojamientos.getCabeza() == nullptr) {
            std::cout << "No hay alojamientos registrados." << std::endl;
            return;
        }
        
        Nodo<Alojamiento*>* actual = alojamientos.getCabeza();
        while (actual != nullptr) {
            actual->getDato()->mostrarInfo();
            std::cout << "-----------------------------------" << std::endl;
            actual = actual->getSiguiente();
        }
        
        monitor.registrarInteraccion();
    }
    
    void consultarHuespedes() {
        std::cout << "===== CONSULTA DE HUÉSPEDES ====="  << std::endl;
        
        if (huespedes.getCabeza() == nullptr) {
            std::cout << "No hay huéspedes registrados." << std::endl;
            return;
        }
        
        Nodo<Huesped*>* actual = huespedes.getCabeza();
        while (actual != nullptr) {
            std::cout << *actual->getDato() << std::endl;
            std::cout << "-----------------------------------" << std::endl;
            actual = actual->getSiguiente();
        }
        
        monitor.registrarInteraccion();
    }
    
    void consultarReservaciones() {
        std::cout << "===== CONSULTA DE RESERVACIONES ====="  << std::endl;
        
        if (reservaciones.getCabeza() == nullptr) {
            std::cout << "No hay reservaciones registradas." << std::endl;
            return;
        }
        
        Nodo<Reservacion*>* actual = reservaciones.getCabeza();
        while (actual != nullptr) {
            actual->getDato()->imprimirComprobante();
            std::cout << "-----------------------------------" << std::endl;
            actual = actual->getSiguiente();
        }
        
        monitor.registrarInteraccion();
    }
    
    void actualizarHistorico() {
        std::cout << "Actualizando historial del sistema..." << std::endl;
        monitor.reporte();
        std::cout << "Historial actualizado correctamente." << std::endl;
    }
};

#endif // SISTEMAUDEASAY_H