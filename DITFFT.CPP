//file name : ditfft.cpp
/*-------------------- Radix-2 DIT FFT algorithm ---------------------------*/
//
//      This program implements the radix-2 DIT FFT algorithm for
//      the complex valued sequence of length N
//
//                 Inputs :  1. Number of samples of x(n)
//			     2.	Values of samples of x(n)
//
//		  Outputs :     real and imaginary part of
//                              DFT X(k).
//
//	      Assumptions :     This program is for written for
//                              inplace computation. The data storage
//                              format is given in the discription.
//------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
# define SWAP(a,b) tempr = (a); (a) = (b); (b) = tempr;
void main()
{
     float data[200],real_k0,imag_k0,real_k1,imag_k1,tempr;
     float pi,cosTheta,sinTheta,t,Theta;
     unsigned long N,n,m,j,i,k,p;

     clrscr();
     printf("        Radix-2 DIT FFT algorithm\n\n");
//--------- Next part of the program accepts
//               complex valued sequence x(n) ------------------------
     printf("Enter the number of samples in the sequence x(n), N = ");
     scanf("%ld",&N);                      // number of samples in x(n)
     printf("\nEnter the samples of sequence x(n)"
	    "\nreal part  imaginary part\n");
     for(n = 1; n <= N; n++)
     {
       printf("x(%d) = ",n-1);       // enter values of samples of x(n)
       scanf("%f%f",&data[2*n-1],&data[2*n]);
     }

//--------- Next part is the bit reversal on x(n) ---------------------
     n = N << 1;
     j = 1;
     for(i = 1; i < n; i = i+2)
     {
       if(j > i)
       {
	  SWAP(data[j],data[i]);
	  SWAP(data[j+1],data[i+1]);
       }
       m = n >> 1;             //  |   various  counters  are  arranged
       while(m >= 2 && j > m)  //  |         such that x(n) is shuffled
       {                       //  |               in bit reversed form
	  j -= m;
	  m >>= 1;
       }
       j += m;
     }
//------------ bit reversal of x(n) completes -------------------------

     k = 1; m = 1; pi = 22.0/7.0,t = 0.0; //initialization of variables

//----------- next part is the DIT FFT computation --------------------

     while((N/(2*k)) >=1)
     {		 // this is the loop for number of stages of decimation
	p = pow(2,m);
	n = 1;
	Theta = ((2*pi)/(float)p)*t;// | these three statements compute
	cosTheta = cos(Theta);      // |           the phase factors in
	sinTheta = sin(Theta);      // |                  the butterfly

	for(i = 1; i <= 2*N;)
	{                  // this loop computes N/2 butterflies in one
	//                                          stage of decimation
	//   following four statements compute real and imaginary parts
	//                                                one butterfly
	   real_k0 = data[i]+cosTheta*data[i+p]+sinTheta*data[i+1+p];
	   imag_k0 = data[i+1]+cosTheta*data[i+1+p]-sinTheta*data[i+p];
	   real_k1 = data[i]-cosTheta*data[i+p]-sinTheta*data[i+1+p];
	   imag_k1 = data[i+1]-cosTheta*data[i+1+p]+sinTheta*data[i+p];

	       data[i] = real_k0;   //  | the  newly  computed real and
	     data[i+1] = imag_k0;   //  |        imaginary parts of the
	     data[i+p] = real_k1;   //  |       butterfly are stored in
	   data[i+p+1] = imag_k1;   //  |      place of prevoius values
				    //  |this is "in place computation"
	   if(n<k)
	   {                              // |
	      i = i + 2;  n++;            // |
	      t = t + 1;                  // |
	      Theta = ((2*pi)/(float)p)*t;// |        this if-else loop
	      cosTheta = cos(Theta);      // |              adjusts the
	      sinTheta = sin(Theta);      // |             counters and
	   } else                         // |            phase factors
	     {                            // |              as required
	       i = i + p+2;               // |             in one stage
	       n = 1; t = 0;              // |            of decimation
	       Theta = ((2*pi)/(float)p)*t;//|
	       cosTheta = cos(Theta);     // |
	       sinTheta = sin(Theta);     // |
	     }
	}
	k = k << 1;      // adjust counter for next stage of decimation
	m++;
     }
//----------- DIT FFT computation completes ---------------------------

//------- Next part displays computed DFT on the screen ---------------

     printf("\nThe DFT is as follows...\n");
     printf("\nreal part of X(k)       imagninar part of X(k)");
     for(n = 1; n <= N; n++)
     {
       printf("\n%f \t\t  %f",data[2*n-1],data[2*n]);
     }
}
//---------------------------End of program---------------------------------
