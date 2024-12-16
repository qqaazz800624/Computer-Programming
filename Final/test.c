#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for company data
typedef struct {
    char code[10];
    char name[50];
    double revenue;
    double cost;
    double gross_profit;
    double avg_price;
    double eps; // Earnings per share
    double gross_margin; // 毛利率
    double pe_ratio; // 本益比
} Company;

// Function to remove commas from a string and convert it to a double
double parse_number_with_commas(const char *str) {
    char buffer[50];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ',') {
            buffer[j++] = str[i];
        }
    }
    buffer[j] = '\0';
    return atof(buffer);
}

// Function to calculate gross margin and P/E ratio
void calculate_metrics(Company *company) {
    if (company->revenue > 0) {
        company->gross_margin = (company->gross_profit / company->revenue) * 100.0;
    } else {
        company->gross_margin = 0.0;
    }
    if (company->eps > 0) {
        company->pe_ratio = company->avg_price / company->eps;
    } else {
        company->pe_ratio = 0.0;
    }
    // Ensure that P/E ratio cannot be negative
    if (company->pe_ratio < 0) {
        company->pe_ratio = 0.0;
    }
}

// Comparison function for sorting
int compare_companies(const void *a, const void *b) {
    const Company *compA = (const Company *)a;
    const Company *compB = (const Company *)b;

    // Sort by gross margin (descending)
    if (compB->gross_margin > compA->gross_margin) return 1;
    if (compB->gross_margin < compA->gross_margin) return -1;

    // If gross margin is the same, sort by P/E ratio (descending)
    if (compB->pe_ratio > compA->pe_ratio) return 1;
    if (compB->pe_ratio < compA->pe_ratio) return -1;

    return 0; // If both metrics are equal
}

int main() {
    int n = 0, capacity = 10;
    Company *companies = (Company *)malloc(capacity * sizeof(Company));
    if (companies == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Read input line by line
    char line[256];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        // Remove newline character from the input line
        line[strcspn(line, "\n")] = '\0';

        // Check for end of input
        if (strcmp(line, "") == 0) {
            break;
        }

        // Resize the companies array if needed
        if (n >= capacity) {
            capacity *= 2;
            companies = (Company *)realloc(companies, capacity * sizeof(Company));
            if (companies == NULL) {
                fprintf(stderr, "Memory reallocation failed.\n");
                return 1;
            }
        }

        // Parse the line
        Company *current = &companies[n];
        char revenue[20], cost[20], gross_profit[20];
        sscanf(line, "%s %s %[^ ] %[^ ] %[^ ] %lf %lf",
               current->code,
               current->name,
               revenue,
               cost,
               gross_profit,
               &current->avg_price,
               &current->eps);

        // Convert revenue, cost, and gross profit to doubles
        current->revenue = parse_number_with_commas(revenue);
        current->cost = parse_number_with_commas(cost);
        current->gross_profit = parse_number_with_commas(gross_profit);

        // Calculate gross margin and P/E ratio
        calculate_metrics(current);
        n++;
    }

    // Sort the companies
    qsort(companies, n, sizeof(Company), compare_companies);

    // Print the results
    printf("公司代碼\t公司名稱\t毛利率\t本益比\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%s\t%.2f\t%.2f\n",
               companies[i].code,
               companies[i].name,
               companies[i].gross_margin,
               companies[i].pe_ratio);
    }

    // Free dynamically allocated memory
    free(companies);

    return 0;
}