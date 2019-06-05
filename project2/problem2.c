
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Author: Nikhil Gosike
 *
 * This is a program that takes in an input file containing the digits
 * of pi and compresses them to half the size of the input file and outputs
 * a file of characters. It also takes the compressed file and outputs the original
 * uncompressed file.
 */

//These are declarations for two methods, which compress and extract the digits of pi
void compress(int c1, int c2, FILE * out_file);
void extract(char c1, FILE * out_file);

int main ( int argc, char ** argv ) { 
    
    //checks for the 4 required command line arguments 
    // If they are not there, exit the program
    if (argc < 4){
        printf("ERROR: this program needs three command line arguments\n");
        printf("\tUsage: %s e|d input_file_path output_file_path\n\n", argv[0] ); 
        exit(1); 
    }

    // takes in the first argument from command line
    char n = (char)(argv[1][0]);

    //if the first argument is not 'c' or 'd', print error and exit
    if(n != 'c' || n != 'e'){

        printf("ERROR: First argument must be 'c' or 'd' for compression or extraction.\n");
        exit(1);
    }

    //open the file for reading
    FILE * in_file = fopen (argv[2], "r" ); 
    
    //open the file for writing 
    FILE * out_file = fopen (argv[3], "w" );
    
    //c1 stores each character one at a time, c2 is the next character (helps with compression)
    int c1 = 0;
    int c2 = 0;

    //tracks whether there is a break in the file before the end of the file
    int end_in_newline = 0;

    //read digits one by one and write them to the output file
    while ( EOF != (c1 = fgetc(in_file))) {
        //if newline is found before the end of file, it is not a valid input file
        if (end_in_newline){ 
            printf("ERROR: invalid character detected: only one newline "
                    "allowed at the end of a file\n");
            exit(1);
        }

        //if newline found, the next char should be end of file (EOF)
        if (c1 == '\n') {
            end_in_newline = 1;
            continue;
        } 

        //if doing compression and the character is no numeric, exit the system for invalid file
        if ((c1 <'0' || c1 >'9') && n == 'c') {
            printf("ERROR: invalid character detected c1: %c \n\n", c1);
            exit(1);
        }

        //if c, start compression of two digits
        if(n == 'c'){

            // get next digit
            c2 = fgetc(in_file);

            //for odd number of digits, track for end of the file
            if(c2 < 48 || c2 > 57)
                // call compress, except with 63 as second argument
                compress(c1, 63,out_file);
            else
                // otherwise call compress on both characters
                compress(c1, c2, out_file);
        }

        //if e, call extract to decompress one digit at a time
        if(n == 'e'){

            extract(c1, out_file);
        }


    } 
    
    //add new line in ouput to indicate end of file
    if (end_in_newline){ 
        fputc('\n',out_file);
    }
    
    //close both files 
    fclose ( in_file); 
    fclose ( out_file); 
    
    return 0;
}

/*
* helper method to compress two digits at a time
*/
void compress(int c1, int c2, FILE * out_file){

    unsigned int other = 0;

    //shifts first character by four bits and then combines it with second character
    other = ((c1 - 48) << 4) | (c2 - 48);
    //puts new compressed character into output file
    fputc(other, out_file);
}

/*
* Helper method to extract two digits, one character at a time
*/
void extract(char c, FILE * out_file){

    //each variable gets the two digits stored in each 4-bit sequence
    unsigned int n = (c>>4) & 15;
    unsigned int n1 = c & 0b1111;

    //puts first digit into output file
    fputc(n + 48, out_file);

    //puts second digit into file
    if(n1 > 9) return;
    fputc(n1 + 48, out_file);

}

