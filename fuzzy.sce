f=input("Enter the real values:")
fa=input("Enter the first fuzzy matrix:")
fb=input("Enter the second fuzzy matrix:")
disp("The real values, first & second fuzzy values provided by you are:")
disp(f)
disp(fa)
disp(fb)
subplot(431)
plot2d(f,fa,style=[color("red")]);
xtitle('fuzzy Logic','Real Values','Fuzzy Values');
subplot(432)
plot2d(f,fb,style=[color("blue")]);
xtitle('fuzzy Logic','Real Values','Fuzzy Values');
m=max(fa,fb);
subplot(433)
plot2d(f,m,style=[color("green")]);
xtitle('Union','Real Values','Fuzzy Values');
n=min(fa,fb);
subplot(434)
plot2d(f,n,style=[color("red")]);
xtitle('Intersection','Real Values','Fuzzy Values');
fan=(1-fa);
subplot(435)
plot2d(f,fan,style=[color("green")]);
xtitle('Negation','Real Values','Fuzzy Values');
fbn=(1-fb);
subplot(436)
plot2d(f,fbn,style=[color("blue")]);
xtitle('Negation','Real Values','Fuzzy Values');
i=(fa.*fb);
subplot(437)
plot2d(f,i,style=[color("red")]);
xtitle('Dot Product','Real Values','Fuzzy Values');
j=(fa+fb);
as=(j-i);
subplot(438)
plot2d(f,as,style=[color("green")]);
xtitle('Algebraic Sum','Real Values','Fuzzy Values');
bs=min(1,as);
subplot(439)
plot2d(f,bs,style=[color("red")]);
xtitle('Bounded Sum','Real Values','Fuzzy Values');
bd=max(0,as);
subplot(4,3,10)
plot2d(f,bd,style=[color("blue")]);
xtitle('Bounded Difference','Real Values','Fuzzy Values');
