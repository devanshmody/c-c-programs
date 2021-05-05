m=input("enter the value row for R matrix");
n=input("enter the value of column for R matrix");
for i=1:m
    for j=1:n
        a(i,j)=input("enter the value");
    end;
end;
disp(a);
p=input("enter the value row for S matrix");
q=input("enter the value of column for S matrix");
for i=1:p
    for j=1:q
        b(i,j)=input("enter the value");
    end;
end;
disp(b);
disp("max min composition");
for i=1:m
    for j=1:q
        for k=1:p
            c(k)=min(a(i,k),b(k,j));
        end;
        ros(i,j)=max(c);
    end;
end;
disp(ros);
