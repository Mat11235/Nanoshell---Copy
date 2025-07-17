
#include <cmath>

void dflt(double* tildeN, double t_ps, double tpump, int* pip){
	if(t_ps >= tpump && *pip ==0) {
		*tildeN = 1.;
	// 	GG = set_GG(G, tau2);
		*pip = 1;
	}
}

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

void sinusoidalwave(double* tildeN, double Tperiod, double t_ps, double tpump, double G, double tau2){
	if (t_ps >= tpump) {
	    *tildeN = 0.5 * (1. + sin(2. * M_PI * (t_ps - tpump) / Tperiod));
		if(*tildeN > 0.9)
			nanosphere.set_GG(G, tau2);
	} else {
	    *tildeN = 0.0;
	}
}

