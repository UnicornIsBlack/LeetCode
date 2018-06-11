@ECHO OFF
git add *
git commit -m "AC update %DATE:~0,10% %TIME%"
git push origin master
ECHO ON
