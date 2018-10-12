%% Gradient Direction

%% Load and convert image to double type, range [0, 1] for convenience
img = double(imread('diamond.jpg')) / 255.; 
figure(1);
imshow(img); % assumes [0, 1] range for double images

%% Compute x, y gradients
[gx gy] = imgradientxy(img, 'sobel'); % Note: gx, gy are not normalized

%% Obtain gradient magnitude and direction
[gmag gdir] = imgradient(gx, gy);

figure(2);
imshow(gmag / (4 * sqrt(2))); % mag = sqrt(gx^2 + gy^2), so [0, (4 * sqrt(2))]

%imshow((gdir + 180.0) / 360.0); % angle in degrees [-180, 180]

%output binary image highlighting region with desired gradient-angle
figure(3);
angle_out = gmag >= 1 & gdir >= 30 & gdir <=60;
imshow(angle_out);