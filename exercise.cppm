export module exercise;
import std;
import broken_class;
using namespace std;

export BrokenLines<double> createTriangle(const Point<double>& start, double a, double angle) {
	if (a <= 0 || angle <= 0 || angle >= 180) {
		throw invalid_argument("invalid triangle parametres");

	}
	double radians = angle * numbers::pi / 180.0;
	Point<double> left = {
		start.x - a * sin(radians / 2.0),
		start.y - a * cos(radians / 2.0)
	};
	Point<double> right = {
	start.x + a * sin(radians / 2.0),
	start.y - a * cos(radians / 2.0)
	};
	BrokenLines<double> triangle(4);
	triangle[0] = start;
	triangle[1] = left;
	triangle[2] = right;
	triangle[3] = start;
	return triangle;
}