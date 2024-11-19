#include <stdio.h>

double f(double t, double y)
{
    double alpha = 1;
    return (-alpha * y);
}

void runge_kutta_2(double t0, double y0, double h, double tf)
{
	double	y = y0;
	double t = t0;
    double k1;
    double k2;
	FILE *file;

	file = fopen("Runge_kutta_2_05.csv", "w");
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
        k2 = h * f(t + h, y + k1);
		y = y + 0.5*(k1 + k2);
        
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

	printf("Resultat de la resolution de l'equation y(t) = exp(-alpha * t) par la methode d'euler implicite\n");
	runge_kutta_2(t0, y0, h, tf);
}
