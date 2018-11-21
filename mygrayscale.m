function [ A1, A2, A3 ] = mygrayscale( img )
% Summary of this function goes here
%   Detailed explanation goes here
% lightness = (max(R,G,B) + min(R,G,B))/2
% avg = (R+G+B)/3
% luminosity = 0.21R+0.72G+0.07B

Red = img(1:end,1:end,1); %Creates three 2D arrays
Green = img(1:end,1:end,2);
Blue = img(1:end,1:end,3);

%% Lightness among the three slices, (find max between all color in pixel, then min, flush out)
Sub_max = max(Red,Green); %Place the maximun values between the two arrays into Sub_max
Max = max(Sub_max,Blue); %The maximum value for all RGB

Sub_min = min(Red,Green); %Place the minimun values between the two arrays into Sub_min
Min = min(Sub_min,Blue); %The minimum value for all RGB

A1 = (Max + Min)/2;
%% Avg Average of the three values
A2 = (Red+Green+Blue)/3; %Takes the average of the image based on the color channel dimension (Average between RGB)

%% luminosity Weighted sum to get value
A3 = (.21)*Red+(.72)*Green+(.07)*Blue;

end

