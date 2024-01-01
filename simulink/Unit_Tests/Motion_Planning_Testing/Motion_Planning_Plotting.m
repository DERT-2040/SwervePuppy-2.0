Data = out.Motion_Plan_Out;
Maxes = out.Maxes;
Num_Poses = out.Num_Poses;
Num_Maxes = out.Num_Maxes;
Positions = Data(:, 1:2);
Curvatures = Data(:, 3);
figure(1), clf
tcl = tiledlayout(1,2,'TileSpacing','compact');

nexttile
    
plot(Positions(1:Spline_Num_Samples*Num_Poses,1), Positions(1:Spline_Num_Samples*Num_Poses,2));

nexttile
hold on;
plot(1:Spline_Num_Samples*(Num_Poses-1), Curvatures(1:Spline_Num_Samples*(Num_Poses-1),1));

scatter(Maxes(1:Num_Maxes, 1), Maxes(1:Num_Maxes, 2));