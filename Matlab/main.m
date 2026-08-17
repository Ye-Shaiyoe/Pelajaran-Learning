% Contoh membuat grafik permukaan 3D di MATLAB
[X, Y] = meshgrid(-8 : 0.5 : 8);
R = sqrt(X.^2 + Y.^2) + eps;
Z = sin(R) ./ R;

figure;
surf(X, Y, Z, 'EdgeColor', 'none');
colormap(jet);
colorbar;
title('Grafik Permukaan Sinc 3D');
xlabel('Sumbu X');
ylabel('Sumbu Y');
zlabel('Sumbu Z');
