function my_images(img1,img2,img3,img4,img5,img6,img7)
%Read in all seven images and display them

%Colorizing one of the images WAFFLES
img = colorize_im(img1);
imshow(img);

%Make separate figures for the rest\
%Scramble the last image
newimg2 = im_scramble(img2);
figure, imshow(newimg2)
figure, imshow(img3);
figure, imshow(img4);
figure, imshow(img5);
figure, imshow(img6);
figure, imshow(img7);
end