#include <complex.h>
#include <math.h>
#include <stdio.h>

const double PI = 3.141592653589793238462643383279502884197;

// Function to perform the Cooley-Tukey radix-2 DIT FFT
void fft_recursive(complex double *a, int n) {
    if (n <= 1) return;

    // Split the input into even and odd parts
    complex double a_even[n/2], a_odd[n/2];
    for (int i = 0; i < n / 2; i++) {
        a_even[i] = a[i * 2];
        a_odd[i] = a[i * 2 + 1];
    }

    // Recursive FFT calls
    fft_recursive(a_even, n / 2);
    fft_recursive(a_odd, n / 2);

    // Combine the results
    for (int i = 0; i < n / 2; i++) {
        complex double t = cexp(-2.0 * I * PI * i / n) * a_odd[i];
        a[i] = a_even[i] + t;
        a[i + n / 2] = a_even[i] - t;
    }
}

int main() {
    // Example usage of the FFT
    int n = 8;
    complex double a[] = {1, 1, 1, 1, 0, 0, 0, 0};

    fft_recursive(a, n);

    printf("FFT result:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %+.2f%+.2fi\n", i, creal(a[i]), cimag(a[i]));
    }

    return 0;
}
