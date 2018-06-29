n=3;
while n>1
    uglovi = fopen('E:\MEHsem\uglovi.txt','r');
    formatSpec = '%f';
    x = fscanf(uglovi, formatSpec, 3)
if  isempty(x)
    pause(0.05);
    fclose(uglovi);
    continue;
end

        %x=rand(1);
        %y=rand(1);
        %z=rand(1);
        %fi=h(mod(x,9)); teta=h(mod(y,9)); psi=h(mod(z,9));
        fi=x(1)*pi/180;
        teta=x(2)*pi/180;
        psi=x(3)*pi/180;
 

         R=[cos(fi)*cos(teta) cos(fi)*sin(teta)*sin(psi)-sin(fi)*cos(psi) cos(fi)*sin(teta)*cos(psi)+sin(fi)*sin(psi);
            sin(fi)*cos(teta) sin(fi)*sin(teta)*sin(psi)+cos(fi)*cos(psi) sin(fi)*sin(teta)*cos(psi)-cos(fi)*sin(psi);
            -sin(teta) cos(teta)*sin(psi) cos(teta)*cos(psi)];
            box on
        f = gca;
        f.ZGrid = 'on';
        f.XGrid = 'on';
        f.YGrid = 'on';


            nx=R(1,1); ny=R(2,1); nz=R(3,1);
            sx=R(1,2); sy=R(2,2); sz=R(3,2);
            ax=R(1,3); ay=R(2,3); az=R(3,3);

            box on
            f = gca;
            f.ZGrid = 'on';
            f.XGrid = 'on';
            f.YGrid = 'on'; 

            a=[0 nx];
            b=[0 ny];
            c=[0 nz];
            drawnow;
            kemo=plot3(a, b, c, 'b');
            pause(0.02);
            hold on;
            axis([-1 1 -1 1 -1 1]);


            box on
            f = gca;
            f.ZGrid = 'on';
            f.XGrid = 'on';
            f.YGrid = 'on';

            a=[0 sx];
            b=[0 sy];
            c=[0 sz];
            drawnow
            edina=plot3(a, b, c,'r');
            pause(0.02);
            hold on;
            axis([-1 1 -1 1 -1 1]);

            a=[0 ax];
            b=[0 ay];
            c=[0 az];
            drawnow
            danijel=plot3(a, b, c,'g');
            pause(0.02);
            hold on;
            axis([-1 1 -1 1 -1 1]);
            pause(1);
            %clf('reset')
            delete(kemo);
            delete(danijel);
            delete(edina);
            fclose(uglovi);
end 