% this implementation imports tables from .mat-files,
% then extracts numbers from these tables and saves them into new table files

% there are two options:
% for task a, the field containing the numbers to extract is always named 'dut'
% for task b, the field containing the numbers to extract CONTAINS 'dut'

% for chosing task a or b, please make changings in line 14

% by Senay Karaali
% 13.06.2020

%% 01. create and save 4 tables as .mat-files

% choose task ('a' or 'b')
task = 'a';

% define and create storage paths
% dataPath = 'C:\Users\senay\Task 1\dataPath\';
pwd; currentFolder = pwd;
dataPath = strcat(currentFolder, '\dataPath\');
subfolderPath = strcat(dataPath, 'task_', task, '\');
mkdir(subfolderPath);

% define different field names for task 2a) and 2b)
if strcmp(task, 'a')
    fieldNames = {'dut', 'dut', 'dut', 'dut'};
elseif strcmp(task, 'b')
    fieldNames = {'dut_1', 'DUT_2', 'Dut_3', 'DUT_4'};
end

% create tables
r1 = NaN(10,3); tbl_1 = array2table(r1);
r2 = randi([1 10],10,1); tbl_2 = array2table(r2);

c = 1;
for i = [1:3, 1]
    % overwrite one field and its name
    tbl = tbl_1;
    tbl(:,i) = tbl_2; 
    tbl.Properties.VariableNames(i) = fieldNames(c);
    
    % define file name for storage and save
    fileName = strcat('table_', num2str(c), '.mat');
    path = strcat(subfolderPath, fileName);
    save(path, 'tbl');
    c = c + 1;
end


%% 02. import .mat-files and extract DUT numbers

% define and create storage paths
resultPath = strcat(subfolderPath, 'results\');
mkdir(resultPath);
files = dir(fullfile(subfolderPath, '*.mat'));

for i = 1:size(files, 1)
    % import file
    readPath = strcat(subfolderPath, files(i).name);
    tbl = importdata(readPath);
    fieldNames = tbl.Properties.VariableNames;
    
    % find field with DUT numbers depending on which task is executed (2a or 2b)
    if strcmp(task, 'a')
        % assumption: field with DUT numbers is named 'dut'
        fieldNumber = find(strcmp(fieldNames, 'dut'));
    elseif strcmp(task, 'b')
        % assumption: field with DUT numbers CONTAINS 'dut'
        fieldNumber = find(contains(fieldNames, 'dut', 'IgnoreCase', true));
    end
    
    % save extracted DUT numbers in defined file name
    dutNumbers = tbl(:, fieldNumber);
    save(strcat(resultPath, 'result_', num2str(i)), 'dutNumbers');
end

