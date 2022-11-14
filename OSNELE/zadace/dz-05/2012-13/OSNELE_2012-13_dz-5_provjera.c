#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

typedef struct {
	double iznos;
	double smjer;
	double freq;
} v_cplx;

inline double v_cplx_x(v_cplx arg)
{
	return arg.iznos * cos(arg.smjer);
}

inline double v_cplx_y(v_cplx arg)
{
	return arg.iznos * sin(arg.smjer);
}

inline double smjer_stup(v_cplx arg)
{
	return arg.smjer / (2 * M_PI) * 360;
}

inline double v_cplx_at_t(v_cplx arg, double t)
{
	return arg.iznos * sin(arg.freq * t + arg.smjer);
}

v_cplx v_cplx_op(v_cplx a, v_cplx b, int sum)
{
	v_cplx rez;
	double rez_x, rez_y;

	if (sum) {
		rez_x = v_cplx_x(a) + v_cplx_x(b);
		rez_y = v_cplx_y(a) + v_cplx_y(b);
	} else {
		rez_x = v_cplx_x(a) - v_cplx_x(b);
		rez_y = v_cplx_y(a) - v_cplx_y(b);
	}
	rez.iznos = sqrt(pow(rez_x, 2) + pow(rez_y, 2));
	rez.smjer = atan(rez_y / rez_x);

	return rez;
}

int main()
{

	double a1, a2, f, w, t, ut;
	v_cplx u1m, u2m, u1, u2, uab;
	int i, smjer = -1;

	char *labels[] =
	    { "U1m[V]", "U2m[V]", "a1[rad]", "a2[rad]", "f[Hz]", "t[ms]" };
	double *data[] =
	    { &u1m.iznos, &u2m.iznos, &u1m.smjer, &u2m.smjer, &f, &t };

	for (i = 0; i < 6; ++i) {
		printf("%s\t:", labels[i]);
		scanf("%lf", data[i]);
	}

	while (smjer != 0 && smjer != 1) {
		printf("Jesu li izvori istog smjera? [0 - ne, 1 - da]: ");
		scanf("%d", &smjer);
	}

	t /= 1000;
	w = 2 * M_PI * f;

	u1m.freq = w;
	u2m.freq = w;

	u1.iznos = u1m.iznos / (sqrt(2));
	u1.smjer = u1m.smjer;
	u1.freq = w;

	u2.iznos = u2m.iznos / (sqrt(2));
	u2.smjer = u2m.smjer;
	u2.freq = w;

	uab = v_cplx_op(u1, u2, smjer);
	if (uab.smjer < 0) {
		uab.smjer += M_PI;
	}

	if (smjer) {
		ut = v_cplx_at_t(u1m, t) + v_cplx_at_t(u2m, t);
	} else {
		ut = v_cplx_at_t(u1m, t) - v_cplx_at_t(u2m, t);
	}

	printf("Uab : %.4lfV <%.2lf°\n", uab.iznos, smjer_stup(uab));
	printf("u(t): %.4lfV\n", ut);

}
