//------------------- Goertzel Algorithm ------------------------------

//	This program calculates DFT of the sequence using Goertzel
//			Algorithm at given value of k

//                 Inputs :  1. Number of samples in x(n)
//			     2.	Samples of x(n) in the form
//				x[0],x[1],x[2],.....x[N-1]
//			     3. Value of k
//
//		  Outputs :     DFT of x(n) at k
//
//	      Assumptions :     Length of sequence and N should be same.
//------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
	float hReal[20],hImag[20],x[20],y[20],sum;
	float N,M,n,k,xkReal,xkImag;
	clrscr();
	printf("                    Goertzel Algorithm\n\n");

	printf("Enter the number of samples in x(n) = ");
	scanf("%f",&N);                      // number of samples in x(n)
	printf("Enter the sequence x(n)\n");
	for(n = 0; n < N; n++)
	{
		printf("x[%1.0f] = ",n);     //Entering the sequence x(n)
		scanf("%f",&x[n]);
	}

	printf("Enter the value of k = ");
	scanf("%f",&k);    	// Value of k at which DFT is calculated

	for(n = 0; n < N; n++)
	{//This loop calculates real and imaginary parts for convolution
		hReal[n] = cos(2*3.142*k*n/N);
		hImag[n] = sin(2*3.142*k*n/N);
	}
	M = N;

//----- Convolution with real part to get real part of X(k)------------

	for(n = 0; n < (N+M-1); n++)   // convolution calculation
	{	sum = 0.0;
		for(k = 0; k < M; k++)        //   summation loop
		{
			if(n < k || (n-k)>= N) continue;
			sum += x[k] * hReal[n-k];
		}
		y[n] = sum;
	}
	xkReal = y[N];		// real part of X(k)

//-- Convolution with imaginary part to get imaginary part of X(k)-----

	for(n = 0; n < (N+M-1); n++)   // convolution calculation
	{	sum = 0.0;
		for(k = 0; k < M; k++)        //   summation loop
		{
			if(n < k || (n-k)>= N) continue;
			sum += x[k] * hImag[n-k];
		}
		y[n] = sum;
	}
	xkImag = y[N];		//imaginary part of X(k)

	printf("\nThe DFT is X(k) = (%1.2f)+j(%1.2f)",xkReal, xkImag);
				// display the DFT at k
}
//----------------------------End of program------------------------------