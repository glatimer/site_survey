CXX=g++
DEBUG=-g
RM=rm -f
CFLAGS=-g -c -Wall

test: process.o datalogger.o linkedList.o surveyData.o
	$(CXX) $(DEBUG) process.o datalogger.o linkedList.o surveyData.o -o process

process.o: process.cpp
	$(CXX) $(CFLAGS) process.cpp

datalogger.o: datalogger.cpp
	$(CXX) $(CFLAGS) datalogger.cpp

linkedList.o: linkedList.cpp
	$(CXX) $(CFLAGS) linkedList.cpp

surveyData.o: surveyData.cpp
	$(CXX) $(CFLAGS) surveyData.cpp

clean: 
	$(RM) test *.o *~D
