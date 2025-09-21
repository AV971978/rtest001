#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to swap two numbers for sorting
void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort array for median calculation
void sort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Calculate mean
double calculate_mean(double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Calculate median
double calculate_median(double arr[], int n) {
    double sorted[n];
    for (int i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }
    sort(sorted, n);
    if (n % 2 == 0) {
        return (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
    } else {
        return sorted[n / 2];
    }
}

// Calculate mode
double calculate_mode(double arr[], int n) {
    int max_count = 1, count = 1;
    double mode = arr[0];
    double sorted[n];
    for (int i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }
    sort(sorted, n);
    
    for (int i = 1; i < n; i++) {
        if (sorted[i] == sorted[i - 1]) {
            count++;
            if (count > max_count) {
                max_count = count;
                mode = sorted[i];
            }
        } else {
            count = 1;
        }
    }
    return mode;
}

// Calculate range
double calculate_range(double arr[], int n) {
    double min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    return max - min;
}

// Calculate standard deviation
double calculate_stddev(double arr[], int n, double mean) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(arr[i] - mean, 2);
    }
    return sqrt(sum / n);
}

// Calculate skewness
double calculate_skewness(double arr[], int n, double mean, double stddev) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow((arr[i] - mean) / stddev, 3);
    }
    return sum / n;
}

// Calculate kurtosis
double calculate_kurtosis(double arr[], int n, double mean, double stddev) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow((arr[i] - mean) / stddev, 4);
    }
    return sum / n - 3; // Excess kurtosis
}

int main() {
    // Dataset 1: User-defined dataset
    int n1;
    printf("\e[1;1H\e[2J");
    printf("\n Sample Size: ");
    printf(" ");
    scanf(" %d", &n1);
    
    double data1[n1];
    printf("\n Enter %d Data Points:", n1);
    for (int i = 0; i < n1; i++) {
        scanf(" %lf", &data1[i]);
    }
    printf("\e[1;1H\e[2J");    
    printf("\n\n Results: [Original Data] \n\n");
    double mean1 = calculate_mean(data1, n1);
    double median1 = calculate_median(data1, n1);
    double mode1 = calculate_mode(data1, n1);
    double range1 = calculate_range(data1, n1);
    double stddev1 = calculate_stddev(data1, n1, mean1);
    double skewness1 = calculate_skewness(data1, n1, mean1, stddev1);
    double kurtosis1 = calculate_kurtosis(data1, n1, mean1, stddev1);
for (int i = 0; i < n1; i++) 
printf(" %.2lf", data1[i]);    
    printf("\n\n Mean: %.2f", mean1);
    printf("\n Median: %.2f", median1);
    printf("\n Mode: %.2f", mode1);
    printf("\n Range: %.2f", range1);
    printf("\n S. D.: %.2f", stddev1);
    printf("\n Skewness: %.2f", skewness1);
    printf("\n Kurtosis: %.2f\n", kurtosis1);
    
    // Dataset 2: Manipulated to have mean = median = mode = range
/*    int n2;
    printf("\n Sample Size of 2nd Dataset: ");
    scanf(" %d", &n2);
    double r2;
    double data2[n2];
    printf("\n Enter %d data points:\n", n2);
    for (int i = 0; i < n2; i++) {
       printf(" ");
        scanf("%lf", &data2[i]);
        double min=data2[0];
    }
  */  
    // Manipulate data2 to make mean = median = mode = range
    double mean2 = calculate_mean(data1, n1);
    
    for (int i = 0; i < n1; i++) 
        data1[i] = mean1; // Set all values to the mean

         data1[0]=mean1-mean1/2;
         data1[n1-1]=mean1+mean1/2;

//    data2[n2-1] = 2*mean2;
    printf("\n\n Results: [Manupulated Data]:\n\n");

       for (int i = 0; i < n1; i++)      
         printf(" %.2lf", data1[i]);

//    data2[n2-1] = 2*mean2;
//    printf("\n\n Dataset 1: [Manupulated Data]:\n");
    double median2 = calculate_median(data1, n1);
    double mode2 = mean2; //calculate_mode(data2, n2);
    double range2 = mean2; //calculate_range(data2, n2);
    double stddev2 = calculate_stddev(data1, n1, mean1);
    double skewness2 = calculate_skewness(data1, n1, mean1, stddev1);
    double kurtosis2 = calculate_kurtosis(data1, n1, mean1, stddev1);
    
    printf("\n\n Mean: %.2f", mean2);
    printf("\n Median: %.2f", median2);
    printf("\n Mode: %.2f", mode2);
    printf("\n Range: %.2f", range2);
    printf("\n S. D.: %.2f", stddev2);
    printf("\n Skewness: %.2f", skewness2);
    printf("\n Kurtosis: %.2f\n", kurtosis2);
    
    return 0;
}
