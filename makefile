# Variáveis
CC = g++
CFLAGS = -std=c++20 -g -MMD -MP

# Arquivo de saida
TARGET = CRUD

# Diretórios dos arquivos
SRCDIR = src
OBJDIR = obj

# Lista de arquivos fonte
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

# Regra principal
$(TARGET): $(OBJS)
		@echo "\033[31m \nLinking all objects files: \033[0m"
		$(CC) $(CFLAGS) -o $@ $^

# Como compilar cada arquivo .cpp  em .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
		$(CC) $(CFLAGS) -c $< -o $@

# Garante que o diretório obj existe
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Inclui os arquivos de dependências, se existirem
-include $(DEPS)

# Limpeza
clean:
		@echo "\033[31mcleaning obj directory \033[0m"
		@rm -f $(OBJDIR)/*.o $(OBJDIR)/*.d

# Recompilar do zero
rebuild: clean $(TARGET)

# Define que esses alvos não são arquivos
.PHONY: all clean rebuild
