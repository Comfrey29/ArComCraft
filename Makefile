# =====================================================
#  ArComCraft - Makefile
#  Projecte inspirat en Craft i ClassiCube
#  Motor base: SDL2 + OpenGL + SDL2_image
# =====================================================

# Compilador
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -g
LIBS    = `sdl2-config --cflags --libs` -lGL -lGLU -lSDL2_image -lm

# Carpetes
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Fitxers font principals
SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/gfx3d.c \
      $(SRC_DIR)/blocks3d.c \
      $(SRC_DIR)/world.c \
      $(SRC_DIR)/camera.c \
      $(SRC_DIR)/menu.c \
      $(SRC_DIR)/game.c

# Generar noms d'objectes automàticament
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Nom de l'executable
EXEC = $(BIN_DIR)/ArComCraft3D

# =====================================================
# Regles
# =====================================================

all: dirs $(EXEC)

# Compilar executable
$(EXEC): $(OBJ)
	@echo "🔧 Enllaçant $(EXEC)..."
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS)
	@echo "✅ Compilació completada correctament!"

# Compilar cada .c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "🧩 Compilant $< ..."
	$(CC) $(CFLAGS) -c $< -o $@

# Crear carpetes necessàries
dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

# Netejar compilació
clean:
	@echo "🧹 Eliminant fitxers compilats..."
	rm -rf $(OBJ_DIR) $(EXEC)

# Netejar tot
distclean: clean
	@echo "🗑️  Eliminant binaris..."
	rm -rf $(BIN_DIR)

# Executar joc
run: all
	@echo "🚀 Executant ArComCraft3D..."
	./$(EXEC)
