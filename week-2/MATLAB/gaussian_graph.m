%plot gaussian noise
noise = randn([1 50]);
[n,x] = hist(noise, [-3 -2 -1 0 1 2 3]);
disp([x;n]);
plot(x,n);