%provide input image
sample = double(imread('diamond.jpg'))/255;

figure(1);
imshow(sample);

%apply sobel operator using 'imgradientxy'
[gx gy] = imgradientxy(sample, 'sobel');

[gmag gdir] = imgradient(gx, gy);

%normalize the output
xmag = (gx+4)/8;
ymag = (gy+4)/8;

%PD along x-axis
figure(2);
imshow(xmag);

%PD along y-axis
figure(3);
imshow(ymag);

%perform edge detection
figure(4);
imshow(gmag/(4*sqrt(2)));