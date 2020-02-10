theta = polyfit(a,c,1);
maxError = 0;
for x = 1:200
   y =  x*theta(1)+theta(2);
   error = y -c(x);
   if error > maxError
       maxError = error;
   end
end
    
maxError