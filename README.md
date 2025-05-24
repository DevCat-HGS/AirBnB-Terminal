# Sistema UdeASay - Sistema de Gestión de Alojamientos

## Descripción
Sistema UdeASay es una aplicación de terminal para la gestión de alojamientos, similar a AirBnB. Permite administrar alojamientos, huéspedes, anfitriones y reservaciones a través de una interfaz de línea de comandos.

## Características Principales
- Gestión de alojamientos con detalles completos (ubicación, precio, amenidades)
- Sistema de reservaciones con validación de disponibilidad
- Administración de huéspedes y anfitriones
- Sistema de puntuación para huéspedes y anfitriones
- Monitoreo del sistema (uso de memoria e iteraciones)
- Persistencia de datos en archivos de texto

## Requisitos del Sistema
- Compilador C++ compatible con C++11 o superior
- Sistema operativo: Windows, Linux o macOS
- Memoria RAM: 512MB mínimo
- Espacio en disco: 10MB mínimo

## Instalación
1. Clonar el repositorio:
   ```bash
   git clone https://github.com/tu-usuario/Sistema-UdeASay.git
   ```
2. Compilar el proyecto:
   ```bash
   cd Sistema-UdeASay
   g++ -std=c++11 main.cpp -o udeasay
   ```
3. Ejecutar el programa:
   ```bash
   ./udeasay
   ```

## Estructura del Proyecto

### Clases Principales

#### `SistemaUdeASay`
- Clase principal que coordina todas las operaciones del sistema
- Gestiona la interacción con el usuario y la persistencia de datos
- Implementa operaciones CRUD para alojamientos, huéspedes y reservaciones
- Métodos principales:
  - `login()`: Gestiona la autenticación de usuarios
  - `registrarAlojamiento()`: Crea nuevos alojamientos
  - `realizarReservacion()`: Gestiona el proceso de reserva
  - `consultarAlojamientos()`: Muestra listados de alojamientos
  - `actualizarHistorico()`: Genera reportes del sistema

#### `Alojamiento`
- Representa un alojamiento en el sistema
- Atributos:
  - `codigo`: Identificador único del alojamiento
  - `nombre`: Nombre descriptivo
  - `tipo`: Categoría (casa, apartamento, habitación)
  - `ubicacion`: Departamento, municipio y dirección
  - `precioNoche`: Tarifa por noche
  - `amenidades`: Lista de servicios y comodidades
- Métodos principales:
  - `verificarDisponibilidad()`: Valida fechas disponibles
  - `mostrarInfo()`: Muestra detalles del alojamiento

#### `Huesped`
- Gestiona la información de los huéspedes
- Atributos:
  - `documento`: Identificación única
  - `nombre`: Nombre completo
  - `antiguedadMeses`: Tiempo en el sistema
  - `puntuacion`: Calificación promedio
  - `reservacionesActivas`: Lista de reservas vigentes

#### `Anfitrion`
- Administra los datos de los anfitriones
- Atributos:
  - `documento`: Identificación única
  - `antiguedad`: Años como anfitrión
  - `puntuacion`: Calificación promedio
  - `alojamientos`: Lista de propiedades registradas

#### `Reservacion`
- Maneja las reservaciones de alojamientos
- Atributos:
  - `codigo`: Identificador único de reserva
  - `fechaInicio`: Inicio de la estadía
  - `duracion`: Cantidad de noches
  - `metodoPago`: Forma de pago
  - `monto`: Costo total
  - `observaciones`: Notas adicionales
- Métodos principales:
  - `validarTraslapes()`: Verifica conflictos de fechas
  - `imprimirComprobante()`: Genera comprobante de reserva

### Estructuras de Datos

#### `Lista<T>`
- Implementación genérica de lista enlazada
- Operaciones:
  - `agregar()`: Inserta nuevo elemento
  - `eliminar()`: Remueve elemento existente
  - `buscar()`: Localiza elemento por criterio
  - `recorrer()`: Itera sobre elementos
  - `contar()`: Cuenta total de elementos

#### `Nodo<T>`
- Estructura base para la lista enlazada
- Componentes:
  - `dato`: Información almacenada
  - `siguiente`: Puntero al siguiente nodo

### Sistema de Monitoreo

#### `MonitorSistema`
- Realiza seguimiento del uso de memoria y las iteraciones
- Funcionalidades:
  - Conteo de iteraciones en operaciones
  - Registro de memoria utilizada
  - Generación de reportes estadísticos
- Métodos principales:
  - `sumarMemoria()`: Registra uso de memoria
  - `registrarIteracion()`: Cuenta operaciones
  - `reporte()`: Genera informe del sistema

## Archivos del Sistema
- `alojamientos.txt`: Almacena información de alojamientos
  - Formato: código|nombre|tipo|departamento|municipio|dirección|precio|anfitrión
  - Incluye amenidades en línea separada

- `huespedes.txt`: Registro de huéspedes
  - Formato: documento|nombre|antiguedad|puntuación

- `anfitriones.txt`: Datos de anfitriones
  - Formato: documento|antiguedad|puntuación

- `reservaciones.txt`: Historial de reservaciones
  - Formato: código|fechaInicio|duración|huésped|metodoPago|fechaPago|monto|observaciones|alojamiento

- `reporte_sistema.txt`: Estadísticas y reportes del sistema
  - Memoria total utilizada
  - Número total de iteraciones

## Funcionalidades del Menú Principal
1. Registrar nuevo alojamiento
   - Ingreso de datos básicos
   - Asignación de anfitrión
   - Registro de amenidades

2. Registrar nuevo huésped
   - Datos personales
   - Asignación de puntuación inicial

3. Realizar reservación
   - Selección de alojamiento
   - Verificación de disponibilidad
   - Cálculo de costos
   - Generación de comprobante

4. Cancelar reservación
   - Búsqueda por código
   - Actualización de disponibilidad

5. Consultar alojamientos
   - Listado completo
   - Detalles por alojamiento

6. Consultar huéspedes
   - Información personal
   - Historial de reservas

7. Consultar reservaciones
   - Estado actual
   - Detalles completos

8. Actualizar historial
   - Generación de reportes
   - Estadísticas del sistema

9. Guardar datos
   - Persistencia en archivos
   - Respaldo de información

10. Cerrar sesión
    - Finalización segura
    - Guardado automático

11. Salir
    - Cierre del programa
    - Guardado final

## Buenas Prácticas Implementadas
- Programación orientada a objetos
- Encapsulamiento de datos
- Manejo de memoria dinámica
- Validación de entrada de datos
- Persistencia de información
- Monitoreo de rendimiento

## Contribución
Si deseas contribuir al proyecto:
1. Realiza un Fork del repositorio
2. Crea una rama para tu característica (`git checkout -b feature/NuevaCaracteristica`)
3. Realiza tus cambios y commits (`git commit -am 'Agrega nueva característica'`)
4. Sube los cambios (`git push origin feature/NuevaCaracteristica`)
5. Abre un Pull Request

## Licencia
Este proyecto está bajo la Licencia MIT. Ver el archivo [LICENSE](LICENSE) para más detalles.

## Autores
- Nombre del Autor
- Colaboradores

## Contacto
Para preguntas y soporte:
- Email: ejemplo@email.com
- GitHub: [tu-usuario](https://github.com/tu-usuario)