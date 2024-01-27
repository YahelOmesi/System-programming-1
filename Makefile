.PHONY = all clean loops loopd recursives recursived 
FLAGS = -Wall -g

loops: libclassloops.a
recursives: libclassrec.a
recursived: libclassrec.so
loopd:libclassloops.so

#creating libraries
libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rcs -o libclassloops.a basicClassification.o advancedClassificationLoop.o
	ranlib libclassloops.a

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
	ranlib libclassrec.a

libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc -shared basicClassification.o advancedClassificationRecursion.o -o libclassrec.so

libclassloops.so: basicClassification.o advancedClassificationLoop.o
	gcc -shared basicClassification.o advancedClassificationLoop.o -o libclassloops.so 

#
main.o: main.c NumClass.h
	gcc -c $(FLAGS) main.c -o main.o

#main files
mains: main.o libclassrec.a
	gcc $(FLAGS) main.o libclassrec.a -o mains

maindloop: main.o
	gcc $(FLAGS) main.o ./libclassloops.so -o maindloop

maindrec: libclassrec.so
	gcc $(FLAGS) main.o ./libclassrec.so -o maindrec

#
basicClassification.o: basicClassification.c NumClass.h
	gcc $(FLAGS) -fPIC -c basicClassification.c -o basicClassification.o

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc $(FLAGS) -fPIC -c advancedClassificationRecursion.c -o advancedClassificationRecursion.o

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc $(FLAGS) -fPIC -c advancedClassificationLoop.c -o advancedClassificationLoop.o

#
all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so mains maindloop maindrec

clean:
	rm -f maindrec maindloop mains *.o *.so *.a











