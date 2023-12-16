# Makefile para compilar o programa todolist com ncurses

# Nome do executável
TARGET = todolist.x

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall

# Lista de arquivos fonte
SRCS = todolist.c

# Regra principal: compilar o programa
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) -lncurses

# Regra para limpar os arquivos gerados
clean:
	rm -f $(TARGET)
