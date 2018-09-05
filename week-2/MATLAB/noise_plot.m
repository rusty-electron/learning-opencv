img = imread('peppers.png');
img = rgb2gray(img);
img = im2double(img);

sigma = 0.05;
noise = randn(size(img)).*sigma;
noisy = noise + img;

figure(1);
line=img(256,:);
plot(1:512,line);

figure(2);
line=noisy(256,:);
plot(1:512,line);



