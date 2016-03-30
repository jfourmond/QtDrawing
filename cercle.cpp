#include "cercle.h"

using namespace std;

Cercle::Cercle(int x, int y, int radius) : Figure(x, y), radius(radius) {}

ostream& Cercle::print(ostream & out) const {
	out << "Cercle :" << endl;
	out << "\t X : " << x << endl;
	out << "\t Y : " << y << endl;
	out << "\t Rayon : " << radius << endl; 
	out << "\t Couleur : (" << color.red() << "," << color.green() << "," << color.blue() << ")" << endl;
	out << "\t Epaisseur : " << thickness << endl;
	out << "\t Remplissage : " << filling << endl;
	out << "\t Rotation : " << rotation << "°" << endl;
	out << "\t Opacité : " << opacity << "%" <<endl;
	
	return out;
}
