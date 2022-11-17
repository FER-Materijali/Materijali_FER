trainData=load('train.txt');
testData=load('test.txt');
x = linspace(min(trainData(:,1)),max(trainData(:,1)), 1000);
x2=1:10;
e1=zeros(1,10);
e2=zeros(1,10);
e3=zeros(1,10);
e1r=zeros(1,10);
e2r=zeros(1,10);
e3r=zeros(1,10);
for k=1:100
    trainData=load('train.txt');
    randSample=randsample(length(trainData), 10);
    tData=trainData(randSample,:);
    trainData(randSample,:)=[];
    vData=trainData;
    for i=1:10
        %figure;
        %hold on;
        %scatter(vData(:,1), vData(:,2), 'r');
        %scatter(tData(:,1), tData(:,2), 'b');
        [err1, err1r, err2, err2r, y]=tryDeg(tData, vData, x, i);
        %plot(x,y,'b');
        %legend('Validation data', 'Train Data', 'Regression function');
        %xlabel(strcat('Train error=', num2str(err1,4), '; Validation error=', num2str(err2,4), '; Test error=', num2str(err3,4)))
        %ylabel(strcat('Deg = ', num2str(i)))
        %fprintf('%d -> %.2f / %.2f / %.2f\n', i, err1, err2, err3);
        e1(i)=e1(i) + err1;
        e2(i)=e2(i) + err2;
        e1r(i)=e1r(i) + err1r;
        e2r(i)=e2r(i) + err2r;
    end
end
e1=e1/100.0;
e2=e2/100.0;
e1r=e1r/100.0;
e2r=e2r/100.0;
figure;
subplot(1,2,1);
plot(x2,e1r, 'r');
title('Train error');
xlabel('Degree of polynomial');
ylabel('Square error');
subplot(1,2,2);
plot(x2,e2r, 'b');
title('Validation error');
xlabel('Degree of polynomial');
ylabel('Square error');