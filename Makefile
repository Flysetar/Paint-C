GCC= gcc
CFLAGS = -W -Wall -std=c99 -O3
INCLUDE = -I.
LIBS = -lm -lglut -lGL -lGLU

TARGET = figure.o opengl.o main.o a_modifier.o list.o

all : $(TARGET)
	$(GCC) $(CFLAGS) $(INCLUDE) $(TARGET) -o paint $(LIBS)

%.o : %.c
	$(GCC) $(CFLAGS)  $(INCLUDE) -c $< -o $@

clean : 
	rm -f paint *~ *.o *.pdf *.log *.aux *.dvi
