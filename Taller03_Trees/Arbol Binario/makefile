# Nombre del ejecutable
EXEC = bin/PruebaArbolBinario

# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -std=c++17

# Archivos fuente
SRCS = PruebaArbolBinario.cpp

# Archivos objeto
OBJS = bin/PruebaArbolBinario.o

# Detectar sistema operativo
OS := $(shell uname 2>/dev/null || echo Windows)
ifeq ($(OS),Windows)
    MKDIR = mkdir
    RMDIR = rmdir /S /Q
    RM = del /Q
else
    MKDIR = mkdir -p
    RMDIR = rm -rf
    RM = rm -f
endif


# Regla principal: compilar el ejecutable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

# Regla para compilar archivos .cpp a .o en bin/
bin/PruebaArbolBinario.o: PruebaArbolBinario.cpp | bin
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crear carpetas necesarias
bin:
	$(MKDIR) -p bin


# Limpiar archivos compilados
clean:
	$(RMDIR) -rf bin
	$(RM) -f $(EXEC)
	clear

# Ejecutar el programa
run: $(EXEC)
	./$(EXEC)