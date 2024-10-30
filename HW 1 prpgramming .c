#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 15 // Maximum number of iterations

// Function prototypes
double sisesta_arv(char []);  // Function to input a double value
void liida(double, double, double, double []); // Function to calculate x
void tulemus_ekraanile(double[], double[], int); // Function to display results

int main(void)
{
   // Constants for input values
   double A, B, H, C;   
   int i;               // Loop counter
   double x[MAX_ITERATIONS], y[MAX_ITERATIONS]; // Arrays for calculated values

   // Input Section
   A = sisesta_arv("A"); // Input for A
   B = sisesta_arv("B"); // Input for B
   H = sisesta_arv("H"); // Input for H
   C = sisesta_arv("C"); // Input for C
      
       liida(A, H, C, x,y);
 
 
   tulemus_ekraanile(x, y, i); // Display results using the output function

   return 0; // End of the program
} 

// Function to calculate x based on parameters A, H, C, and index i
double liida(double A, double H, double C, double x[], double y[])
{  int i;
	 for (i = 0; i < MAX_ITERATIONS; i++){
	if (x[i] >= B) break;
     x[i]= A + i * H + C * (i - 1) * H; 
     
     y[i] = sqrt(x[i] * x[i] + x[i] - 20 )/(x[i] * x[i] + x[i] - 10);
       
       // Check if y is NaN (Not a Number) or infinite
       if (isnan(y[i]) || isinf(y[i])) {
           y[i] = 0; // Set y to 0 to indicate invalid y
       } 
       // Check if y is not an integer
       else if (y[i] != floor(y[i])) {
           y[i] = -1; // Set y to -1 to indicate complex number// Calculate x
}  }   

// Function to input a double value from the user
double sisesta_arv(char w[])
{
   double lokA;  
   
   printf ("%s: ", w); // Prompt user for input
   scanf("%lf", &lokA); // Read input as a double
   
   return lokA; // Return the input value
}      

// Function to display the results of the calculations
void tulemus_ekraanile(double x[], double y[], int count)    
{  printf("x\t\ty\n");
   for (int i = 0; i < count; i++) {
       if (y[i] == 0) {
           printf("%f\t\tpuudub\n", x[i]); // Indicate no valid y value
       } else if (y[i] == -1) {
           printf("%f\t\tkompleksarvuline\n", x[i]); // Indicate complex number
       } else {
           printf("%f\t\t%f\n", x[i], y[i]); // Display x and y values
       }
   }
} 
