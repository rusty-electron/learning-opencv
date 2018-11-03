% load image(convert to grayscale if rgb) and apply canny operator to find edge pixels

img = imread('square.png');
edges = edge(img, 'canny');

figure, imshow(img), title('Original Image');
figure, imshow(edges), title('Edge Pixels');

% Apply hough transform to find candidate lines
[accum theta rho] = hough(edges);
figure, imagesc(accum, 'XData', theta, 'YData', rho), title('Hough Accumulator Array');

% Find peaks in the HAA
peaks = houghpeaks(accum, 100); % peaks has location of the maxima in [y,x] pairs
hold on; plot(theta(peaks(:,2)), rho(peaks(:,1)), 'rs'); hold off;

% Find line segments in the image based on the peaks
line_segs = houghlines(edges, theta, rho, peaks)

% Plot line segments
figure, imshow(img), title('Line segments');
hold on;
for k=1:length(line_segs)
    endpoints = [line_segs(k).point1; line_segs(k).point2];
    plot(endpoints(:,1), endpoints(:,2), 'LineWidth', 2, 'Color', 'green');
end
hold off;
