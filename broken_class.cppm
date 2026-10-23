export module broken_class;
import std;
import functions;
using namespace std;

export template <typename T> struct Point {
	T x = 0;
	T y = 0;
};

export template <typename T> class BrokenLines {
private:
	size_t size;
	Point<T>* data;
public:
	BrokenLines(const Point<T>& point) {
		size = 1;
		data = new Point<T>[size];
		data[0] = point;
	}
	BrokenLines(size_t counter) {
		size = counter;
		data = new Point<T>[size] {};
	}
	BrokenLines(size_t count, T m1, T m2) {
		if (!validRange(m1, m2)) {
			throw std::invalid_argument("Invalid coordinate range");
		}
		size = count;
		data = new Point<T>[size] {};

		for (size_t i = 0; i < size; ++i) {
			data[i].x = randomValue(m1, m2);
			data[i].y = randomValue(m1, m2);
		}
	}
	Point<T>& operator[](size_t index) {
		if (index >= size) {
			throw out_of_range("Point index out of range");
		}
		return data[index];
	}
	const Point<T>& operator[](size_t index) const {
		if (index >= size) {
			throw out_of_range("Point index out of range");
		}
		return data[index];
