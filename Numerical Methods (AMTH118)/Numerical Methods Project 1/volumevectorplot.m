% Joshua Ramayrat
%
% Line 9: An 'empty array' is created for the volume function values.
% Line 11: A 'for loop' is used to fill an 'empty array'
% Line 12: 'VolumeFunction' is found in another m-file.
% 			We subtract 16000 for an "appropriate root"
% 		   	1/4 of the hemisphere is located at the 'root'.

volumevector = [];            

for t = 1:3000                
    volumevector(t) = VolumeFunction(t) - 16000;
end

a = [1:3000];                 
plot(a, volumevector)