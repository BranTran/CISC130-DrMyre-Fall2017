function [c2img] = im_scramble(img)

[row, column,~] = size(img);

row_rem = mod(row,3);
col_rem = mod(column,3);

base_row = (row - row_rem)/3;
base_col = (column - col_rem)/3;
cimg = img;


cimg(1:end,1:(base_col+col_rem),:) = img(1:end,(2*base_col+1):end,:);%1,3
cimg(1:end,(base_col+1+col_rem):(2*base_col+col_rem),:) = img(1:end,(base_col+1):(2*base_col),:);%2,2
cimg(1:end,((2*base_col)+1+col_rem):end,:) = img(1:end,1:base_col,:);%3,1
c2img = cimg;

c2img(1:base_row+row_rem,1:end,:) = cimg((2*base_row+1):end,1:end,:);%1,3
c2img((base_row+1+row_rem):(2*base_row+row_rem),1:end,:) = cimg((base_row+1):(2*base_row),1:end,:);%2,2
c2img(((2*base_row)+1+row_rem):end,1:end,:) = cimg(1:base_row,1:end,:);%3,1

%Random fill board of 1 - 9
% A = randperm(9);
% B = [A(1:3);A(4:6);A(7:9)];
end

