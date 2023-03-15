@echo off

REM Path to the testing program
SET MyProgram="%~1"

REM Run beyond the testing program
if %MyProgram% == "" (
	echo Please specify path to Program
	exit /B 1
)

REM Copy empty file
%MyProgram% Empty.txt "%TEMP%\output.txt" || goto err
fc Empty.txt "%TEMP%\output.txt" > nul || goto err
echo Test 1 passed 

REM Copy empty file
%MyProgram% NonEmpty.txt "%TEMP%\output.txt" || goto err
fc NonEmpty.txt "%TEMP%\output.txt" > nul || goto err
echo Test 2 passed 

REM Copy missing file (must fail)
%MyProgram% Missing.txt "%TEMP%\output.txt" && goto err
echo Test 3 passed 

REM Output file not specified (must fail)
%MyProgram% "%TEMP%\output.txt" && goto err
echo Test 4 passed 

REM Program completed successfully
echo All tests passed successfully
exit /B 0

REM Program completed with an error
:err
echo One of tests failed
exit /B 1