@echo off

REM Path to the testing program
SET MyProgram="%~1"

REM Run beyond the testing program
if %MyProgram% == "" (
	echo Please specify path to Program
	exit /B 1
)

REM No parameters (must fail)
%MyProgram% && goto err
echo Test 1. No parameter. Passed..

REM Too many parameters (must fail)
%MyProgram% 1 2 3 && goto err
echo Test 2. Too many parameters. Passed..

REM Wrong type of parameter
%MyProgram% "Hello" && goto err
echo Test 3. Wrong type of parameter. Passed..

REM Out of limit 0 to 255
%MyProgram% 256 && goto err
echo Test 4. Out of limit 0 to 255. Passed..

REM Positive case - 6 96
%MyProgram% "6" > "%TEMP%\Output.txt" || goto err
fc Output6.txt "%TEMP%\Output.txt" > nul || goto err
echo Test 5. Positive case - 6 96. Passed..

REM Positive case - min limit number 0 0
%MyProgram% "0" > "%TEMP%\Output.txt" || goto err
fc Output0.txt "%TEMP%\Output.txt" > nul || goto err
echo Test 6. Positive case - min limit number 0 0. Passed..

REM Positive case - max limit number 255 255
%MyProgram% "255" > "%TEMP%\Output.txt" || goto err
fc Output255.txt "%TEMP%\Output.txt" > nul || goto err
echo Test 7. Positive case - max limit number 255 255. Passed..