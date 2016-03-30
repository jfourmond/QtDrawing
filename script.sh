#!/bin/bash

bison -d parser.ypp
flex parser.lex
qmake "Projet 2015-2016.pro"

make
