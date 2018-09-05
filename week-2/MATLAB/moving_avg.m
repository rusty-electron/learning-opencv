x = (0:0.2:3*pi);
y = sin(x);

noise = randn(size(y));
noisy = noise/2.5 + y;

figure(1);
plot(x,noisy);

%MATLAB Keyboard shortcut Ctrl + R -- comment & Ctrl + T -- uncomment

hold on;

 filtered = movmean(noisy,5);
 plot(x,filtered);

w = 5;
wf = floor(w/2);
filter = [1 4 6 4 1];
filterTotal = 16;
taskmat = noisy;

result = zeros(size(taskmat));

for k = wf+1:size(taskmat,2)-wf
    result(k) = sum(taskmat(k-wf:k+wf).*filter)/filterTotal;
end 

plot(x,result);

legend('Input Data', 'Filtered Data','My Algo - Weighted');
hold off;