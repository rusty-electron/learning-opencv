% Edge Detection Summary

% Load Image
lake = imread('lake.jpg');
figure, imshow(lake), title('Original Image, monochrome');

% Prepare Gaussian filter
h = fspecial('gaussian', [11 11], 4);
figure, surf(h);

lakeSmooth = imfilter(lake, h);

% Method 1: Shift left and right, display the difference
lakeL = lakeSmooth;
lakeL(:, (1:end-1)) = lakeL(:,(2:end)); % last and second last column shall be identical

lakeR = lakeSmooth;
lakeR(:, (2:end)) = lakeR(:,(1:end-1)); % first and second column shall be identical

lakeDiff = double(lakeL) - double(lakeR);
figure, imshow(lakeDiff, []), title('Difference between left-right shifted Images');

% Method 2: Canny Edge Detector
cannyLake = edge(lake, 'canny');
figure, imshow(cannyLake), title('Canny Operator on Original Image');

cannyLake = edge(lakeSmooth, 'canny');
figure, imshow(cannyLake), title('Canny Operator on Smoothed Image');

% Method 3: Laplacian Operator
lapLake = edge(lake, 'log');
figure, imshow(cannyLake), title('Laplacian Operator on Original Image');