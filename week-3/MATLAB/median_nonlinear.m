%verification that median is a non-linear function unlike mean
clc;
A = [2 4 6];
B = [0 -4 4];
C = A+B;

meanA = mean(A);
meanB = mean(B);
meanC = mean(C);

fprintf("For mean: f(x) : %f and f(y) : %f so f(x+y) : %f\n",meanA,meanB,meanC);

medA = median(A);
medB = median(B);
medC = median(C);

fprintf("For median: g(x) : %f and g(y) : %f but g(x+y) : %f\n",medA,medB,medC);