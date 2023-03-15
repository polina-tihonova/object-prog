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

REM One parameter (must fail)
%MyProgram% NonEmpty.txt && goto err
echo Test 2. One parameters. Passed..

REM Too many parameters (must fail)
%MyProgram% NonEmpty.txt "A" "%TEMP%\Output.txt" > "%TEMP%\Output.txt" && goto err
echo Test 3. Too many parameters. Passed..

REM File do not exists
%MyProgram% NotExists.txt "contains" && goto err
echo Test 4. File do not exists. Passed..

REM Empty file
%MyProgram% Empty.txt "contains" > "%TEMP%\Output.txt" && goto err
echo Test 5. Empty file. Passed..

REM Non empty file
%MyProgram% NonEmpty.txt "a" > "%TEMP%\Output.txt" || goto err
fc Output.txt "%TEMP%\Output.txt" > nul || goto err
echo Test 6. Non empty fil lowercase. Passed..

REM Non empty file
%MyProgram% NonEmpty.txt "A" > "%TEMP%\Output.txt" || goto err
fc Output.txt "%TEMP%\Output.txt" > nul || goto err
echo Test 7. Non empty file uppercase. Passed..

REM Non empty file
%MyProgram% NonEmpty.txt "A" > "%TEMP%\Output.txt" || goto err
fc Output.txt "%TEMP%\Output.txt" > nul || goto err
echo Test 7. Non empty file uppercase. Passed..

REM No substring in file
%MyProgram% NonEmpty.txt "wow" > "%TEMP%\Output.txt" && goto err
echo Test 8. No substring in file. Passed..