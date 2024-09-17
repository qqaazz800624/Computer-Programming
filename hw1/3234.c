#include <stdio.h>
#include <math.h>

int main()
{
    int A, B;
    double C;
    int sum;
    double sum2;
    double avg, sigma;

    // Input A, B, and C
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%lf", &C);

    // Cast C to int for digit extraction
    int intPartC = (int)C;

    // Loop through the four digits from the units place
    for (int i = 1000; i >= 1; i /= 10) {
        int A_digit = (A / i) % 10;
        int B_digit = (B / i) % 10;
        int C_digit = (intPartC / i) % 10;

        // Calculate sum, average, and sigma (standard deviation)
        sum = A_digit + B_digit + C_digit;
        avg = sum / 3.0;
        sigma = sqrt((pow(A_digit - avg, 2) + pow(B_digit - avg, 2) + pow(C_digit - avg, 2)) / 3.0);

        // Output the results for the current digit place
        printf("%d %.2f %.2f\n", sum, avg, sigma);
    }

    // Compute final sum, average, and sigma using full values of A, B, and C
    sum2 = A + B + C;
    avg = sum2 / 3.0;
    sigma = sqrt((pow(A - avg, 2) + pow(B - avg, 2) + pow(C - avg, 2)) / 3.0);

    // Output the results for the full values
    printf("%.2f %.2f %.2f\n", sum2, avg, sigma);

    return 0;
}
