TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    heap.cpp \
    graph.cpp \
    graphutils.cpp \
    djikstranaive.cpp \
    djikstraheap.cpp \
    unionfind.cpp

HEADERS += \
    heap.h \
    graph.h \
    graphutils.h \
    djikstranaive.h \
    djikstraheap.h \
    unionfind.h
