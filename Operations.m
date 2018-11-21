a = 5; %This intro part is for simple scalars
b = 3;
c = a+b;    %Addition
d = a-b;    %Subtraction
e = a*b;    %Multiplication
f = a/b;    %Division NOTE that \ is also division but it is from right to left
g = a^b;    %Power

disp('Simple scalar results')
disp(c)%Should be 8
disp(d)%Should be 2
disp(e)%Should be 15
disp(f)%Should be Matlab prints out 4 digits after decimal
disp(g)%Should be 125

%Matlab's operations are different when you get into arrays/matrices/vectors
%Scalar with an array/matrix vector

disp('Scalar with matrix')
a = 5;
A = [1 2 3]; %Column vector (horizontal)
disp(a+A)
disp(a-A) %Note that the order matters, this example takes values of A and does a-A
disp(A-a)
disp(A*a)
disp(A/a) %This takes values in A and goes A/a

disp('Matrix with a matrix')
A = [1 2 3]; %Column vector (horizontal)
B = [1; 2; 3]; %Row vector (vertical)
C = A+B; %Takes the value in A and adds them to each value in B
D = A-B;

disp(C) %This is solely element wise
disp(D)


%Multiplication and division vary from element wise and vector wise
disp('Matrix vs Element multiplication')
E = A*B; %Does the matrix multiplication which should be 14
F = A.*B; %Multiplies element wise creates an 3x3 matrix (.) special character

disp(E) %Will do the matrix multiplication 
disp(F) %Adding the period before the operation makes it element wise

%Matrix division has been left up to the reader to figure out
%Only special note is that /divides left to right
%While \ divides right to left

%Transpose
disp('Transpose')
Z = D';
disp(D)
disp(Z) %Flip the elements of an array along the diagonal from top left to 