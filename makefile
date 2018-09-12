all:
	g++ -std=c++11  -O3 -o examples examples.cpp -fopenmp -lgsl -lgslcblas -lfftw3 -lm

clean:
	$(RM) examples

