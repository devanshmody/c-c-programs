//file name : fir.cpp
/*----------------------- FIR filter design using windows ---------------*/
//
//      This program computes the coefficients of the lowpass or
//      highpass FIR filter with given discrete time cutoff frequency,
//      given length and given window.
//
//          Inputs :  1. Number of coefficients of the filter, i.e. M
//		      2. Cutoff frequency of digital filter, i.e. wc
//                    3. Whether highpass or lowpass.
//                    4. choice of the window.
//
//	   Outputs :     Coefficients of the corresponding filter.
//
//     Assumptions :     hd(n) is obtained from the desired frequency
//                       response (refer explanation).
//
//---------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
     float wc,tou,M,hd[50],h[50],wn,pi,n;
     int choice,p;
     char HPF;

     clrscr();
     printf("\t\tFIR filter design using windows\n\n");
     printf("Enter the length (number of coefficients)"
					       " of the filter  M = ");
     scanf("%f",&M);                         // length(M) of the filter
     p = (int)M;
     printf("\nEnter the discrete time cutoff frequency wc = ");
     scanf("%f",&wc);         // cutoff frequency of the filter i.e. wc

     printf("\nif you want highpass filter, enter HPF = y, otherwise "
		   "perss any key\ndefault is lowpass filter\nHPF = ");
     HPF = getch(); printf("%c",HPF);           // enter for HPF or LPF
     tou = (M-1)/2;                                   // delay in hd(n)
     pi = 22.0/7.0;                                      // value of pi

//   Next part of the program calculates hd(n)

     for(n = 0; n <= M-1; n++)    // this loop calculates hd(n) for LPF
     {                            //                       (by default)
       hd[n] = (sin(wc*(n-tou)))/(pi*(n-tou));         // hd(n) for LPF
       if((n==tou)&&((p/2)*2 != p)) hd[n] = wc/pi;  // hd(n) at n = tou
     }
     if(HPF =='y')      // this loop recalculates hd(n) for HPF if user
     {                  //                          wants to design HPF
       for(n = 0; n <= M-1; n++)
       {                                               // hd(n) for HPF
	 hd[n] = (sin(pi*(n-tou)) - sin(wc*(n-tou)))/(pi*(n-tou));
	 if((n==tou)&&((p/2)*2 != p)) hd[n] = 1-(wc/pi);
       }                                            // hd(n) at n = tou
     }

//   Next part of the program performs windowing depending upon
//                                                     choice of window

     printf("\n\nEnter the window you want to use");// choice of window
     printf("\nrectangular window (Enter 1)");            //rectangular
     printf("\ntriangular(bartlett) window (Enter 2)");    //triangular
     printf("\nhamming window (Enter 3)");                    //hamming
     printf("\nhanning window (Enter 4)\nchoice = ");         //hanning
     scanf("%d",&choice);                               // enter choice

     switch(choice)
     {             // h(n) = hd(n) * w(n) depending upon type of window
       case 1 : for(n = 0; n <= M-1; n++)                // rectangular
		{
		  wn = 1;                   //wn for rectangular window
		  h[n] = hd[n] * wn;             // windowing operation
		} break;
       case 2 : for(n = 0; n <= M-1; n++)                 // triangular
		{
		  wn = 1 - (2*abs(n-tou)/(M-1));   // calculation of wn
		  h[n] = hd[n] * wn;             // windowing operation
		} break;
       case 3 : for(n = 0; n <= M-1; n++)                    // hamming
		{
		  wn = 0.54 - 0.46*cos((2*pi*n)/(M-1));           // wn
		  h[n] = hd[n] * wn;             // windowing operation
		} break;
       case 4 : for(n = 0; n <= M-1; n++)                    // hanning
		{
		  wn = (1-cos((2*pi*n)/(M-1)))/2;  // calculation of wn
		  h[n] = hd[n] * wn;             // windowing operation
		} break;
     }

//   Next part of the program displays coefficients on the screen
     if(HPF == 'y')  printf("\ncoefficients of highpass FIR filter"
						 " are as follows...");
     else  printf("\ncoefficients of lowpass FIR filter"
						 " are as follows...");
     for(n = 0; n <= M-1; n++)
     {
       printf("\nh%1.0f = %f",n,h[n]);
     }
}
//---------------------------End of program---------------------------------

