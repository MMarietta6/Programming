#include <stdio.h>
#include <math.h>

// Constants
#define MAX_ITERATIONS 15 // Maximum number of iterations for the loop

// Function prototypes
double sisesta_arv(char []);  // Function to input a double value
double liida(double, double, double, int); // Function to calculate x based on parameters
void tulemus_ekraanile(double, double); // Function to display results

int main(void)
{
   // Variables for input values
   double A, B, H, C;   
   int i;               // Loop counter
   double x, y;        // Variables for calculated values
   
   // Input values for A, B, H, and C from the user
   A = sisesta_arv("A");
   B = sisesta_arv("B");
   H = sisesta_arv("H");
   C = sisesta_arv("C");
   
   // Print header for the output table
   printf("x\t\ty\n");
   
   // Loop to calculate values for x and y
   for (i = 0; i < MAX_ITERATIONS; i++) {
       // Calculate the value of x using the liida function
       x = liida(A, H, C, i);
       
       // Break the loop if x exceeds B
       if (x >= B) break; 
       
       // Calculate the value of y based on x
       y = x*x + x - 20 - sqrt(x*x + x - 10);
       
       // Check if y is NaN (Not a Number) or infinite
       if (isnan(y) || isinf(y)) {
           tulemus_ekraanile(x, 0); // Display result indicating no valid y value
       } 
       // Check if y is not an integer
       else if (y != floor(y)) {
           tulemus_ekraanile(x, -1); // Display result indicating complex number
       } 
       // If y is a valid integer
       else {
           tulemus_ekraanile(x, y); // Display x and y
       }
   }

   return 0; // End of the program
} 

// Function to calculate x based on parameters A, H, C, and index i
double liida(double A, double H, double C, int i)
{
     return A + i * H + C * (i - 1) * H; // Calculate x
}     

// Function to input a double value from the user
double sisesta_arv(char w[])
{
   double lokA;  
   
   printf ("%s: ", w); // Prompt user for input
   scanf("%lf", &lokA); // Read input as a double
   
   return lokA; // Return the input value
}      
 
// Function to display the results of the calculations
void tulemus_ekraanile(double argX, double argY)    
{
   if (argY == 0) {
       printf("%f\t\tpuudub\n", argX); // Indicate no valid y value
   } else if (argY == -1) {
       printf("%f\t\tkompleksarvuline\n", argX); // Indicate complex number
   } else {
       printf("%f\t\t%f\n", argX, argY); // Display x and y values
   }
} 
