img = imread('pep.png');
hsize = 31;

%varying sigma to demonstrate its effect on images
for sigma=1:3:10
    h = fspecial('gaussian', hsize, sigma);
    out = imfilter(img, h);
    
    imshow(out);
    pause;
end