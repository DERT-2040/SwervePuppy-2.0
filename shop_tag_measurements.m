
%%
tags_raw = [ % x, y, z
    -100.25     -26.25  20.25
    5.0         136.125 23.0
    129.25      66.5    46.5
    129.25      5.5     33.0
    74.75       -40.5   34.375
    -100.25     48.25   20.75
    -5.75       -41.75  19.5
    -101.875    119.625 18.625];

tags_min_x = min(tags_raw(:,1));
tags_min_y = min(tags_raw(:,2));

tags_offset(:,1) = tags_raw(:,1)-tags_min_x;
tags_offset(:,2) = tags_raw(:,2)-tags_min_y;
tags_offset(:,3) = tags_raw(:,3);

figure(1)
plot3(tags_offset(:,1),tags_offset(:,2),tags_offset(:,3),'o')
%plot(tags_offset(:,1),tags_offset(:,2),'o')
axis square
axis equal
grid on
zlim([0 48])
xlabel('x-axis')
ylabel('y-axis')
zlabel('z-axis')

% convert from inches to meters
tags_offset_meter = tags_offset*0.0254;  