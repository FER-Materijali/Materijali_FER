trainData=load('train.txt');
testData=load('test.txt');
x = linspace(min(trainData(:,1)),max(trainData(:,1)), 1000);
x2=1:10;
randSample=randsample(length(trainData), 10);
tData=trainData(randSample,:);
trainData(randSample,:)=[];
vData=trainData;
figure;
for i=1:10
    subplot(2,5,i)
    hold on;
    scatter(vData(:,1), vData(:,2), 'r');
    scatter(tData(:,1), tData(:,2), 'b');
    [err1, err2, err3, y]=tryDeg(tData, vData, testData, x, i);
    plot(x,y,'b');
    %legend('Validation data', 'Train Data', 'Regression function');
    %xlabel(strcat('Train error=', num2str(err1,4), '; Validation error=', num2str(err2,4), '; Test error=', num2str(err3,4)))
    ylabel(strcat('Deg = ', num2str(i)))
    fprintf('%d -> %.2f / %.2f / %.2f\n', i, err1, err2, err3);
end
label('Validation data', 'Train data', 'Regression function')