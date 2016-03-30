#ifndef MONDESSIN_H
#define MONDESSIN_H

#include <QtGui>
#include <QMainWindow>
#include <vector>

#include "cercle.h"
#include "figure.h"
#include "ligne.h"
#include "rectangle.h"

class monDessin:public QWidget {
	Q_OBJECT

	private:
		std::vector<Figure *> figures;
		
	public:
		monDessin(QWidget * parent=0, Qt::WindowFlags flags=0);
		
		void set_figures(std::vector<Figure *> figures);
		
		void show_figures();
		
		static QColor getQColor(int R, int G, int B);
		
		void paintCercle(Cercle * C, QPaintEvent *);
		void paintRectangle(Rectangle * R, QPaintEvent *);
		void paintLigne(Ligne * L, QPaintEvent *);
		
		void paintEvent(QPaintEvent *);
		void draw() {update();}
		
		~monDessin();
};


#endif
