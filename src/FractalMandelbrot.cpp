
#include <iostream>
#include "gwindow.h"
#include <cmath>
#include <complex>
#include "gtypes.h"

using namespace std;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int MAX_IT = 100;

// min and max values of the real numbers
const double MIN_REAL = -2.0;
const double MAX_REAL = 0.5;

// min and max values of the imaginary numbers
const double MIN_IMAGINARY = -1.25;
const double MAX_IMAGINARY = 1.25;

int main() {
    GWindow gw(WINDOW_WIDTH, WINDOW_HEIGHT);
    double step = (abs(MAX_REAL) + abs(MIN_REAL)) / gw.getWidth();

    for (double i = MAX_IMAGINARY; i >= MIN_IMAGINARY; i -= step) {
        for (double r = MIN_REAL; r <= MAX_REAL; r += step) {
            int count = 0;
            complex<double> z = 0;
            complex<double> c(r, i);

            while (count < MAX_IT && abs(z) < 2) {
                z = pow(z, 2) + c;
                count++;
            }

            if (count == MAX_IT) {
                //  to draw in the window center
                double x = (r - MIN_REAL) * WINDOW_WIDTH / (abs(MAX_REAL) + abs(MIN_REAL));
                double y = (i - MIN_IMAGINARY) * WINDOW_HEIGHT / (abs(MAX_IMAGINARY) + abs(MAX_IMAGINARY));

                gw.drawOval(x, y, 1, 1);
            }
        }
    }

	return 0;
}
