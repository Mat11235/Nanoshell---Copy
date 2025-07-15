
#include <cmath>

void squarewave(double* tildeN, double Tperiod, double duty, double t_ps, double tpump){
	if (t_ps >= tpump) {
		    // onda cuadrada: tildeN = 1 durante el pulso, luego 0
		    double local_t = fmod(t_ps - tpump, Tperiod);
		    if (local_t < duty * Tperiod) {
		        *tildeN = 1.;  // bomba encendida
		    } else {
		        *tildeN = 0;  // bomba apagada
		    }
		} else {
		    *tildeN = 0;  // antes de tpump, no hay bomba
		}
}

void sinusoidalwave(double* tildeN, double Tperiod, double t_ps, double tpump){
	if (t_ps >= tpump) {
	    tildeN = 0.5 * (1. + sin(2. * M_PI * (t_ps - tpump) / Tperiod));
	} else {
	    tildeN = 0.0;
	}
}

