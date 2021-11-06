all: exe_arq

exe_arq: main.o botao.o
	g++ -o exe_arq main.o botao.o `pkg-config gtkmm-3.0 --cflags --libs`

main.o: main.cpp botao.h
	g++ -o main.o main.cpp -c `pkg-config gtkmm-3.0 --cflags --libs`

botao.o: botao.cpp 
	g++ -o botao.o botao.cpp -c `pkg-config gtkmm-3.0 --cflags --libs`

run: exe_arq
	./exe_arq