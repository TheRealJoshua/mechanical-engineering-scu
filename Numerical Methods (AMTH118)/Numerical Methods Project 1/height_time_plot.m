% Joshua Ramayrat
%
% The purpose of this '.m file' is to plot
% the height of water as a function of time.
%
% Line 15: Using a for loop to enter into a
%          half sphere with radius 25m.
%          declaring Volume as a function of time.



function [height] = height_time_plot

    heightvector = [];                  % 'empty array' for passing 'height values'.
    for t = 1:300
        i = t;                          % variable 'i' to hold time at which loop ends.
        V = (-800000*t*exp(-t/80) 
            - 64000000*exp(-t/80) 
            + 64000000)/1000;
        height = phi_inv(V);            % 'height' is found by inversing Volume, f(t).
        heightvector(t) = height;
        if height > 25                  % 'max height' that hemisphere can fill to.
            break;
        end
    end
    t = [1:i];                          % Declaring an equal length vector of time
                                        % to plot water height.             
    plot(t,heightvector)                % Plot of height as a function of time.            
    title('Height of Water with time'); % Commands to label axes and title of plot. 
    xlabel('Time, t (seconds)');
    ylabel('Height, m (meters)');

end

