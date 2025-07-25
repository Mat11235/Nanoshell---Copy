
#include <cmath>


	void dflt(double* tildeN, double t_ps, double tpump, int* pip){
		if(t_ps >= tpump && *pip ==0) {
			*tildeN = 1.;
		// 	GG = set_GG(G, tau2);
			*pip = 1;
		}
	}
	
	void squarewave(double* tildeN, double Tperiod, double duty, double t_ps, double tpump, std::complex<double>* GG, double G, double tau2){
		if (t_ps >= tpump) {
			    // onda cuadrada: tildeN = 1 durante el pulso, luego 0
			    double local_t = fmod(t_ps - tpump, Tperiod);
			    if (local_t < duty * Tperiod) {
			        *tildeN = 1.;  // bomba encendida
				*GG = set_GG(-0.14, tau2);
			    } else {
			        *tildeN = 0;  // bomba apagada
				*GG = set_GG(G, tau2);
			    }
			} else {
			    *tildeN = 0;  // antes de tpump, no hay bomba
			}
	}
	
	void sinusoidalwave(double* tildeN, double Tperiod, double t_ps, std::complex<double>* GG, double G, double tau2){
	    *tildeN = 0.5 * (1. + sin(2. * M_PI * t_ps / Tperiod));
		if(*tildeN > 0.6){
			*GG = set_GG(-0.14, tau2);
		} else {
			*GG = set_GG(G, tau2);
		}	
	}
