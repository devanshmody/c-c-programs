/*----------------ASSEMBLY PROGRAM TO IMPLEMENT GENERAL DIFFERENCE EQUATION------------------*/
/*  This program implements a general difference equation involving an input sequence x(n)
    and feedback from the output equation y(n).
      Input :Input sequence data stored in file INPUT.DAT,coefficients of array x(n) stored
             in file ACOEFFS.DAT and coefficients of array y(n) stored in file BCOEFFS.DAT
      Output:Output sequence in the form of array y(n).
------------------------------------------------------------------------------------------*/ 
.MODULE               diffeqn;              { Name of the program }

.CONST                samples = 5;          { Constant defining the number of summation terms
                                              in the difference equation} 
.CONST                inputsamples = 5;     { Constant defining the size of the input array }
.VAR/DM/CIRC/ABS =    0x0000  x[samples];   { Array used as x(n) in the difference equation }
.VAR/DM/CIRC/ABS =    0x0010  y[samples];   { Array used as y(n) in the difference equation }
.VAR/DM/CIRC/ABS =    0x0020  a[samples];   { Array containing coefficients of x(n) }
.VAR/DM/CIRC/ABS =    0x0030  b[samples];   { Array containing coefficients of y(n) }
.VAR/DM/ABS      =    0X0040  input[inputsamples];        { Array for input samples }

.INIT            a:<ACOEFFS.DAT>;           { File containing the a(n) coefficients }
.INIT            b:<BCOEFFS.DAT>;           { File containing the b(n) coefficients }
.INIT        input:<INPUT.DAT>;             { File containing the input samples }
 
JUMP start; NOP; NOP; NOP;   { These instructions are stored at the interrupt vector locations
RTI; NOP; NOP; NOP;           and contain instructions which are executed when an interrupt
RTI; NOP; NOP; NOP;           occurs.The various interrupts are the hardware reset,SPORT1 
RTI; NOP; NOP; NOP;           receive and transfer interrupts,SPORT0 receive and transfer    
RTI; NOP; NOP; NOP;           interrupts and the timer interrupt.Since in this program we are
RTI; NOP; NOP; NOP;           only using the Hardware reset interrupt we write a
RTI; NOP; NOP; NOP;          'JUMP' instruction at this locations so that the program jumps to 
				the corresponding vector locations. }
 	
start:  IMASK = 0;              { Mask all interrupts }
        ICNTL = 0;              { Make all interrupts level sensitive and disable interrupt 
                                  nesting } 
  
        I0 = ^x;                { Define base address of array x(n) }
        L0 = %x;                { Define length of array x(n) }
        M0 = 1;                 { Modify register M0 initialised to 1 }
        M1 = 0;                 { Modify register M1 initialised to 0 }
        I1 = ^y;                { Define base address of array y(n) }
        L1 = %y;                { Define length of array y(n) }
        I2 = ^a;                { Define base address of array a(n) }
        L2 = %a;                { Define length of array a(n) }
        I3 = ^b;                { Define base address of array b(n) }
        L3 = %b;                { Define length of array b(n) }
        I4 = ^input;            { Define base address of input array }
        L4 = 0;                 { Define length of input array as 0 as it is linear }
        M4 = 1;                 { Modify register M4 initialised with 1 }
       
        CNTR = samples;         { Loop used to clear the x(n) and y(n) array } 
        DO clrbuf UNTIL CE;
        DM( I0, M0 ) = 0;
clrbuf: DM( I1, M0 ) = 0;

        ENA M_MODE;             { Enable 1.15 format arithmetic }
        AY0 = DM(I4,M4);        { Read first sample from input array }
        DM(I0,M1) = AY0;        { Store this sample in first position of x(n) array }
        MODIFY(I0,M0);          { Point I0 register to the next location in the x(n) array
                                 to place the next input sample }
        CNTR = inputsamples;  
        DO outerloop UNTIL CE;  { Outer loop to be executed for the length of the input array }
        MR = 0;                 { Clear MR register before computation of each value of y(n) }
        CNTR = samples;
        DO innerloop UNTIL CE;  { Inner loop to be executed for the length of the x(n) or y(n) array }
         MX0 = DM(I0,M0);       { Take sample from array x(n) }
         MY0 = DM(I2,M0);       { Take corresponding coefficient from array a(n) }
         MR = MR + MX0 * MY0 (SS);   { Multiply sample with coefficient and accumulate it with
                                       previous value of x(n) and a(n) product }
         MX0 = DM(I1,M0);       { Take sample from array y(n) }
         MY0 = DM(I3,M0);       { Take corresponding coefficient from array b(n) }
innerloop:
         MR = MR + MX0 * MY0 (SS);   { Multiply sample with coefficient and accumulate it with
                                       previous value of y(n) and b(n) product and also with sum 
					of products of array x(n) and a(n) }
         AY0 = DM(I4,M4);       { Read next sample from input array }
         DM(I0,M0) = AY0;       { Store this sample in x(n) array }
outerloop:
         DM(I1,M0) = MR0;       { Store the final value of y(n) in array y(n) which is then used 
					for calculation for future values of y(n) }
 
.ENDMOD;                        { End of program }
        



