%Number 4 in Review
%read the image pollock, obtain a subimage that is the lower right quad

%Step one is to read in the image
img = imread('pollock.jpg');
imshow(img);
[row, col, ~] = size(img);

%Take into account a remainder before splitting image into 4
row_rem = mod(row,2);
col_rem = mod(col,2);

%We want the lower right quadrant, so we can do this with slicing;
%The slice we want is lower and right so from half way to end on row and
%column
sub_img = img(((row/2)+row_rem+1):end,((col/2)+col_rem+1):end,:);
figure;
imshow(sub_img);