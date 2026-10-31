import std;
import broken_class;
import exercise;
using namespace std;

void testConstructors() {
    Point<int> point = { 3, 4 };

    BrokenLines<int> line1(point);
    BrokenLines<int> line2(3);
    BrokenLines<int> line3(3, 1, 10);

    cout << "Line from point:\n" << line1;
    cout << "Line from count:\n" << line2;
    cout << "Random line:\n" << line3;
}

void testCopy() {
    BrokenLines<int> line1(3, 1, 10);
    BrokenLines<int> line2 = line1;

    BrokenLines<int> line3(1);
    line3 = line1;

    cout << "Original:\n" << line1;
    cout << "Copy:\n" << line2;
    cout << "Assigned:\n" << line3;
}

void testOperators() {
    BrokenLines<int> line1(3, 1, 10);
    BrokenLines<int> line2 = line1;
    BrokenLines<int> line3 = line1;

    Point<int> point = { 3, 4 };

    cout << "Equal: " << (line1 == line2) << '\n';

    line2[0] = { 100, 100 };

    cout << "Not equal: " << (line1 != line2) << '\n';

    line3 += line2;
    cout << "Line += line:\n" << line3;

    line3 += point;
    cout << "Line += point:\n" << line3;

    cout << "Line + line:\n" << line1 + line2;
    cout << "Line + point:\n" << line1 + point;
    cout << "Point + line:\n" << point + line1;

    cout << "Length: " << line1.getLength() << '\n';
    cout << "Size: " << line1.getSize() << '\n';
}

void testTypes() {
    BrokenLines<int> intLine(3, 1, 10);
    BrokenLines<float> floatLine(3, 1.0f, 10.0f);
    BrokenLines<double> doubleLine(3, 1.0, 10.0);

    BrokenLines<complex<float>> complexFloatLine(3, { 1.0f, 2.0f }, { 10.0f, 20.0f });

    BrokenLines<complex<double>> complexDoubleLine(3, { 1.0, 2.0 }, { 10.0, 20.0 });

    cout << "Int:\n" << intLine;
    cout << "Float:\n" << floatLine;
    cout << "Double:\n" << doubleLine;
    cout << "Complex float:\n" << complexFloatLine;
    cout << "Complex double:\n" << complexDoubleLine;
}

void testExceptions() {
    try {
        BrokenLines<int> line(3);
        cout << line[10].x << '\n';
    }
    catch (const out_of_range& error) {
        cout << "Index error: " << error.what() << '\n';
    }

    try {
        BrokenLines<int> line(3, 10, 1);
        cout << line;
    }
    catch (const invalid_argument& error) {
        cout << "Range error: " << error.what() << '\n';
    }
}

void runExercise() {
    double x, y, a, angle;

    cout << "Enter starting point (x y): ";
    cin >> x >> y;

    cout << "Enter side length: ";
    cin >> a;

    cout << "Enter vertex angle: ";
    cin >> angle;

    try {
        Point<double> start = { x, y };

        BrokenLines<double> triangle = createTriangle(start, a, angle);

        cout << "Triangle:\n" << triangle;
        cout << "Perimeter: " << triangle.getLength() << '\n';
    }
    catch (const invalid_argument& error) {
        cout << "Error: " << error.what() << '\n';
    }
}

int main() {
    testConstructors();
    testCopy();
    testOperators();
    testTypes();
    testExceptions();
    runExercise();

    return 0;
}