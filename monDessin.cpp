#include "monDessin.h"
#include <sstream>
#include <iostream>
using namespace std;

extern void trace(const char*);

monDessin::monDessin(QWidget * parent, Qt::WindowFlags flags) :QWidget(parent,flags) { }

void monDessin::set_figures(vector<Figure * > figures) {
	this->figures = figures;
}

void monDessin::show_figures() {
	for(Figure * F : figures) {
		Cercle * C = dynamic_cast<Cercle *> (F);
		Rectangle * R = dynamic_cast<Rectangle *> (F);
		Ligne * L = dynamic_cast<Ligne *> (F);
		if(C != nullptr) {
			cout << *C << endl;
		} else if(R != nullptr) {
			cout << * R << endl;
		} else if(L != nullptr) {
			cout << *L << endl;
		}
	}
}

QColor monDessin::getQColor(int R, int G, int B) {
	QColor q_color(R, G, B);
	return q_color;
}

void monDessin::paintCercle(Cercle * C, QPaintEvent *) {
	QPainter p(this);
	QPen pe;
	QColor color = C->get_color_alpha();
	
	// Couleur & Opacité
	pe.setBrush(color);
	// Epaisseur
	pe.setWidth(C->get_thickness());
	// Remplissage
	if(C->get_filling() == plein)
		p.setBrush(color);
	p.setPen(pe);
	
	p.drawEllipse(C->get_x()-C->get_radius(), C->get_y()-C->get_radius(), C->get_radius() * 2, C->get_radius() * 2);
	// Rotation
	p.rotate(C->get_rotation());
}

void monDessin::paintRectangle(Rectangle * R, QPaintEvent *) {
	QPainter p(this);
	QPen pe;
	QColor color = R->get_color_alpha();
	
	// Couleur & Opacité
	pe.setBrush(color);
	// Epaisseur
	pe.setWidth(R->get_thickness());
	// Remplissage
	if(R->get_filling() == plein)
		p.setBrush(color);
	p.setPen(pe);
	
	p.drawRect(R->get_x(), R->get_y(), R->get_length(), R->get_width());
	// Rotation
	p.rotate(R->get_rotation());
}

void monDessin::paintLigne(Ligne * L, QPaintEvent *) {
	QPainter p(this);
	QPen pe;
	QColor color = L->get_color_alpha();
	
	// Couleur & Opacité
	pe.setBrush(color);
	// Epaisseur
	pe.setWidth(L->get_thickness());
	// Remplissage
	if(L->get_filling() == plein)
		p.setBrush(color);
	p.setPen(pe);

	p.drawLine(L->get_x(), L->get_y(), L->get_x_end(), L->get_y_end());
	//	Rotation
	p.rotate(L->get_rotation());
}

void monDessin::paintEvent(QPaintEvent * PE) {
	for(Figure * F : figures) {
		Cercle * C = dynamic_cast<Cercle *> (F);
		Rectangle * R = dynamic_cast<Rectangle *> (F);
		Ligne * L = dynamic_cast<Ligne *> (F);
		if(C != nullptr) {
			paintCercle(C, PE);
		} else if(R != nullptr) {
			paintRectangle(R, PE);
		} else if(L != nullptr) {
			paintLigne(L, PE);
		}
	}
}

monDessin::~monDessin() {
	for(Figure * F : figures)
		free(F);
	figures.clear();
}
