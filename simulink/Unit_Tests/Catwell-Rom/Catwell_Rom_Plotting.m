Pose = out.Robot_Pose(end, :);
Knots = out.Spline_Knots(1:Spline_Max_Num_RefPoses + 2 - (out.Start_Index(end)-1),:,end);
Ref_Poses = [2 2; 4 3; 7 2; 8 0; 10 -2; 12 0; 15 -1; 16 -3; 13 -4; 13 -1];

figure(1), clf
plot(Pose(1), Pose(2), 'o', 'MarkerFaceColor', 'k')
hold on
plot(Knots(:,1), Knots(:,2), 'g^-') 
plot(Ref_Poses(:, 1), Ref_Poses(:, 2), 'ms-')
axis equal
grid on
legend('Robot', 'Spline Knots', 'Ref Poses')