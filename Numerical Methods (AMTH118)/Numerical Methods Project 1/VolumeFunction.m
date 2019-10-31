% Joshua Ramayrat
%
% Line 6: The 'volume of water' as a 'function of time'.
% Line 7: The derived expression for 'volume'.

function [tvalue] = VolumeFunction(t)		 

	V = (-800000*t*exp(-t/80) 				
		 - 64000000*exp(-t/80) 
		 + 64000000)/1000;
	tvalue = V;

end

