#ifndef LIGNE_H
#define LIGNE_H

#include <iostream>

#include "figure.h"

class Ligne : virtual public Figure {
	private:
		int x_end;
		int y_end;
	
	public:
		Ligne(int x, int y, int x_end, int y_end);
		
		int get_x_end() { return x_end; }
		int get_y_end() { return y_end; }
		
		void set_x_end(int x_end) { this->x_end = x_end; }
		void set_y_end(int y_end) { this->y_end = y_end; }

		std::ostream& print(std::ostream& out) const;

		friend std::ostream& operator<<(std::ostream& out, const Ligne & l) { return l.print(out); }
		
		~Ligne() {};
};

#endif
