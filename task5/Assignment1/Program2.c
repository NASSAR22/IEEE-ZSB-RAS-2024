#include <stdio.h>

typedef struct {
    float real;
    float imaginary;
} Complex;

Complex addComplex(Complex n1, Complex n2) {
    Complex result;
    result.real = n1.real + n2.real;
    result.imaginary = n1.imaginary + n2.imaginary;
    return result;
}

int main() {
    Complex n1, n2, sum;

    printf("Enter the real and imaginary parts of the first complex number:\n");
    scanf("%f %f", &n1.real, &n1.imaginary);

    printf("Enter the real and imaginary parts of the second complex number:\n");
    scanf("%f %f", &n2.real, &n2.imaginary);

    sum = addComplex(n1, n2);

    printf("Sum = %.2f + %.2fi\n", sum.real, sum.imaginary);

    return 0;
}
