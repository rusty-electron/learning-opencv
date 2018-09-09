img = imread('pepperg.png');
img = im2double(img); %converting to data range of [0,1]

figure(1);
imshow(img);

%generating noise
sigma = 0.05;
noise = randn(size(img)).*sigma;

%adding noise to original image
noisy = noise + img;

figure(2);
imshow(noisy);

%generate filter
hsize = 31;
sigma = 2;
h=fspecial('gaussian',hsize,sigma);

%apply filter on noisy image
outimg = imfilter(noisy,h);

figure(3);
imshow(outimg);