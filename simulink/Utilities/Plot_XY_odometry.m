x = squeeze(out.Simulation_Px);
y = squeeze(out.Simulation_Py);
time_plant = out.tout;
x_est = squeeze(out.Simulation_Px_estimate.signals.values);
y_est = squeeze(out.Simulation_Py_estimate.signals.values);
time_est = out.Simulation_Px_estimate.time;
gyro = squeeze(out.Simulation_Gyro);

figure(13), clf
plot(x, y)
hold on
plot(x_est, y_est,'--')
grid on
zoom on
axis equal
xlabel('X Position')
ylabel('Y Position')

%%
figure(21), clf
subplot(3,1,1)
plot(time_plant,x)
hold on
plot(time_est,x_est,'--')
xlabel('Time (sec)')
ylabel('X Position (m)')
grid on

subplot(3,1,2)
plot(time_plant,y)
hold on
plot(time_est,y_est,'--')
grid on
xlabel('Time (sec)')
ylabel('Y Position (m)')

subplot(3,1,3)
plot(time_plant,gyro)
grid on
xlabel('Time (sec)')
ylabel('Gyro Angle (deg)')