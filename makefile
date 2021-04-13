sand:	main.o particle.o cursor.o myTime.o
	gcc -g object/main.o object/particle.o object/cursor.o object/myTime.o -lncurses -o sand
particle.o:	particle.c particle.h
	gcc -c particle.c -o object/particle.o 
cursor.o:	cursor.c cursor.h
	gcc -c cursor.c -o object/cursor.o
myTime.o:	myTime.c myTime.h
	gcc -c myTime.c -o object/myTime.o
main.o:	main.c particle.h cursor.h myTime.h
	gcc -c main.c -o object/main.o
clean:
	rm main.o particle.o cursor.o myTime.o
