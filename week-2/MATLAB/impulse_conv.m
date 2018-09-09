%create impulse function 
d=3;
impulse = zeros(2*d+1, 2*d+1);
impulse(d+1,d+1) =1;

%generate random filter
filter = randi(10,5);
disp(filter)

%convolve filter with impulse
result = conv2(filter,impulse);
disp(result);