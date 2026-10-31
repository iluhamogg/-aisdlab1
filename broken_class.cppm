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
	BrokenLines(const BrokenLines& other) {
		size = other.size;
		data = new Point<T>[size];
		for (size_t i = 0; i < size; ++i) {
			data[i] = other.data[i];
		}
	}
	BrokenLines& operator=(const BrokenLines& other) {
		if (this == &other) {
			return *this;
		}
		Point<T>* newData = new Point<T>[other.size];
		for (size_t i = 0; i < other.size; ++i) {
			newData[i] = other.data[i];
		}
		delete[] data;
		data = newData;
		size = other.size;
		return *this;
	}
	~BrokenLines() {
		delete[] data;
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
	bool operator==(const BrokenLines& other) const {
		if (size != other.size) {
			return false;
		}
		for (size_t i = 0; i < size; ++i) {
			if (!equalValues(data[i].x, other.data[i].x) || !equalValues(data[i].y, other.data[i].y)) {
				return false;
			}
		}
		return true;
	}
	bool operator!=(const BrokenLines& other) const {
		return !(*this == other);
	}
	BrokenLines& operator+=(const BrokenLines& other) {
		Point<T>* newData = new Point<T>[size + other.size];
		for (size_t i = 0; i < size; ++i) {
			newData[i] = data[i];
		}
		for (size_t i = 0; i < other.size; ++i) {
			newData[size + i] = other.data[i];
		}
		delete[] data;
		data = newData;
		size += other.size;
		return *this;
	}
	BrokenLines& operator+=(const Point<T>& point) {
		Point<T>* newData = new Point<T>[size + 1];
		for (size_t i = 0; i < size; ++i) {
			newData[i] = data[i];
		}
		newData[size] = point;
		delete[] data;
		data = newData;
		size += 1;
		return *this;
	}
	BrokenLines operator+(const BrokenLines& other) const {
		BrokenLines result(*this);
		result += other;
		return result;
	}
	BrokenLines operator+(const Point<T>& point) const {
		BrokenLines result(*this);
		result += point;
		return result;
	}
	size_t getSize() const {
		return size;
	}
	double getLength() const {
		double length = 0;
		for (size_t i = 1; i < size; ++i) {
			double dx = abs(data[i].x - data[i - 1].x);
			double dy = abs(data[i].y - data[i - 1].y);
			length += sqrt(dx * dx + dy * dy);
		}
		return length;
	}


};

export template<typename T>
ostream& operator<<(ostream& out, const BrokenLines<T>& line) {
	for (size_t i = 0; i < line.getSize(); ++i) {
		out << "Point " << i << ": (" << line[i].x << ", " << line[i].y << ")\n";
	}
	return out;
}

export template<typename T>
BrokenLines<T> operator+(const Point<T>& point, const BrokenLines<T>& line) {
	BrokenLines<T> result(point);
	result += line;
	return result;
}
