#include <stdio.h>

double f(double t, double y)
{
    double alpha = 1;
    return (-alpha * y);
}

void runge_kutta_4(double t0, double y0, double h, double tf)
{
	double	y = y0;
	double t = t0;
    double k1, k2, k3, k4;
	FILE *file;

	file = fopen("Runge_kutta_4_05.csv", "w");
	if (file == NULL)
	{
		printf("Erreur d'ouverture du fichier");
		return ;
	}
	fprintf(file, "t, y\n");
	fprintf(file , "%lf,%lf\n", t,y); // pour les conditions initiales
	while (t < tf)
	{
        k1 = h * f(t,y);
        k2 = h * f(t + h / 2, y + k1 / 2);
        k3 = h * f(t + h / 2, y + k2 / 2);
        k4 = h * f(t + h, y + k3);
		y = y + (k1 + 2 * k2+ 2 * k3 + k4)/6.0;

		t = t + h;
		fprintf(file, "%lf,%lf\n", t,y);
	}
	fclose(file);
}
int main(void)
{
	double t0 = 0.0;
	double tf = 4.0;
	double y0 = 1.0;
	double h = 0.5; // on modifie le h pour la precision 

	printf("Resultat\n");
	runge_kutta_4(t0, y0, h, tf);
}
