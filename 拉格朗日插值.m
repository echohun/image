function lagrint(x,y,xi);
dxi = xi-x;
n=length(x);
L=zeros(size(y));
L(1) =  prod(dxi(2:n))/prod(x(1)-x(2:n));
L(n) = prod(dxi(1:n-1))/prod(x(n)-x(1:n-1));
for j=2:n-1
    num = prod(dxi(1:j-1))*prod(dxi(j+1:n));
    den = prod(x(j)-x(1:j-1))*prod(x(j)-x(j+1:n));
    L(j) = num/den;
end
yi = sum(y.*L);
fprintf('x=%f,y=%f',xi,yi);
