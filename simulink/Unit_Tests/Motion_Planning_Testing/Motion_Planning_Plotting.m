Positions = out.Motion_Plan_Out(:, 1:2);
Curvatures = out.Motion_Plan_Out(:, 3);
Maxes = out.Maxes;
Num_Poses = out.Num_Poses;
Num_Maxes = out.Num_Maxes;
Distances = out.Distances;
Displacements = out.Displacements;
Control_Points = out.Control_Points;
Num_Control_Poses = out.Num_Control_Points;
% 
% figure(1), clf
% tcl = tiledlayout(1,2,'TileSpacing','compact');
% 
% nexttile
% 
% plot(Positions(1:(Spline_Num_Samples-1)*(Num_Poses-1)+1,1), Positions(1:(Spline_Num_Samples-1)*(Num_Poses-1)+1,2));
% 
% nexttile
% hold on;
% plot(1:(Spline_Num_Samples-1)*(Num_Poses-1)+1, Curvatures(1:(Spline_Num_Samples-1)*(Num_Poses-1)+1,1));
% 
% scatter(Maxes(1:Num_Maxes, 1), Maxes(1:Num_Maxes, 2));
% 
% figure(2), clf
% tcl1 = tiledlayout(1,2,'TileSpacing','compact');
% 
% nexttile
% 
% plot(Displacements);
% 
% nexttile
% 
% plot(Distances);

figure(3), clf
axis equal
scatter(Distances(Maxes(1:Num_Maxes, 1)), Maxes(1:Num_Maxes, 2));
hold on

for i = 1:Num_Control_Poses
    % disp(sample(i));
    samples_num = 200;
    x_tmp = zeros(samples_num, 1);
    y_tmp = zeros(samples_num, 1);
    
    Max = Maxes(Control_Points(i),:);
    start_Vel = Max(2);
    start_Dist = Distances(Max(1));
    
    
    for i = 1:samples_num
        x_tmp(i) = Distances(end)*((i-1)/(samples_num-1));
        y_tmp(i) = sqrt(start_Vel^2 +2 * Spline_Max_Linear_Acceleration * abs(x_tmp(i)-start_Dist));
    end
    
    plot(x_tmp, y_tmp);
end