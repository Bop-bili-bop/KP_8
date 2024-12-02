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
    double a = 0, b = 0, c = 0, d = 0;
    complex Z = {0, 0}, numerator = {0, 0}, denominator = {0, 0};
    do
    {

        circuit_choice = validate_char_input("Choose circuit(1-4):\n",
                        '1', '2', '3', '4');
        printf("You chose circuit #%c\n", circuit_choice);
        L = validate_double_input("Enter L:\n", 0.0);
        C = validate_double_input("Enter C:\n", 0.0);
        f_min = validate_double_input("Enter f_min:\n", 0.0);
        f_max = validate_double_input("Enter f_max:\n", f_min);
        switch (circuit_choice) {
            case '1':
            case '2':
                R = validate_double_input("Enter R:\n", 0.0);
                break;
            case '3':
            case '4':
                R1 = validate_double_input("Enter R1:\n", 0.0);
                R2 = validate_double_input("Enter R2:\n", 0.0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        df = validate_double_input("Enter df:\n", 0.0);
        int i = 0;
        f0 = calculate_resonant_frequency(L, C);
        printf("Resonant frequency = %g\n", f0);
        f = f_min;
        do {
            omega = 2.0 * M_PI * f;
            switch (circuit_choice) {
                case '1':
                    numerator.real = L / C;
                    numerator.imaginary = -R / (omega * C);
                    denominator.real = R;
                    denominator.imaginary = omega * L - 1.0 / (omega * C);
                    Z = complex_division(numerator, denominator);
                    break;
                case '2':
                    numerator.real = L / C;
                    numerator.imaginary = R / (omega * C);

                    denominator.real = R;
                    denominator.imaginary = omega * L - 1.0 / (omega * C);
                    Z = complex_division(numerator, denominator);
                    break;
                case '3':
                    numerator.real = R1 * R2;
                    numerator.imaginary = R1 * (omega * L - 1.0 / (omega * C));
                    denominator.real = R1 + R2;
                    denominator.imaginary = omega * L - 1.0 / (omega * C);
                    Z = complex_division(numerator, denominator);
                    break;
                case '4':
                    numerator.real = R1 * R2 + L / C;
                    numerator.imaginary = omega * L * R1 - R2*R2 / (omega * C);
                    denominator.real = R1 + R2;
                    denominator.imaginary = omega * L - 1.0 / (omega * C);
                    Z = complex_division(numerator, denominator);
                    break;
                default:
                    printf("Error");
                    break;
            }

            printf("f%d:%g\t", i+1, f);
            printf("df%d:%g\t", i+1, df);
            printf("Z[%d]: ", i+1);
            print_complex_number(Z);
            f+=df;
            i++;
        }while (f<=f_max);
        printf("Press 'q' to exit, any other key to continue\n");
    }while (getch() != 'q');
    return 0;
}