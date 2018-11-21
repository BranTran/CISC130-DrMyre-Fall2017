img = imread('ust_arches.jpg');

imshow(img);

%[Lightness, Average, Luminosity] = mygrayscale(img);
%figure, imshow(Lightness);
%figure, imshow(Average);
%figure, imshow(Luminosity);

cimg = img;
[row, column, channel] = size(img);
%(row column channel)
cimg(:,1:(column/3),3) = img(:,1:(column/3),2);
cimg(:,1:(column/3),2) = zeros(row,(column/3));
cimg(:,(2*column)/3:end,3) = cimg(:,(2*column)/3:end,1);
figure, imshow(cimg);