img = rgb2gray(imread('moon.jpg'));

x = [1:512];
y = img(256,:);

figure(1);
plot(x,y);

noisy_img = imnoise(img,'salt & pepper',0.05);

y = noisy_img(256,:);

figure(2);
plot(x,y);