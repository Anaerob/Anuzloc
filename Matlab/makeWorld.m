%% TRANSFORMS PNG TO DAT
clear all;
clc;

world = 'route1';
png = '.png';
dat = '.dat';

input = imread(strcat(world, png));
sizeX = size(input, 2);
sizeY = size(input, 1);

output = zeros(sizeY, sizeX);
for x = 1:sizeX
  for y = 1:sizeY
    if permute(input(y, x, :), [1 3 2]) == [0 0 0]
      output(y, x) = 0;
    elseif permute(input(y, x, :), [1 3 2]) == [255 255 255]
      output(y, x) = 1;
    elseif permute(input(y, x, :), [1 3 2]) == [0 200 0]
      output(y, x) = 2;
    elseif permute(input(y, x, :), [1 3 2]) == [255 0 0]
      output(y, x) = 3;
    elseif permute(input(y, x, :), [1 3 2]) == [150 100 50]
      output(y, x) = 4;
    elseif permute(input(y, x, :), [1 3 2]) == [0 100 200]
      output(y, x) = 5;
    end
  end
end

dlmwrite(strcat(world, dat), [sizeX, sizeY], 'delimiter', ' ');
dlmwrite(strcat(world, dat), ' ', '-append', 'delimiter', ' ');
dlmwrite(strcat(world, dat), output, '-append', 'delimiter', ' ');
