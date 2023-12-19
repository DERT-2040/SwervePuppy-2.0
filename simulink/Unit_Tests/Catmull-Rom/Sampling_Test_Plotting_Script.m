Pose = out.simout;


figure(1), clf
hold on

plot(Pose(:, 1), Pose(:,2), 'b');
plot(0:(1/(size(Pose,1)-1)):1, Pose(:,3), 'm');
plot([1 3 0 0],[1 4 4 0], 'go-');

axis equal
grid on
legend('Samples', 'Curvature')