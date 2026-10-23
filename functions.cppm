export module functions;
import std;
using namespace std;

export int randomValue(int min, int max) {
	static mt19937 gen(random_device{}());
	uniform_int_distribution<int> dist(min, max);
	return dist(gen);
}

export float randomValue(float min, float max) {
	static mt19937 gen(random_device{}());
	uniform_real_distribution<float> dist(min, max);
	return dist(gen);
}

export double randomValue(double min, double max) {
	static mt19937 gen(random_device{}());
	uniform_real_distribution<double> dist(min, max);
	return dist(gen);
}

export complex<float> randomValue(complex<float> min, complex<float> max) {
	return { randomValue(min.real(), max.real()), randomValue(min.imag(), max.imag()) };
}
export complex<double> randomValue(complex<double> min, complex<double> max) {
	return { randomValue(min.real(), max.real()), randomValue(min.imag(), max.imag()) };