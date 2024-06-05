CXX=g++
CXXFLAGS=-std=c++17 -Wall -Werror -Wextra -pedantic -UQT_MACRO
APP = build/SmartCalc_v2.app

all: install

OPEN_CMD = open
ifeq ($(OS),Linux)
 OPEN_CMD = xdg-open
endif

build:
	mkdir build
	cd ./build/ && qmake ../ && make && mv Smart_Calc_v2.app SmartCalc_v2.app

tests:
	$(CXX) unit_tests/unit_tests.cpp model/model.cpp -lstdc++ -lgtest $(CXXFLAGS) -o tests
	./tests

install: build
	@mkdir $(HOME)/Desktop/SmartCalc_v2.0/
	@cp -rf $(APP) $(HOME)/Desktop/SmartCalc_v2.0/
	make clean

clean:
	rm -rf build ./*.o ./*.a ./a.out ./*.tar ./*.gcno ./*.gcda ./gcov_report *.info ./*.info tests

uninstall:
	@rm -rf build*
	@rm -rf $(HOME)/Desktop/SmartCalc_v2.0

dist:
	mkdir SmartCalc_v2.0_dist/
	mkdir SmartCalc_v2.0_dist/src
	cp Makefile controller/* dvi.html model/* unit_tests/* view/* *.pro *.cpp *.h SmartCalc_v2.0_dist/src/
	tar cvzf SmartCalc_v2.0_dist.tgz SmartCalc_v2.0_dist/
	mv SmartCalc_v2.0_dist.tgz $(HOME)/Desktop/
	rm -rf SmartCalc_v2.0_dist/

dvi:
	$(OPEN_CMD) dvi.html

make_style:
	clang-format -style=Google -i controller/* model/* view/* plot/* unit_tests/*

check_style:
	clang-format -style=Google -n controller/* model/* view/* plot/* unit_tests/*
