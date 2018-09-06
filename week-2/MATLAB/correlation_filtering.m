img = imread('pepperg.png');

hsize = 31;
sigma = 5;

h=fspecial('gaussian',hsize,sigma);

figure(1);
surf(h);

figure(2);
imagesc(h);

outimg = imfilter(img,h);

figure(3);
imshow(outimg);