%Number 6 in Review
%Calculate the Root Mean Square Error
function [e] = RMSE(a,b)
%The square root of the mean of the squared error
e = sqrt(mean((a-b).^2));
end