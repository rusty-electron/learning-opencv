% Test code:
img = imread('jetplane.jpg');
template = img(128:256, 50:178);
figure(1);
imshow(template);

c = normxcorr2(template, img);
[yRaw xRaw] = find(c == max(c(:)));
y = yRaw - size(template,1) + 1;
x = xRaw - size(template,2) + 1;

disp([y x]);

figure(2);
colormap('gray');imagesc(img);
hold on;
plot(x,y,'r+','markersize',16);

figure(3);
imshow(c);
%surf(c);shading flat;