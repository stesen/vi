#!/usr/bin/octave -q

datafile = argv ();
data = load(datafile{1});

x = data(:, 1);
y = data(:, 2);

p = polyfit(x, y, 1);
y1 = polyval(p,x);
subplot(2, 1, 1), plot(x, y, '-r*', x, y1, '-b'), title("交流电流");
grid;
xlabel('时间');
ylabel('电流');
legend('测量结果','线性拟合');
text(x, y, num2str(y));

dt = 0.1;
x = [0:dt:100];
y1 = y';
[a,b]=xcorr(y1,'unbiased');
subplot(2, 1, 2), plot(b*dt, a), title("自相关");
xlabel('j');
ylabel('r(j)');
grid;
print -dpng /home/stesen/tmp/course/无线电实验/2/webui/image/ai.png;

x = mean(y1);
y = var(y1);
printf("%f\n", x);
printf("%f\n", y);
printf("%f ", y1);
printf("\n");
