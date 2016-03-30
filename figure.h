#ifndef	FIGURE_H
#define	FIGURE_H

#include <QColor>

#include "remplissage.h"

class Figure {
	protected:
		/*	Définitions des coordonnées	*/
		int x;
		int y;
		
		/*	Définitions des caractéristiques	*/
		QColor color;
		int thickness;
		Filling filling;
		int rotation;
		int opacity;
		
	public:
		Figure(int x, int y) : x(x), y(y), color(0,0,0), thickness(1), filling(vide), rotation(0), opacity(100) {};

		int get_x() 			{ return x; }
		int get_y() 			{ return y; }
		QColor get_color()	{ return color; }
		int get_thickness() 	{ return thickness; }
		Filling get_filling(){ return filling; }
		int get_rotation()	{ return rotation; }
		int get_opacity()		{ return opacity; }
		
		void set_x(int x) 						{ this->x = x; }
		void set_y(int y) 						{ this->y = y; }
		void set_color(QColor color) 			{ this->color = color; }
		void set_thickness(int thickness) 	{ this->thickness = thickness; }
		void set_filling(Filling filling)	{ this->filling = filling; }
		void set_rotation(int rotation)		{ this->rotation = rotation; }
		void set_opacity(int opacity)			{ this->opacity = opacity; }
		
		int alpha()				{ return opacity / 100; }
		QColor get_color_alpha() {
			int alpha = (opacity * 255) / 100;
			QColor c(color.red(), color.green(), color.blue(), alpha);
			return c;
		}
		
		virtual ~Figure() {};
};



#endif
