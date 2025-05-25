# Sistema UdeAStay

## Descripción
UdeAStay es un sistema de gestión de alojamientos y reservaciones desarrollado en C++. Permite a los usuarios buscar, reservar y administrar alojamientos, así como gestionar perfiles de huéspedes y administradores.

## Características Principales
- Gestión de alojamientos
- Sistema de reservaciones
- Autenticación de usuarios
- Perfiles de huéspedes y administradores
- Gestión de disponibilidad
- Historial de reservaciones

## Requisitos del Sistema
- Compilador C++ (GCC 7.0 o superior)
- Sistema operativo: Windows/Linux/MacOS
- Memoria RAM: 2GB mínimo
- Espacio en disco: 100MB mínimo

## Instalación

1. Clonar el repositorio:
```bash
git clone https://github.com/tu-usuario/UdeAStay.git
cd UdeAStay
```

2. Compilar el proyecto:
```bash
g++ -o udeaStay main.cpp
```

3. Ejecutar el programa:
```bash
./udeaStay
```

## Uso

### Como Huésped
1. Registrarse en el sistema
2. Iniciar sesión
3. Buscar alojamientos disponibles
4. Realizar reservaciones
5. Ver historial de reservas
6. Cancelar reservaciones activas

### Como Administrador
1. Iniciar sesión como administrador
2. Gestionar alojamientos
3. Administrar usuarios
4. Ver reportes del sistema

## Estructura del Proyecto
```
UdeAStay/
├── src/
│   ├── main.cpp
│   ├── SistemaUdeAStay.h
│   ├── Alojamiento.h
│   ├── Huesped.h
│   └── Reservacion.h
├── data/
│   ├── alojamientos.txt
│   ├── huespedes.txt
│   └── reservaciones.txt
├── docs/
│   ├── ARCHITECTURE.md
│   ├── CONTRIBUTING.md
│   └── TESTING.md
└── README.md
```

## Persistencia de Datos
El sistema utiliza archivos de texto para almacenar la información:
- `alojamientos.txt`: Información de alojamientos disponibles
- `huespedes.txt`: Datos de usuarios registrados
- `reservaciones.txt`: Registro de reservaciones

## Contribución
Si deseas contribuir al proyecto:
1. Revisa la guía de contribución en CONTRIBUTING.md
2. Crea un fork del repositorio
3. Crea una rama para tu feature
4. Envía un pull request

## Pruebas
Consulta TESTING.md para información sobre:
- Ejecución de pruebas unitarias
- Pruebas de integración
- Casos de prueba
- Automatización

## Licencia
Este proyecto está bajo la Licencia MIT. Ver el archivo LICENSE para más detalles.

## Contacto
Para preguntas o sugerencias:
- Email: contacto@udeaStay.com
- GitHub: [UdeAStay](https://github.com/tu-usuario/UdeAStay)