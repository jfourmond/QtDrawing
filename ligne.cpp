#include "ligne.h"

using namespace std;

Ligne::Ligne(int x, int y, int x_end, int y_end) : Figure(x, y), x_end(x_end), y_end(y_end) {}

ostream& Ligne::print(ostream & out) const {
	out << "Ligne :" << endl;
	out << "\t X1 : " << x << endl;
	out << "\t Y1 : " << y << endl;
	out << "\t X2 : " << x_end << endl;
	out << "\t Y2 : " << y_end << endl;
	out << "\t Couleur : (" << color.red() << "," << color.green() << "," << color.blue() << ")" << endl;
	out << "\t Epaisseur : " << thickness << endl;
	out << "\t Remplissage : " << filling << endl;
	out << "\t Rotation : " << rotation << "°" << endl;
	out << "\t Opacité : " << opacity << "%" <<endl;
	
    return out;
}
