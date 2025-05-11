# Nombre del ejecutable
EXEC = bin/grafo

# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -std=c++17 -w

# Archivos fuente
SRCS = main.cpp TADS/Grafo.cpp TADS/Cita.cpp

# Archivos objeto
OBJS = bin/main.o bin/TADS/Grafo.o bin/TADS/Cita.o

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
bin/main.o: main.cpp | bin
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/TADS/Grafo.o: TADS/Grafo.cpp | bin/TADS
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/TADS/Cita.o: TADS/Cita.cpp | bin/TADS
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crear carpetas necesarias
bin:
	$(MKDIR) -p bin

bin/TADS:
	$(MKDIR) bin/TADS

# Limpiar archivos compilados
clean:
	$(RMDIR) -rf bin
	$(RM) -f $(EXEC)
	clear

# Ejecutar el programa
run: $(EXEC)
	./$(EXEC)