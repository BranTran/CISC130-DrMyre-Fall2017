%Number 1 in Review
%Obtain the 15-26 row and 10-21 column of 100x100 matrix
A = 1:100;
B = A';
C = A+B;%Elementwise summing to get 100x100
D = C(15:26,10:21);%This calls (rows,columns) : increments by 1 naturally and is inclusive on limits