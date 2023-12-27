classdef Test_Functions<handle
    properties
        Points = [];
    end
    methods
        function main(App)
            App.AddPoint(2, 3);
        end
        function App = Plot_Catmull_Rom_Spline_Segment(App, P1, P2, P3, P4)
            Sample_Num = 50;
            T = 0.5;
            figure(1);
            hold on
            for i = 1:Sample_Num
                u  = (i-1) / (Sample_Num-1);
                a = u^3 - 2*u^2 + u;
                b = u^2 - u^3;
                c = 3*u^2 - 2*u^3;
                x(i) = T*( a*( P3(1) - P1(1) )+b*( P2(1) - P4(1) ) ) + P2(1) + c*( P3(1) - P2(1) );
                y(i) = T*( a*( P3(2)-P1(2) )+b*( P2(2)-P4(2) ) ) + P2(2) + c*( P3(2) - P2(2) );
            end
            plot(x, y, 'k');
            clear Sample_Num T i u a b c x y;
        end
        function App = Plot_Full_Spline(App)
            [App, First_Control] = App.Make_Control_Point(App.Points(1,:), App.Points(2,:));
            [App, Last_Control] = App.Make_Control_Point(App.Points(end,:), App.Points(end-1,:));
            Knots = [First_Control;App.Points;Last_Control];
            figure(1), clf
            scatter(App.Points(:,1), App.Points(:,2));
            for i = 1:(size(Knots,1)-3)
                App.Plot_Catmull_Rom_Spline_Segment(Knots(i,:), Knots(i+1,:), Knots(i+2,:), Knots(i+3,:));
            end
        end
        function [App, C_Point] = Make_Control_Point(App, Last_Point, Point_Before_Last)
            C_Point = 2*Last_Point - Point_Before_Last;
        end
        function App = AddPoint(App, x, y)
            App.Points = [App.Points; x, y];
        end
    end
end