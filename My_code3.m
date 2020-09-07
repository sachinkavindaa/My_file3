close all
clear all
load My_code3.txt
A=My_code3;
t=A(:,1);
x=A(:,2);
y=A(:,3);
z=A(:,4);

figure(1)
plot(t,x,'-r',t,y,'-g',t,z,'-b')
legend('x','y','z')
xlabel('Time')
ylabel('x(t),y(t),z(t)')
title('persistence of residual tumour cells')
hold on

figure(2)
plot(t,x,'-r')
xlabel('Time')
ylabel('x(t)')
title('The graph of x(t) Vs t')

figure(3)
plot(t,y,'-g')
xlabel('Time')
ylabel('y(t)')
title('The graph of y(t) Vs t')

figure(4)
plot(t,z,'-b')
xlabel('Time')
ylabel('z(t)')
title('The graph of z(t) Vs t')

subplot(2,2,1) ; plot(t,x,'-r',t,y,'-g',t,z,'-b')
title('(a)', 'FontSize', 8);
subplot(2,2,2) ; plot(t,x,'-r')
title('(b)', 'FontSize', 8);
subplot(2,2,3) ; plot(t,y,'-g')
title('(c)', 'FontSize', 8);
subplot(2,2,4) ; plot(t,z,'-b')
title('(d)', 'FontSize', 8);
hold on

