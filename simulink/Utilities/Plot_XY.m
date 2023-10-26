x = squeeze(out.Simulation_Px);
y = squeeze(out.Simulation_Py);
gyro = squeeze(out.Simulation_Gyro);

figure(12)
plot(x, y)
grid on
zoom on
axis equal
xlabel('X Position')
ylabel('Y Position')

%%
figure(20)
subplot(3,1,1)
plot(out.tout,x)
xlabel('Time (sec)')
ylabel('X Position (m)')
grid on

subplot(3,1,2)
plot(out.tout,y)
grid on
xlabel('Time (sec)')
ylabel('Y Position (m)')

subplot(3,1,3)
plot(out.tout,gyro)
grid on
xlabel('Time (sec)')
ylabel('Gyro Angle (deg)')