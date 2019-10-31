% Joshua Ramayrat
%
% The purpose of this '.m file' is to 
% evaluate height at a given volume.


function [zero] = phi_inv(v)

	format long                             %display higher degrees of accuracy

	h = 12.5;                               %arbitrary start point between 0 & 50
	v0 = 1;                                 %to initially pass the while loop
	i = 0;                                  %used to show number of iterates

	while abs(v0) > 10^(-12) && i <1000     %loop determines proximity of abs(v0) relative to the root.
                                        	%i<1000 cuts off the code from
                                         	%running for too long
	    v0 = pi*h^2*(25-(h/3))-v;           %v0 is the original phi equation
	    vprime = pi*50*h - (h^2);           %vprime is the derivative of phi.
	    h0 = h - (v0/vprime);               %formula for Newton's method 
	    h = h0;                             %setting the new h-value for the next Newton iterate.
	    i = i+1;                            %adding 1 to the iteration count.
	end

	disp('Iterate count: ');                  
	disp(i)                                 %display iterate count
	disp('Height: ');
	disp(h)                                 %display height of water
	zero = h;
end

