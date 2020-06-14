by Senay Karaali
13.06.2020

___INTRODUCTION_
This is an implementation of an algorithm which follows several steps:
1. creates and saves tables into .mat-files
2. imports created files, analyzes which field of the table contains numbers,
   saves this field into new table and .mat-file

There are 2 options:
For task a) field with numbers is named 'dut'.
For task b) field name with numbers CONTAINS 'dut'.


___FILES___
README.txt - This file.
task_1.m - algorithm for creating and extracting numbers from tables.
outputExample - folder with examples for output of the algorithm

___USAGE___
For testing the algorithm, please follow these steps:
1.) Make sure to select which task is followed: in line 14, please write 'a' or 'b'.
2.) Set path to store data in line 17 (variable 'dataPath').
3.) Press RUN.


___OUTPUT___
As an output, new folders are created in folder, where task_1.m-file is located:

- folder task_a
	--> contains 4 tables in .mat-files
	(table_1.mat, table_2.mat, table_3.mat, table_4.mat)
- subfolder task_a\results
	--> contains 4 tables in .mat-files
	--> each table contains one field with extracted numbers to corresponding table
	--> e.g.:
		 table_2.mat contains 3 fields but only contains numbers in field 2
		 result_2.mat contains 1 field with numbers of field 2 in table_2.mat

- folder task_b --> contains 4 tables in .mat-files
	--> contains 4 tables in .mat-files
	(table_1.mat, table_2.mat, table_3.mat, table_4.mat)
- subfolder task_b\results
	--> contains 4 tables in .mat-files
	--> each table contains one field with extracted numbers to corresponding table
	--> e.g.:
		 table_2.mat contains 3 fields but only contains numbers in field 2
		 result_2.mat contains 1 field with numbers of field 2 in table_2.mat

