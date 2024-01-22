# Makefile para compilar o programa todolist com ncurses

# Nome do executável
TARGET = todolist.x

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall

# Lista de arquivos fonte
SRCS = Register.c todolist.c Logos.c  AboutTheProject.c 

# Regra principal: compilar o programa
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) -lncurses -DNCURSES_STATIC 

# Regra para limpar os arquivos gerados
clean:
	rm -f $(TARGET)

