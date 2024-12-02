#include <stdio.h>
#include <math.h>
#include "calculation.h"
#include "complex.h"
#include "validation.h"
int main()
{
    char circuit_choice = 0;
    double R = 0, R1 = 0, R2 = 0, L = 0, C = 0, f_min =0, f_max = 0, df = 0;
    double omega = 0, f0 = 0, f = 0;
    do {
        complex Z = {0, 0}, a = {0, 0}, b = {0, 0};
        circuit_choice = validate_char_input("Choose circuit(1-4):\n",
                        '1', '2', '3', '4');
        L = validate_double_input("Enter L:\n", 0.0);
        C = validate_double_input("Enter C:\n", 0.0);
        R = validate_double_input("Enter R:\n", 0.0);
        f_min = validate_double_input("Enter f_min:\n", 0.0);
        f_max = validate_double_input("Enter f_max:\n", f_min);
        df = validate_double_input("Enter df:\n", 0.0);
        int i = 0;
        f0 = calculate_resonant_frequency(L, C);
        printf("Resonant frequency = %lf\n", f0);
        f = f_min;
        do {
            omega = 2.0 * M_PI * f;
            switch (circuit_choice) {
                case '1':
                    a.real = L/C;
                a.imaginary = -(R / (omega * C));
                b.real = R;
                b.imaginary = (omega * L) - (1.0 / (omega * C));
                Z = complex_division(a, b);
                break;
                case '2':
                    break;
                case '3':
                    break;
                case '4':
                    break;
                default:
                    printf("Error");
                break;
            }

            printf("f%d:%e\t", i+1, f);
            printf("df%d:%e\t", i+1, df);
            printf("z%d: ", i+1);
            print_complex_number(Z);
            f+=df;
            i++;
        }while (f<=f_max);
        printf("Press 'q' to exit, any other key to continue\n");
    }while (getch() != 'q');
    return 0;
}