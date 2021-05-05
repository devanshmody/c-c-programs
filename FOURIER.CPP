//file name : fourier.cpp
/*- Fourier Transform of the sequence and computation of transfer function -*/
//
//      This program computes the fourier transform of the sequence x(n)
//      and plots its magnitude and phase transfer function
//      characteristics on the screen.
//
//                 Inputs :  1. Number of samples of x(n)
//			     2.	Values of samples of x(n)
//                           3. Frequency w at which fourier transform
//			        is to be evaluated
//
//		  Outputs :  1. X(w) at given value is displayed.
//                           2. Magnitude and Phase plots for 0 to pi
//                              values of w are displayed on screen.
//
//	      Assumptions :  1. This program is for written real
//                              values of sequence x(n)
//                           2. Magnitude and phase transfer function
//                              plots are computed for x(n) for 0 to pi
//                              values of w.
//------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main()
{
     float static x[100],w,XwReal,XwImag,pi,wStep;
     float static mag[640],phase[640],yMag,yPhase;
     int k,n,N,gd,gm;

     clrscr();
     printf("   \nFourier Transform and computation of "
				      "transfer function\n\n");
     printf("Enter the number samples in the sequence x(n)  ");
     scanf("%d",&N);                      // number of samples in x(n)
     printf("\nEnter the samples of sequence x(n)\n");
     for(n = 0; n < N; n++)
     {
       printf("x(%d) = ",n);        // enter values of samples of x(n)
       scanf("%f",&x[n]);
     }
     printf("\nEnter the frequency w at which fourier"
	     " transform is \nto be evaluated w(bteween 0 to pi) = ");
     scanf("%f",&w);                                     // value of w
     XwReal = XwImag = 0.0;
     for(n = 0; n < N; n++)  // computation of X(w) at particular
     {//                                                    value of w
       XwReal = XwReal + x[n] * cos(w*n);         // real part of X(w)
       XwImag = XwImag + x[n] * sin(w*n);    // imaginary part of X(w)
     }
     XwImag = XwImag*(-1.0);       // sign inversion of imaginary part
     printf("\nThe value of fourier transform is "
	    "\nX(w = %f) = %f + j(%f)",w,XwReal,XwImag);
     printf("\n\npress any key to see magnitude and phase"
	    "  transfer function plots");       getch();

//   next part of the program computes magnitude and phase of X(w)
//                                       at 640 points between 0 to pi
     w = 0.0;
     pi = 22.0/7.0;                                     // value of pi
     wStep = pi/640.0; // range of w = 0 to pi divided into small
//                            steps of pi/640 for displaying on screen.
     for(k = 0; k < 640; k++)
     {   // this loop computes magnitude and phase at 640 points
//                                        in the range of w = 0 to pi.
	XwReal = XwImag = 0.0;
	w = w + wStep;               // steps by which w is increased.
	for(n = 0; n < N; n++) // this loop computes real part of X(w)
	{//                          and imaginary part of X(w) at one
//                                        value of w out of 640 points
	   XwReal = XwReal + x[n] * cos(w*n);     // real part of X(w)
	   XwImag = XwImag + x[n] * sin(w*n); //imaginary part of X(w)
	}
	XwImag = XwImag*(-1.0); //inversion of imaginary value of X(w)

	mag[k] = sqrt(XwReal*XwReal + XwImag*XwImag);
		       //calculation of magnitude of transfer function
	phase[k] = atan2(XwImag,XwReal);
     }                     //calculation of phase of transfer function

//   Next part of program displays the magnitude & phase on the screen
//            which is calculated at 640 points by previous 'for' loop

     detectgraph(&gd,&gm);   // detect graphics mode & graphics driver
     initgraph(&gd,&gm,"");      // initialize screen in graphics mode
     setlinestyle(DOTTED_LINE,1,1);    // dotted line style for x-axis
     line(0,250,640,250);                 // x-axis line for magnitude
     line(0,350,640,350);                     // x-axis line for phase
     for(k = 0; k < 640; k++) // this loop puts 640 pixels of
     {//                             magnitude and phase on the screen
	yMag = 250 - mag[k]*200; //magnitude scaled for proper display
	putpixel(k,yMag,YELLOW);//put pixel of magnitude on the screen
	yPhase = 350 - phase[k]*50;                // scaling of phase
	putpixel(k,yPhase,GREEN);                // put pixel of phase
     }
     outtextxy(500,260,"Magnitude plot");        // label of magnitude
     outtextxy(500,450,"Phase plot");                // label of phase
     getch();                                  // wait for observation
     closegraph();
}
//---------------------------End of program---------------------------------
