Pose = out.Robot_Pose(end, :);
Ref_Poses = [2 2; 4 3; 7 2; 8 0; 10 -2; 12 0; 15 -1; 16 -3; 13 -4; 13 -1];
Data = out.ChainSampling.signals.values;

figure(1), clf
plot(Pose(1), Pose(2), 'o', 'MarkerFaceColor', 'k')
hold on
plot(Spline_Ref_Poses_auto(1:Spline_Num_Poses_auto, 1), Spline_Ref_Poses_auto(1:Spline_Num_Poses_auto, 2),"LineWidth",1);
axis equal
grid on

for i = 1:size(Data, 3)
    plot(Data(:,1,i), Data(:,2,i), '-');
end

figure(2), clf
hold on
for i = 1:size(Data, 3)
    plot((i-1:1/(Spline_Num_Samples-1):i)', Data(:, 3, i), '-');
end