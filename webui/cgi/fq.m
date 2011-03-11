#!/usr/bin/octave -q

datafile = argv ();
data = load(datafile{1});

x = data(:, 1);
y = data(:, 2);

p = polyfit(x, y, 1);
y1 = polyval(p,x);
subplot(2, 1, 1), plot(x, y, '-r*', x, y1, '-b'), title("频率");
grid, xlabel('时间(t)'), ylabel('频率(Hz)'), legend('测量结果', '线性拟合');
text(x, y, num2str(y));

x1 = x';
y1 = y';
y = fft(y1, []);
subplot(2, 1, 2), plot(x, y), title("频率域");
xlabel('Freq(Hz)'), ylabel('|Y(f)|'), grid;
print -dpng /home/stesen/tmp/course/无线电实验/2/webui/image/fq.png;

x = mean(y1);
y = var(y1);
printf("%f\n", x);
printf("%f\n", y);
printf("%f ", y1);
printf("\n");
