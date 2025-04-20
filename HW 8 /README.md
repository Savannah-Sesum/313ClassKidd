## Savannah Sesum (UMBC/313/ 7:44PM 4-16-25)
### Purpose of Software -------- 
To mimic the formula of "D = A + (3 * B) x C^T". <br>
It will produce 5 matrices in total, showing each 3 matrices + the tranpose of C + the final evaluation. <br>
The user will have to implement HW 8 / their own dimensions and values for the 3 matrices A, B and C. <br>
The program will then automatically evaluate into the final matrix using the same formula.

### Files --------
**README.md -** The file that explains this submission for HW 8 <br>
**matrix.hpp -** The header file for the testMatrix.cpp program <br>
**matrix.h -** The header file for the testMatrix.c program <br>
**testMatrix.cpp -** The c++ file that'll run with matrix.hpp, performing the printing and completion of HW 8 <br>
**testMatrix.c -** The c file that'll run with matrix.h, performing the printing and completion of HW 8 in C99 standards <br>

### Build Instructions --------
After downloading all files and making sure in the HW8 directory, do this for the c files to compile: <br>
gcc -std=c99 -Wall testMatrix.c -o testMatrixC

do this for the c++ files to compile: <br>
g++ -Wall testMatrix.cpp -o testMatrixCPP

To run the c after compiling: <br>
./testMatrixC

To run the c++ after compiling: <br>
./testMatrixCPP

### Testing Methodology --------
I first did everything on paper, and then did things step by step. For example, I started with
scalar multiplication, and did 3*B and eventually B*3 because i found it satisfying to have both hand operations. <br>
I manually set and got values through my functions, and was basically cout/printf everything so that 
I knew there would be no errors.  <br>
Since Matrix addition and multiplication has some strict rules for dimensions, I also put basic checks for those
required dimensions to that if you were to test and ex. do 3x3 + 3x4, it would fail and give you a message explaining so.
The same would happen to multiplication if you weren't to do a mxn * nxp
### Additional Information --------
When you ./ the files, you're going to be prompted with how many rows and cols you want.
As stated in the program's description, you get to customize your matrix. 
It'll start with matrix A, B and then C. <br>
So, when it says "How many Rows and Cols for matrix A? ", you can type "2 3" and it'll make you
a 2x3 matrix. Then, upon completion, you'll be asked "What do you want at Row 1 and Col 1?" and you insert
a digit of your liking. It'll then continue and say "What do you want at Row 1 and Col 2", so on and so on
until your entire matrix is filled! <br>

So yes, have the mildest bits of fun if you can with this!


