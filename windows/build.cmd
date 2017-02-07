@echo off
REM Get the last build number and increment it
REM 
if exist build-count.txt goto Start
echo Curent build cannot be determined because the build-count.txt file doesn't appear to exist.
pause
echo What is the current build?
set /p Build=""
echo %Build%>build-count.txt
attrib +R +H build-count.txt

:Start
set /p CurrentBuild=<build-count.txt
set /a NewBuild=%CurrentBuild%+1
echo Using build %NewBuild%
attrib -R -H build-count.txt
echo %NewBuild%>build-count.txt
attrib +R +H build-count.txt

echo Using a build number of %NewBuild%

nmake putty.exe - VER="/DSVN_REV=0.63.0.%NewBuild%" /a /f makefiletray.vc

REM Clean up environment
set Build=
set CurrentBuild=
set NewBuild=
