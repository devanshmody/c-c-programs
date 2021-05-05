x=input("Enter required no of signals");
for i=1:x
        X(i)=input("Enter the values of x(n) :");
    end;
P(1)=X(1)+X(3);
P(2)=X(1)-X(3);
P(3)=X(2)+X(4);
P(4)=X(2)-X(4);
disp(P);
P(4)=imult(P(4));

B(1)P(1)+P(3);
B(2)=P(2)-P(4);
B(3)=P(1)-P(3);
B(4)=P(2)+P(4);
disp(B);
