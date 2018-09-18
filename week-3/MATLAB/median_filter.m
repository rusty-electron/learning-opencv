%load image using imread
img = rgb2gray(imread('moon.jpg'));

figure(1);
imshow(img);

%apply salt and pepper noise to image using imnoise
noisy_img = imnoise(img,'salt & pepper',0.02);
figure(2);
imshow(noisy_img);

%apply median filter to filter out the noise
median_img = medfilt2(noisy_img);
figure(3);
imshow(median_img);

%Optional: Check output incase of gaussian filter
hsize = 31;
sigma = 1;
h=fspecial('gaussian',hsize,sigma);
gauss_img = imfilter(noisy_img,h);
figure(4);
imshow(gauss_img);

