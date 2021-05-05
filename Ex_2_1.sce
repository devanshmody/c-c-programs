//Example 2.1

clc;clear;close;
A=1;T=2;
w0=2*%pi/T;

//Calculation of trignometric fourier series co-efficients
a0=A/T*(integrate('-1','t',-T/2,-T/4)+integrate('+1','t',-T/4,T/4)+integrate('-1','t',T/4,T/2));
for n=1:10;
a(1,n)=2*A/T*(integrate('-cos(n*w0*t)','t',-T/2,-T/4)+integrate('+cos(n*w0*t)','t',-T/4,T/4)+integrate('-cos(n*w0*t)','t',T/4,T/2));
b(1,n)=2*A/T*(integrate('-sin(n*w0*t)','t',-T/2,-T/4)+integrate('+sin(n*w0*t)','t',-T/4,T/4)+integrate('-sin(n*w0*t)','t',T/4,T/2));
end

//Displaying fourier coefficients
disp(T,'fundamental period T= ',A,'Assumption: Amplitude A= ');
disp('Tignometric fourier series co-efficients:');
disp(a0,'a0= ');disp(a,'an= ');disp(b,'bn= ');

x=[-A*ones(1,25) A*ones(1,50) -A*ones(1,25)]    //Function for ploting purpose
t=-T/2:0.01*T:T/2-0.01;
subplot(311);plot(t,x);
title('x(t)');xlabel('time t');
subplot(312);plot2d3(a);
title('Coefficients an');xlabel('n');
subplot(313);plot2d3(b);
title('Coefficients bn');xlabel('n');