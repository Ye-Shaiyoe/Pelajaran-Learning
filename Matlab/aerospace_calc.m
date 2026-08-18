% ============================================================
%  AEROSPACE_CALC.M
%  Perhitungan Dasar Aerodinamika & Kinerja Pesawat
%  Author  : Akram (Ye-Shaiyoe)
%  Deskripsi:
%    - Gaya Angkat (Lift) & Hambatan (Drag)
%    - Persamaan Breguet (Range & Endurance)
%    - Manuver Melingkar (Turning Performance)
%    - Visualisasi Polar Drag & Lift vs Sudut Serang
% ============================================================

clc; clear; close all;

% -- Kondisi Atmosfer (ISA Sea Level) --
rho   = 1.225;          % Densitas udara [kg/m^3]
g     = 9.81;           % Percepatan gravitasi [m/s^2]
mu    = 1.789e-5;       % Viskositas dinamis udara [Pa.s]

% -- Spesifikasi Pesawat (contoh: mirip Cessna 172) --
W     = 10700;          % Berat pesawat [N] (~1090 kg)
S     = 16.2;           % Luas sayap [m^2]
AR    = 7.32;           % Aspect Ratio sayap
e     = 0.8;            % Oswald efficiency factor
CL0   = 0.2;            % Koefisien Lift saat alpha = 0
CLa   = 0.1;            % Slope CL per derajat [1/deg]
CD0   = 0.027;          % Drag parasit (zero-lift drag)
k     = 1/(pi * AR * e);% Faktor induced drag

% -- Parameter Propulsi --
T_max   = 5000;         % Thrust maksimum [N]
SFC     = 8.5e-6;       % Specific Fuel Consumption [kg/(N.s)]
W_fuel  = 2000;         % Berat bahan bakar awal [N]
eta_p   = 0.85;         % Efisiensi propeller

fprintf('==============================\n');
fprintf(' AEROSPACE CALCULATOR v1.0\n');
fprintf('==============================\n\n');


alpha_deg = -5:0.5:20;          % Sudut serang [derajat]
alpha_rad = deg2rad(alpha_deg);

CL  = CL0 + CLa .* alpha_deg;  % Koefisien Lift linear
CD  = CD0 + k .* CL.^2;        % Drag polar (parabolic)
LoD = CL ./ CD;                 % Lift-to-Drag ratio

fprintf('[1] Lift-to-Drag Maksimum (L/D_max):\n');
[LoDmax, idx] = max(LoD);
fprintf('    L/D_max = %.2f  pada alpha = %.1f deg\n\n', LoDmax, alpha_deg(idx));


V_range = linspace(20, 100, 500);   % Rentang kecepatan [m/s]

% Level flight: L = W => CL = 2W / (rho * V^2 * S)
CL_v  = (2 * W) ./ (rho .* V_range.^2 .* S);
CD_v  = CD0 + k .* CL_v.^2;

% Gaya Angkat dan Hambatan
L_v   = 0.5 .* rho .* V_range.^2 .* S .* CL_v;
D_v   = 0.5 .* rho .* V_range.^2 .* S .* CD_v;

% Thrust required = Drag (level flight)
T_req = D_v;

% Kecepatan minimum (Stall)
CLmax = 1.6;
V_stall = sqrt((2 * W) / (rho * S * CLmax));
fprintf('[2] Kecepatan Stall:\n');
fprintf('    V_stall = %.2f m/s (%.2f km/h)\n\n', V_stall, V_stall*3.6);

% Kecepatan untuk L/D max (best range speed)
V_LDmax = sqrt((2 * W) / (rho * S) * sqrt(k / CD0));
fprintf('[3] Kecepatan Best Range (L/D_max):\n');
fprintf('    V_LDmax = %.2f m/s (%.2f km/h)\n\n', V_LDmax, V_LDmax*3.6);

% Kecepatan minimum Thrust (Maximum Endurance speed)
V_Tmin = sqrt((2 * W) / (rho * S) * sqrt(k / (3 * CD0)));
fprintf('[4] Kecepatan Best Endurance (T_min):\n');
fprintf('    V_Tmin  = %.2f m/s (%.2f km/h)\n\n', V_Tmin, V_Tmin*3.6);


% Range maksimum (Propeller aircraft - Breguet Range Equation)
%   R = (eta_p / (g * SFC)) * (CL/CD)_max * ln(W0/W1)
W0    = W + W_fuel;         % Berat awal (termasuk bahan bakar) [N]
W1    = W;                  % Berat akhir (bahan bakar habis) [N]

LoDmax_val = 0.5 / sqrt(CD0 * k);  % L/D max teoritis

R_breguet = (eta_p / (g * SFC)) * LoDmax_val * log(W0 / W1);

fprintf('[5] Persamaan Breguet:\n');
fprintf('    Range Maksimum (R) = %.2f km\n', R_breguet / 1000);

% Endurance maksimum
%   E = (eta_p / (g * SFC)) * (CL^(3/2)/CD)_max * (1/sqrt(rho*S/2)) * (1/sqrt(W1) - 0)
% Pendekatan sederhana:
CL32CDmax = (3/4) * (3 / (CD0 * (3*k)^3))^(1/4);  % (CL^1.5/CD)_max
E_breguet = (eta_p / (g * SFC)) * CL32CDmax * ...
            sqrt(2 * rho * S) * (1/sqrt(W1) - 1/sqrt(W0));
fprintf('    Endurance Maksimum (E) = %.2f jam\n\n', E_breguet / 3600);

% Bank angle & turn radius
phi_deg = 10:5:80;
phi_rad = deg2rad(phi_deg);
n_load  = 1 ./ cos(phi_rad);    % Load factor

% Kecepatan untuk manuver (asumsi V = V_LDmax)
V_turn  = V_LDmax;
R_turn  = (V_turn^2) ./ (g .* tan(phi_rad));   % Radius belok [m]
omega   = V_turn ./ R_turn;                     % Turn rate [rad/s]

fprintf('[6] Turning Performance (V = %.1f m/s):\n', V_turn);
fprintf('    %-12s %-14s %-14s %-12s\n', 'Bank (deg)', 'Load Factor', 'Radius (m)', 'Rate (deg/s)');
fprintf('    %s\n', repmat('-', 1, 54));
for i = 1:5:length(phi_deg)
    fprintf('    %-12.0f %-14.3f %-14.2f %-12.2f\n', ...
        phi_deg(i), n_load(i), R_turn(i), rad2deg(omega(i)));
end
fprintf('\n');

figure('Name', 'Aerospace Performance Dashboard', ...
       'NumberTitle', 'off', 'Color', [0.12 0.12 0.15], ...
       'Position', [50, 50, 1200, 800]);

% -- Plot 1: Polar Drag (CL vs CD) --
subplot(2,3,1);
plot(CD, CL, 'c-', 'LineWidth', 2); hold on;
% Titik L/D max
CD_LDmax = CD0 + k * CL(idx)^2;
plot(CD_LDmax, CL(idx), 'r*', 'MarkerSize', 10);
grid on; grid minor;
xlabel('C_D'); ylabel('C_L');
title('Drag Polar', 'Color', 'w');
legend({'Drag Polar', sprintf('L/D_{max}=%.1f', LoDmax)}, 'TextColor', 'w');
set(gca, 'Color', [0.18 0.18 0.22], 'XColor', 'w', 'YColor', 'w', ...
    'GridColor', [0.4 0.4 0.4]);

% -- Plot 2: CL & CD vs Alpha --
subplot(2,3,2);
yyaxis left
plot(alpha_deg, CL, 'b-', 'LineWidth', 2);
ylabel('C_L', 'Color', 'b');
yyaxis right
plot(alpha_deg, CD, 'r--', 'LineWidth', 2);
ylabel('C_D', 'Color', 'r');
xlabel('Alpha (deg)'); title('CL & CD vs Sudut Serang', 'Color', 'w');
grid on; grid minor;
set(gca, 'Color', [0.18 0.18 0.22], 'XColor', 'w', 'YColor', 'w', ...
    'GridColor', [0.4 0.4 0.4]);

% -- Plot 3: L/D vs Alpha --
subplot(2,3,3);
plot(alpha_deg, LoD, 'm-', 'LineWidth', 2); hold on;
plot(alpha_deg(idx), LoDmax, 'y*', 'MarkerSize', 12);
grid on; grid minor;
xlabel('Alpha (deg)'); ylabel('L/D');
title('Lift-to-Drag Ratio', 'Color', 'w');
legend({'L/D', sprintf('Max=%.1f @ %.1f°', LoDmax, alpha_deg(idx))}, 'TextColor', 'w');
set(gca, 'Color', [0.18 0.18 0.22], 'XColor', 'w', 'YColor', 'w', ...
    'GridColor', [0.4 0.4 0.4]);

% -- Plot 4: Thrust Required vs Velocity --
subplot(2,3,4);
plot(V_range * 3.6, T_req / 1000, 'g-', 'LineWidth', 2); hold on;
xline(V_stall * 3.6, 'r--', 'V_{stall}', 'Color', 'r', 'LabelColor', 'r');
xline(V_LDmax * 3.6, 'y--', 'V_{R}', 'Color', 'y', 'LabelColor', 'y');
grid on; grid minor;
xlabel('Kecepatan (km/h)'); ylabel('Thrust Required (kN)');
title('Thrust Required vs Kecepatan', 'Color', 'w');
set(gca, 'Color', [0.18 0.18 0.22], 'XColor', 'w', 'YColor', 'w', ...
    'GridColor', [0.4 0.4 0.4]);

% -- Plot 5: Turn Radius vs Bank Angle --
subplot(2,3,5);
plot(phi_deg, R_turn, 'orange', 'LineWidth', 2);
grid on; grid minor;
xlabel('Bank Angle (deg)'); ylabel('Turn Radius (m)');
title('Radius Belok vs Bank Angle', 'Color', 'w');
set(gca, 'Color', [0.18 0.18 0.22], 'XColor', 'w', 'YColor', 'w', ...
    'GridColor', [0.4 0.4 0.4]);

% -- Plot 6: Load Factor vs Bank Angle --
subplot(2,3,6);
plot(phi_deg, n_load, 'r-', 'LineWidth', 2); hold on;
yline(2.5, 'w--', 'Limit Normal Cat.', 'LabelColor', 'w');
grid on; grid minor;
xlabel('Bank Angle (deg)'); ylabel('Load Factor (n)');
title('Load Factor vs Bank Angle', 'Color', 'w');
set(gca, 'Color', [0.18 0.18 0.22], 'XColor', 'w', 'YColor', 'w', ...
    'GridColor', [0.4 0.4 0.4]);

% Global title
sgtitle('Aerospace Performance Dashboard - Cessna 172 Approximation', ...
        'Color', 'w', 'FontSize', 13, 'FontWeight', 'bold');

fprintf('✓ Semua perhitungan selesai! Grafik telah ditampilkan.\n');