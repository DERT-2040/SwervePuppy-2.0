Curvatures = squeeze(out.PreSample(:,:,end));

figure(1), clf
hold on
for i = (1:size(Curvatures,2))
plot((i-1:1/(Spline_Num_Samples-1):i)', Curvatures(:,i), '-');
end

clear i Curvatures