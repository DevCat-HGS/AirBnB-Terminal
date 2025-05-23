# Sistema UdeASay - Sistema de Gestión de Alojamientos

## Descripción
Sistema UdeASay es una aplicación de terminal para la gestión de alojamientos, similar a AirBnB. Permite administrar alojamientos, huéspedes, anfitriones y reservaciones a través de una interfaz de línea de comandos.

## Características Principales
- Gestión de alojamientos con detalles completos (ubicación, precio, amenidades)
- Sistema de reservaciones con validación de disponibilidad
- Administración de huéspedes y anfitriones
- Sistema de puntuación para huéspedes y anfitriones
- Monitoreo del sistema (uso de memoria e interacciones)
- Persistencia de datos en archivos de texto

## Estructura del Proyecto

### Clases Principales

#### `SistemaUdeASay`
- Clase principal que coordina todas las operaciones del sistema
- Gestiona la interacción con el usuario y la persistencia de datos
- Implementa operaciones CRUD para alojamientos, huéspedes y reservaciones

#### `Alojamiento`
- Representa un alojamiento en el sistema
- Atributos: código, nombre, tipo, ubicación, precio, amenidades
- Gestiona la disponibilidad y las reservaciones asociadas

#### `Huesped`
- Gestiona la información de los huéspedes
- Atributos: documento, nombre, antigüedad, puntuación
- Mantiene un registro de reservaciones activas

#### `Anfitrion`
- Administra los datos de los anfitriones
- Atributos: documento, antigüedad, puntuación
- Mantiene una lista de alojamientos asociados

#### `Reservacion`
- Maneja las reservaciones de alojamientos
- Atributos: código, fechas, duración, método de pago, monto
- Incluye validación de disponibilidad y generación de comprobantes

### Estructuras de Datos

#### `Lista<T>`
- Implementación genérica de lista enlazada
- Operaciones: agregar, eliminar, recorrer, buscar, contar
- Utilizada para almacenar colecciones de objetos en el sistema

#### `Nodo<T>`
- Estructura base para la lista enlazada
- Almacena datos genéricos y referencia al siguiente nodo

### Sistema de Monitoreo

#### `MonitorSistema`
- Realiza seguimiento del uso de memoria y las interacciones
- Genera reportes del sistema
- Guarda estadísticas en archivo de texto

## Archivos del Sistema
- `alojamientos.txt`: Almacena información de alojamientos
- `huespedes.txt`: Registro de huéspedes
- `anfitriones.txt`: Datos de anfitriones
- `reservaciones.txt`: Historial de reservaciones
- `reporte_sistema.txt`: Estadísticas y reportes del sistema

## Funcionalidades del Menú Principal
1. Registrar nuevo alojamiento
2. Registrar nuevo huésped
3. Realizar reservación
4. Cancelar reservación
5. Consultar alojamientos
6. Consultar huéspedes
7. Consultar reservaciones
8. Actualizar historial
9. Guardar datos
10. Cerrar sesión
11. Salir

## Licencia
Este proyecto está bajo la Licencia MIT. Ver el archivo [LICENSE](LICENSE) para más detalles.