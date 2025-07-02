CC = g++
CFlags = -Wall
TARGET = main

OBJS = main.o Passageiro.o Voo.o Aeronave.o Pessoa.o Piloto.o GerenciadorVoos.o


$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)