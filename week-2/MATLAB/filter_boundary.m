img = imread('peppers.png');
img = im2double(img); %converting to data range of [0,1]

figure('Name','Original Image');
imshow(img);

%generating noise
sigma = 0.05;
noise = randn(size(img)).*sigma;

%adding noise to original image
noisy = noise + img;

figure('Name','Noisy Image');
imshow(noisy);

%generate filter
hsize = 31;
sigma = 2;
h=fspecial('gaussian',hsize,sigma);

%apply filter on noisy image
%outimg = imfilter(noisy,h,0);
% outimg = imfilter(noisy,h,'circular');
%outimg = imfilter(noisy,h,'replicate');
 outimg = imfilter(noisy,h,'symmetric');


figure('Name','Filtered Image');
imshow(outimg);
