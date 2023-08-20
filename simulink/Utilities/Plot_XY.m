x = squeeze(out.Simulation_Px);
y = squeeze(out.Simulation_Py);
figure(2)
plot(x, y)
grid on
zoom on
axis equal
xlabel('X Position')
ylabel('Y Position')