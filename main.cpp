#include "cercle.h"

#include "parser.tab.cpp"
#include "monDessin.h"

#include <QtGui>
#include <QApplication>

#include <iostream>

using namespace std;

int main ( int argc , char ** argv ) {
	FILE * file = nullptr;
	
	if(argc > 1) {
		// Lecture de fichier
		file = fopen(argv[1], "r");
		if(file) yyin = file;
	}

	QApplication app(argc,argv);
	QMainWindow * w = new QMainWindow;
	
	trace(w);
	
	return app.exec();
}
