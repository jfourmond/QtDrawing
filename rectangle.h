#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

#include "figure.h"

/**
 * Classe représentation un rectangle disposant des attributs particuliers :
 * 	- length (longueur)
 * 	- width (largeur)
 */
class Rectangle : virtual public Figure {
	private:
		int length;
		int width;
	
	public:
		Rectangle(int x, int y, int length, int width);
		
		int get_length() { return length; }
		int get_width() { return width; }
		
		void set_length(int length) { this->length = length; }
		void set_width(int width) { this->width = width; }

		std::ostream& print(std::ostream& out) const;

		friend std::ostream& operator<<(std::ostream& out, const Rectangle & r) { return r.print(out); }
		
		~Rectangle() {};
};

#endif
