%provide input image
sample = double(imread('rick.png'))/255;

figure(1);
imshow(sample);

img_edge = edge(sample,'canny');
figure(2);
imshow(img_edge);
