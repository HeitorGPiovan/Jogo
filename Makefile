# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -IIncludes -ISFML/include

# Diretórios
SRC_DIR = scr
OBJ_DIR = ./Outputs/obj
BIN_DIR = ./Outputs
SFML_LIB_DIR = SFML/lib

# Nome do executável
TARGET = $(BIN_DIR)/main.exe

# Fontes e objetos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Bibliotecas SFML
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Caminho adicional para as bibliotecas no Windows
LDFLAGS = -L$(SFML_LIB_DIR)

# Regras
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Linkando: $@"
	$(CXX) $^ -o $@ $(LDFLAGS) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"
	@echo "Compilando: $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para dependências
-include $(OBJECTS:.o=.d)

# Gera dependências automaticamente
$(OBJ_DIR)/%.d: $(SRC_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -MM -MT $(@:.d=.o) $< > $@

clean:
	@echo "Limpando arquivos..."
	@if exist "$(OBJ_DIR)" rmdir /S /Q "$(OBJ_DIR)"
	@if exist "$(TARGET)" del "$(TARGET)"

run: all
	@echo "Executando o programa..."
	@$(TARGET)
