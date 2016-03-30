#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(int x, int y, int length, int width) : Figure(x, y), length(length), width(width) {}

ostream& Rectangle::print(ostream & out) const {
	out << "Rectangle :" << endl;
	out << "\t X : " << x << endl;
	out << "\t Y : " << y << endl;
	out << "\t Longueur : " << length << endl;
	out << "\t Largeur : " << width << endl;
	out << "\t Couleur : (" << color.red() << "," << color.green() << "," << color.blue() << ")" << endl;
	out << "\t Epaisseur : " << thickness << endl;
	out << "\t Remplissage : " << filling << endl;
	out << "\t Rotation : " << rotation << "°" << endl;
	out << "\t Opacité : " << opacity << "%" <<endl;
	
    return out;
}
