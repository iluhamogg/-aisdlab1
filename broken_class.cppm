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
	}
	BrokenLines operator+(const BrokenLines& other) const {
		BrokenLines result(size + other.size);
		for (size_t i = 0; i < size; ++i) {
			result.data[i] = data[i];
		}
		for (size_t i = 0; i < other.size; ++i) {
			result.data[size + i] = other.data[i];
		}
		return result;
	}
	BrokenLines operator+(const Point<T>& point) const {
		BrokenLines result(size + 1);
		for (size_t i = 0; i < size; ++i) {
			result.data[i] = data[i];
		}
		result.data[size] = point;
		return result;
	}
	size_t getSize() const {
		return size;
	}

};

export template<typename T>
BrokenLines<T> operator+(const Point<T>& point, const BrokenLines<T>& line) {
	BrokenLines<T> result(line.getSize() + 1);
	result[0] = point;
	for (size_t i = 0; i < line.getSize(); ++i) {
		result[i + 1] = line[i];
	}
	return result;
}
