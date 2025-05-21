#include <iostream>
using namespace std;


class ColorPoint {
private:
    int x, y;
    int red, green, blue;

   
    int checkColor(int value) {
        if (value < 0) return 0;
        if (value > 255) return 255;
        return value;
    }

public:
    
    ColorPoint() : x(0), y(0), red(0), green(0), blue(0) {}

   
    ColorPoint(int x, int y, int r, int g, int b) {
        this->x = x;
        this->y = y;
        red = checkColor(r);
        green = checkColor(g);
        blue = checkColor(b);
    }

   
    void setColor(int r, int g, int b) {
        red = checkColor(r);
        green = checkColor(g);
        blue = checkColor(b);
    }

    
    void print() const {
        cout << "Point (" << x << ", " << y << ") ";
        cout << "Color (R:" << red << ", G:" << green << ", B:" << blue << ")" << endl;
    }

   
    ~ColorPoint() {
        cout << "Point deleted\n";
    }
};


class Line {
private:
    ColorPoint start;
    ColorPoint end;

public:
    
    Line() : start(), end() {}

    
    Line(int x1, int y1, int x2, int y2, int r, int g, int b)
        : start(x1, y1, r, g, b), end(x2, y2, r, g, b) {}

    
    void print() const {
        cout << "Line:\n  Start: ";
        start.print();
        cout << "  End: ";
        end.print();
    }

   
    ~Line() {
        cout << "Line deleted\n";
    }
};


int main() {
    int x, y, r, g, b;

    cout << "--- Point input ---\n";
    cout << "Enter point coordinates (x y): ";
    cin >> x >> y;

    cout << "Enter color (R G B): ";
    cin >> r >> g >> b;

    ColorPoint userPoint(x, y, r, g, b);
    userPoint.print();

    cout << "\n--- Line input ---\n";
    int x2, y2;

    cout << "Enter start point coordinates (x1 y1): ";
    cin >> x >> y;

    cout << "Enter end point coordinates (x2 y2): ";
    cin >> x2 >> y2;

    cout << "Enter color (R G B): ";
    cin >> r >> g >> b;

    Line userLine(x, y, x2, y2, r, g, b);
    userLine.print();

    return 0;
}

