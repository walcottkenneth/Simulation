a.out: main.cc classes.h
        g++ -std=c++11 main.cc classes.h
clean:
        rm a.out
