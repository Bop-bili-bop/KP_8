#ifndef COMPLEX_H
#define COMPLEX_H
typedef struct complex{
    double real;
    double imaginary;
}complex;

complex complex_division(complex a, complex b) {
    complex result;
    double detorminator = a.real * b.real + a.imaginary * b.imaginary;
    result.real = a.real*b.real / detorminator;
    result.imaginary = (b.real*a.imaginary + a.real*b.imaginary) / detorminator;
    return result;
}

void print_complex_number(complex number)
{
    printf("%e + i * %e\n", number.real, number.imaginary);
}
#endif //COMPLEX_H
