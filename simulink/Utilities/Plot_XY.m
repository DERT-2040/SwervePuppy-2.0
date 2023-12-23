time_sim = squeeze(out.tout);
x = squeeze(out.Simulation_Px);
y = squeeze(out.Simulation_Py);
Target_x = squeeze(out.Target_X);
Target_y = squeeze(out.Target_Y);
Odom_x = squeeze(out.Odom_X);
Odom_y = squeeze(out.Odom_Y);
gyro = squeeze(out.Simulation_Gyro);


figure(12), clf
plot(Spline_Ref_Poses_auto(1:Spline_Num_Poses_auto, 1), Spline_Ref_Poses_auto(1:Spline_Num_Poses_auto, 2),"LineWidth",3);
hold on
plot(Target_x,Target_y,'r-')
plot(Odom_x,Odom_y,'g-')
plot(x, y,'k')
grid on
zoom on
axis equal
legend('Design','Target','Odometry','Simulation')
xlabel('X Position')
ylabel('Y Position')

%%
figure(20)
subplot(3,1,1)
plot(time_sim,x)
xlabel('Time (sec)')
ylabel('X Position (m)')
grid on

subplot(3,1,2)
plot(time_sim,y)
grid on
xlabel('Time (sec)')
ylabel('Y Position (m)')

subplot(3,1,3)
plot(time_sim,gyro)
grid on
xlabel('Time (sec)')
ylabel('Gyro Angle (deg)')