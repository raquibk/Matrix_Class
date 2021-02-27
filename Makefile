# Name: Raquib Khan Lavani
# ID: 1622108
# Weekly Exercise #4: Matrix Class
# CMPUT 275, Winter 2021

# Target: matrix.o
# Dependancies: matrix.cpp
matrix.o: matrix.cpp
	g++ -c matrix.cpp

# Target: clean
clean:
	rm -f *.o