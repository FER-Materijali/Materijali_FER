setlocal EnableDelayedExpansion
@echo off
if exist config.conf (
	(
	set /p input=
	set /p output=
	set /p name=
	set /p version=
	)<config.conf
) else (
set /p input=What is input format?:
set /p output=What is output format?:
set /p name=What is name of program?:
set /p version=What is version of python ^(2 or 3^)?:
(
echo !input!
echo !output!
echo !name!
echo !version!
) >> config.conf
)
FOR /f "delims=" %%i in ('DIR /a:d /b "test"') DO (
type test\%%i\test.%input%|Py -%version% %name%.py > output.txt
fc output.txt test\%%i\test.%output%
pause
cls
)
del output.txt
exit