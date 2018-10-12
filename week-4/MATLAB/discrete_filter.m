img = double(imread('lake.jpg'))/255;

figure(1);
imshow(img);

filter = [0 0 0;-.5 0 .5;0 0 0];

%for sharp edge condition of 1 and 0 the extreme values of gradient matrix
%will be -0.5 and 0.5

%calculating horizontal image gradient matrix
img_hres = imfilter(img, filter);
figure(2);
imshow(img_hres, [-.5 .5]);

%calculating vertical image gradient matrix
img_vres = imfilter(img, filter');
figure(3);
imshow(img_vres, [-.5 .5]);

%using the previous two image gradient matrices to perform edge detection
img_edge = sqrt(img_hres.*img_hres + img_vres.*img_vres);
figure(4);
imshow(img_edge, [0 sqrt(.5)]);







