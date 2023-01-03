#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;

double f(double x, double y, double z) {
    double a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
    return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}

double h(double x, double z) {
    for (double y = 1.0f; y >= 0.0f; y -= 0.001f) {
        if (f(x, y, z) <= 0.0f)
	    return y;
    }
    return 0.0f;
}

int main() {
    for (double z = 1.5f; z > -1.5f; z -= 0.05f) {
        for (double x = -1.5f; x < 1.5f; x += 0.025f) {
		    double v = f(x, 0.0f, z);
		    if (v <= 0.0f) {
				double y0 = h(x, z);
				double ny = 0.01f;
				double nx = h(x + ny, z) - y0;
				double nz = h(x, z + ny) - y0;
				double nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
				double d = (nx + ny - nz) * nd * 0.5f + 0.5f;
				cout << ".:-=+*#%@"[(int)(d * 5.0f)];
		    }
		    else cout << " ";
        }
        usleep(8000);
        cout << endl;
    }
    return 0;
}
