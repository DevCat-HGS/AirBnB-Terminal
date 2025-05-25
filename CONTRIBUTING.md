# Guía de Contribución - UdeAStay

## Proceso de Contribución

### 1. Preparación del Entorno
1. Fork del repositorio
2. Clonar el fork:
   ```bash
   git clone https://github.com/tu-usuario/UdeAStay.git
   cd UdeAStay
   ```
3. Configurar el repositorio upstream:
   ```bash
   git remote add upstream https://github.com/original/UdeAStay.git
   ```

### 2. Desarrollo de Cambios
1. Crear rama para la feature:
   ```bash
   git checkout -b feature/nombre-caracteristica
   ```
2. Realizar cambios siguiendo las convenciones de código
3. Ejecutar pruebas locales
4. Commit de cambios:
   ```bash
   git commit -m "feat: descripción del cambio"
   ```

## Convenciones de Código

### 1. Estilo de Código
```cpp
// Ejemplo de clase
class NombreClase {
private:
    // Variables miembro con prefijo m_
    int m_variable;
    
public:
    // Constructor explícito
    explicit NombreClase(int valor);
    
    // Métodos descriptivos
    void realizarAccion();
    int obtenerValor() const;
};
```

### 2. Nomenclatura
- **Clases**: PascalCase (ej: `ClaseEjemplo`)
- **Métodos**: camelCase (ej: `realizarAccion()`)
- **Variables**: camelCase (ej: `nombreVariable`)
- **Constantes**: SNAKE_CASE (ej: `VALOR_MAXIMO`)

### 3. Documentación
```cpp
/**
 * @brief Descripción breve de la función
 * @param parametro1 Descripción del primer parámetro
 * @param parametro2 Descripción del segundo parámetro
 * @return Descripción del valor retornado
 */
int funcionEjemplo(int parametro1, string parametro2);
```

## Proceso de Pull Request

### 1. Preparación
- Actualizar rama con upstream:
  ```bash
  git fetch upstream
  git rebase upstream/main
  ```
- Verificar cambios localmente
- Actualizar documentación si es necesario

### 2. Creación del PR
1. Subir cambios al fork:
   ```bash
   git push origin feature/nombre-caracteristica
   ```
2. Crear Pull Request en GitHub
3. Completar template de PR:
   ```markdown
   ## Descripción
   Breve descripción de los cambios

   ## Tipo de Cambio
   - [ ] Feature
   - [ ] Bug fix
   - [ ] Documentación
   - [ ] Optimización

   ## Pruebas Realizadas
   Descripción de las pruebas
   ```

## Estándares de Calidad

### 1. Pruebas
- Unitarias para nuevas funcionalidades
- Integración para cambios en flujos existentes
- Documentación de casos de prueba

### 2. Revisión de Código
- Legibilidad y mantenibilidad
- Optimización y rendimiento
- Seguridad y manejo de errores

## Buenas Prácticas

### 1. Commits
- Mensajes descriptivos y concisos
- Un commit por cambio lógico
- Seguir convención de commits semánticos:
  ```
  feat: nueva característica
  fix: corrección de bug
  docs: cambios en documentación
  style: cambios de formato
  refactor: refactorización de código
  test: cambios en pruebas
  ```

### 2. Branching
- `main`: rama principal
- `feature/*`: nuevas características
- `fix/*`: correcciones de bugs
- `docs/*`: actualizaciones de documentación

## Recursos Adicionales

### 1. Herramientas Recomendadas
- IDE: Visual Studio Code, CLion
- Linters: clang-format
- Debugger: GDB, LLDB

### 2. Referencias
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

## Soporte

### 1. Canales de Comunicación
- Issues de GitHub
- Discusiones del proyecto
- Canal de Discord

### 2. Reportar Problemas
1. Verificar si el issue ya existe
2. Usar el template de issues
3. Incluir pasos de reproducción
4. Adjuntar logs relevantes