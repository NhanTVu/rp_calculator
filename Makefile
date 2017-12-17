# Makefile for Project
CC = g++
CFLAGS = -g -w -std=c++11 -c 

CXXFLAGS = -std=c++11
LDFLAGS = -L/usr/local/lib -lfltk -lXext -lX11 -lm -Wl,-Bsymbolic-functions -lfltk_images -lfltk -lX11

all: gui

rebuild: clean gui

gui: gui.cpp
	$(CXX) $(CXXFLAGS) $(fltk-config --use-images --cxxflags) -o gui GuiMain.cpp $(LDFLAGS)
main: Robot_model.o Shop.o View.o Battery.o Head.o Arm.o Torso.o Locomotor.o Robot_part.o Controller.o Customer.o SalesAssociate.o Order.o
	$(CC) Robot_model.o Shop.o View.o Battery.o Head.o Arm.o Torso.o Locomotor.o Customer.o SalesAssociate.o Robot_part.o Controller.o Order.o -o cli main_cli.cpp
rp.o: rp.cpp 
	$(CC) $(CFLAGS) rp.cpp
Battery.o: Battery.cpp Battery.h
	$(CC) $(CFLAGS) Battery.cpp
Head.o: Head.cpp Head.h
	$(CC) $(CFLAGS) Head.cpp


clean:
	-rm  -f *.o a.out gui cli
