%Number 5 in Review
%Read in matrix.csv, obtain size, slice every other row.
A = csvread('matrix.csv',0,0);
%Obtain size as row and column
[row, column] = size(A);
%Initiate slicing of row then of column
B = A(1:2:row,:);%Every other meaning step size of two
C = B(:,1:2:column);