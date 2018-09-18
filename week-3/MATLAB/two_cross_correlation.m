%load image
img = imread('jetplane.jpg');
figure(1);
imshow(img);

%create a filter from loaded image
filter = img(128:256,1:128);
figure(2);
imshowpair(img,filter,'montage');

%perform cross-correlation and display the 3d plot for visual verification
c=normxcorr2(filter,img);
figure(3);surf(c);shading flat;